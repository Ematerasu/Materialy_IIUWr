#lang typed/racket

;;z.1.
(: prefixes (All (a) (-> (Listof a) (Listof (Listof a)))))
(define (prefixes xs)
  (: iter (All (a) (-> (Listof a) (Listof a) (Listof (Listof a)))))
  (define (iter xs acc)
    (if (null? xs)
        (cons acc null)
        (cons acc
              (iter (cdr xs) (append acc (list (car xs)))))))  
  (iter xs (list)))


#|(: prefixes-rec (All (a) (-> (Listof a) (Listof (Listof a)))))
(define (prefixes-rec xs)
  (if (null? xs)
      null
      (cons (list (car xs)) 
            (map (lambda (ys) (cons (car xs) ys)) 
                 (prefixes-rec (cdr xs)))))|# ;system typow sie wysypie

;;zad2
(struct vector2 ([x : Real] [y : Real]) #:transparent)
(struct vector3 ([x : Real] [y : Real] [z : Real]) #:transparent)

(define-type Vector (U vector2 vector3))

(define-predicate vector? Vector)

(: vector-x (-> Vector Real))
(define (vector-x v)
  (match v
    [(vector2 x y) x]
    [(vector3 x y z) x]))

(: vector-y (-> Vector Real))
(define (vector-y v)
  (match v
    [(vector2 x y) y]
    [(vector3 x y z) y]))

(: vector-z (-> Vector Real))
(define (vector-z v)
  (match v
    [(vector3 x y z) z]))

;z wykladu wziete procedury do obliczenia dlugosc wektora

(: dist (-> Real Real Real))
(define (dist x y)
  (abs (- x y)))

(: average (-> Real Real Real))
(define (average x y)
  (/ (+ x y) 2))

(: square (-> Real Real))
(define (square x)
  (* x x))

(: sqrt (-> Real Real))
(define (sqrt x)
  ;; lokalne definicje
  ;; poprawienie przybliżenia pierwiastka z x
  (: improve (-> Real Real))
  (define (improve approx)
    (average (/ x approx) approx))
  ;; nazwy predykatów zwyczajowo kończymy znakiem zapytania
  (: good-enough? (-> Real Boolean))
  (define (good-enough? approx)
    (< (dist x (square approx)) 0.0001))
  ;; główna procedura znajdująca rozwiązanie
  (: iter (-> Real Real))
  (define (iter approx)
    (cond
      [(good-enough? approx) approx]
      [else                  (iter (improve approx))]))
  
  (iter 1.0))

;;

;;dopasowanie wzorca
(: vector-length-match (-> Vector Real))
(define (vector-length-match v)
  (match v
    [(vector2 x y) (sqrt (+ (square x) (square y)))]
    [(vector3 x y z) (sqrt (+ (square x) (square y) (square z)))]
    [_ 0]))

;;warunkowo
(: vector-length-cond (-> Vector Real))
(define (vector-length-cond v)
  (cond 
    [(vector2? v) (sqrt (+ (square (vector-x v)) (square (vector-y v))))]
    [(vector3? v) (sqrt (+ (square (vector-x v)) (square (vector-y v)) (square (vector-z v))))]
    [else 0]))


;zad3
(: fold-right (All (a) (-> (-> a a a) a (Listof a) a)))
(define (fold-right op acc lis) 
  (if (null? lis) 
      acc 
      (op (car lis) (fold-right op acc (cdr lis)))))

;zad4

(define-type (RoseTree a) (U leaf (node a)))

(struct leaf () #:transparent)
(struct [a] node ([val : a] [child : (Listof (RoseTree a))]))

(: preorder (All (a) (-> (RoseTree a) (Listof a))))
(define (preorder t)
    (match t
        [(leaf) 
         null]
        [(node val children) 
         (cons val 
               ((inst append-map a (RoseTree a)) preorder children))]))

(define tree
  (node 'a
        (list (node 'b (list (leaf) (leaf)))
              (node 'c (list (leaf) (leaf))))))


;;zad5
(struct const    ([val : Value])      #:transparent)
(struct binop    ([op : Symbol] [l : Expr] [r : Expr])   #:transparent)
(struct var-expr ([id : Symbol])       #:transparent)
(struct let-expr ([id : Symbol] [e1 : Expr] [e2 : Expr]) #:transparent)

(define-type Expr (U const binop var-expr let-expr))
(define-type Value (U Number Boolean))
(define-predicate expr? Expr)

(: parse (-> Any Expr))
(define (parse q)
  (match q
    [_ #:when (number? q)
       (const q)]
    [_ #:when (symbol? q)
       (var-expr q)]
    [`(,op ,e1 ,e2) #:when (symbol? op)
                    (binop op
                           (parse e1)
                           (parse e2))]
    [`(let (,x ,e1) ,e2) #:when (symbol? x)
     (let-expr x 
               (parse e1)
               (parse e2))]))

(: subst (-> Expr Symbol Expr Expr))
(define (subst e1 x e2)
  (match e2
    [(var-expr y) (if (eq? x y) e1 (var-expr y))]
    [(const n) (const n)]
    [(binop op l r)
     (binop op (subst e1 x l) (subst e1 x r))]
    [(let-expr y e3 e4)
     (let-expr y (subst e1 x e3) 
                 (if (eq? x y) e4 (subst e1 x e4)))]))

(: op->proc (-> Symbol (-> Value Value Value)))
(define (op->proc op)
  (let ([f (match op ['+ +] ['- -] ['* *] ['/ /])])
    (lambda (x y) 
      (if (and (number? x) (number? y))
          (f x y)
          (error "Type mismatch")))))

(: eval (-> Expr Value))
(define (eval e)
  (match e
    [(const n) n]
    [(binop op l r) ((op->proc op) (eval l) (eval r))]
    [(let-expr x e1 e2)
     (eval (subst (const (eval e1)) x e2))]))