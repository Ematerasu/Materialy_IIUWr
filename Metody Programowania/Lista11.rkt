#lang racket

(struct const    (val)      #:transparent)
(struct binop    (op l r)   #:transparent)
(struct var-expr (id)       #:transparent)
(struct let-expr (id e1 e2) #:transparent)


(define expr/c
  (flat-rec-contract expr
                         (struct/c const number?)
                         (struct/c binop symbol? expr expr)
                         (struct/c var-expr symbol?)
                         (struct/c let-expr expr expr expr)))
                     

(define (expr? e)
  (match e
    [(const n) (number? n)]
    [(binop op l r) (and (symbol? op) (expr? l) (expr? r))]
    [(var-expr x) (symbol? x)]
    [(let-expr x e1 e2) (and (symbol? x) (expr? e1) (expr? e2))]
    [_ false]))

(define (parse q)
  (cond
    [(number? q) (const q)]
    [(symbol? q) (var-expr q)]
    [(and (list? q) (eq? (length q) 3) (eq? (first q) 'let))
     (let-expr (first (second q))
               (parse (second (second q)))
               (parse (third q)))]
    [(and (list? q) (eq? (length q) 3) (symbol? (first q)))
     (binop (first q)
            (parse (second q))
            (parse (third q)))]))

(define (test-parse) (parse '(let [x (+ 2 2)] (+ x 1))))

(define/contract (suffixes xs)
  (parametric->/c [a] (-> (listof a) (listof (listof a))))
  (if (null? xs)
      null
      (cons xs (suffixes (cdr xs)))))

(define/contract (sublists xs)
  (parametric->/c [a] (-> (listof a) (listof (listof a))))
   (if (null? xs)
       (list null)
       (append-map
         (lambda (ys) (list (cons (car xs) ys) ys))
         (sublists (cdr xs)))))

(define foldl-map/c  	
   (parametric->/c [x y] (-> (-> x y (cons/c x y))
                           y
                           (listof x)
                           (cons/c (listof x) y))))

(define (foldl-map f a xs)
  foldl-map/c
    (define (it a xs ys)
        (if (null? xs)
            (cons (reverse ys) a)
            (let [(p (f (car xs) a))]
                (it (cdr p)
                (cdr xs)
                (cons (car p) ys)))))
(it a xs null))

(foldl-map (lambda (x a) (cons a (+ a x))) 0 '(1 2 3))
(foldl-map (lambda (x a) (cons (number->string x) (+ a x))) 0 '(1 2 3))
; ----------------------- ;
; Podstawienie za zmienna ;
; ----------------------- ;

(define (subst e1 x e2)
  (-> expr/c symbol? expr/c expr/c)
  (match e2
    [(var-expr y) (if (eq? x y) e1 (var-expr y))]
    [(const n) (const n)]
    [(binop op l r)
     (binop op (subst e1 x l) (subst e1 x r))]
    [(let-expr y e3 e4)
     (let-expr y (subst e1 x e3) 
                 (if (eq? x y) e4 (subst e1 x e4)))]))

(define (test-subst)
  (subst (parse '(+ 2 2))
         'x
         (parse '(let [y (+ x 1)] (let [x (+ x y)] (+ y x))))))

; --------- ;
; Ewaluacja ;
; --------- ;

(define (value? v)
  (number? v))

(define (op->proc op)
  (match op ['+ +] ['- -] ['* *] ['/ /]))

(define/contract (eval e)
  (-> expr/c number?)
  (match e
    [(const n) n]
    [(binop op l r) ((op->proc op) (eval l) (eval r))]
    [(let-expr x e1 e2)
     (eval (subst (const (eval e1)) x e2))]))

(define (test-eval) (eval (test-subst)))