#lang racket

(struct const (val)    #:transparent)
(struct binop (op l r) #:transparent)
(struct pow(e1 e2) #:transparent)
(struct sum (e1 e2 i f) #:transparent)
(struct integral (e1 e2 x f) #:transparent)
(struct minimum (f xs) #:transparent)

(struct var-expr (id)       #:transparent)
(struct let-expr (id e1 e2) #:transparent)

; 2 + 2 * 2
(define 2+2*2 (binop '+ (const 2)
                        (binop '* (const 2)
                                  (const 2))))


; Co to są wartości?
(define (value? v)
  (number? v))
        

(define (op->proc op)
  (match op ['+ +] ['- -] ['* *] ['/ /]))

(define (eval e)
  (match e
    [(const n) n]
    [(binop op l r) ((op->proc op) (eval l) (eval r))]))

; ------------------------- ;
; Trochę składni konkretnej ;
; ------------------------- ;

(define (test) (eval (parse '(+ (* 2 3) (* 4 5)))))

;zad1
(struct infinity() #:transparent)


(define (expr? e)
  (match e
    [(const n) (number? n)]
    [(binop op l r) (and (symbol? op) (expr? l) (expr? r))]
    [(var-expr x) (symbol? x)]
    [(let-expr x e1 e2) (and (symbol? x) (expr? e1) (expr? e2))]
    [(pow e1 e2) (and (expr? e1) (expr? e2))]
    [(sum e1 e2 i f) (and (expr? e1) (expr? e2) (symbol? i) (expr? f))]
    [(integral e1 e2 x f) (and (expr? e1) (expr? e2) (symbol? x) (expr? f))]
    [(minimum f i) (and (expr? f) (symbol? i))]
    [(infinity) true]
    [_ false]))

(define (subst e1 x e2)
  (match e2
    [(var-expr y) (if (eq? x y) e1 (var-expr y))]
    [(const n) (const n)]
    [(binop op l r)
     (binop op (subst e1 x l) (subst e1 x r))]
    [(let-expr y e3 e4)
     (let-expr y (subst e1 x e3) 
                 (if (eq? x y) e4 (subst e1 x e4)))]))

;zad2

;'(^ a b)
;'(sum begin end i f(i))
;'(integral begin end x f(x))
;'(min i f)
;'inf

(define (parse q)
  (cond [(number? q) (const q)]
        [(symbol? q) (var-expr q)]
        [(eq? 'inf q) (infinity)]
        [(and (list? q) (eq? (length q) 3) (eq? (first q) 'let))
         (let-expr (first (second q))
                   (parse (second (second q)))
                   (parse (third q)))]
        [(and (list? q) (eq? (length q) 3) (symbol? (second q)) 
                                           (eq? 'min (first q)))
         (minimum (second q) (parse (third q)))]
         [(and (list? q) (eq? (length q) 3) (eq? '^ (first q)))
         (pow (parse (second q)) (parse (third q)))]
        [(and (list? q) (eq? (length q) 3) (symbol? (first q)))
         (binop (first q) (parse (second q)) (parse (third q)))]
        [(and (list? q) (eq? (length q) 5) 
                        (symbol? (fourth q)) 
                        (eq? 'sum (first q)))
         (sum (parse (second q)) 
              (parse (third q)) 
              (fourth q)
              (parse (fifth q)))]
        [(and (list? q) (eq? (length q) 5) 
                        (symbol? (fourth q)) 
                        (eq? 'integral (first q)))
         (integral (parse (second q)) 
                   (parse (third q)) 
                   (fourth q)
                   (parse (fifth q)))]
        ))

(define test2 (parse '(^ (integral 1 5 x (^ x 2)) (sum 0 4 x x))))
(define (test-subst)
  (subst (parse '(+ 2 2))
         'x
         (parse '(let [y (+ x 1)] (let [x (+ x y)] (+ y x))))))
(define e1 'x)
(define e2 '(let (x 42) (+ y x)))
(define e3 '(let (z 42) (+ y z)))

(subst (parse e1) 'y (parse e2))
(subst (parse e1) 'y (parse e3))

;Zad3

(struct binsign (sign f1 f2)     #:transparent)
(struct monosign (sign f)        #:transparent)
(struct quantifier (q v formula) #:transparent)
(struct variable (v)             #:transparent)

(define (expr2? e)
  (match e
    [(variable v)               (symbol? v)]
    [(binsign sign f1 f2)       (and (symbol? sign) (expr? f1) (expr? f2))]
    [(monosign sign f)          (and (symbol? sign) (expr? f))]
    [(quantifier q v formula)   (and (symbol? q) (symbol? v) (expr? formula))]
    [_              false]))

(define (good-binsign? sign)
  (member sign '(and or)))

(define (good-monosign? sign)
  (member sign '(neg)))

(define (good-quantifier? quantifier)
  (member quantifier '(forall exists)))

(define (parse2 e)
  (cond
    [(and (list? e)
          (= (length e) 3)
          (good-quantifier? (first e))
          (symbol? (second e)))
     (quantifier (first e) (second e) (parse (third e)))]
    [(and (list? e)
         (good-binsign? (second e))
         (= (length e) 3))
         (binsign (second e) (parse (first e)) (parse (third e)))]
    [(and (list? e)
         (good-monosign? (first e))
         (= (length e) 2))
         (monosign (first e) (parse (second e)))]
    [(symbol? e)
     (variable e)]
    [else false]))

;Zad4

(define (2eval x)
  (define (eval-formula f l)
    (define (eval-var v l)
      (if (null? l)
          #f
          (if (eq? (car (first l)) v)
              (cdr (first l))
              (eval-var v (cdr l)))))
    (match f
      [(binsign 'or f1 f2) (or (eval-formula f1 l)
                               (eval-formula f2 l))]
      [(binsign 'and f1 f2) (and (eval-formula f1 l)
                                 (eval-formula f2 l))]
      [(monosign 'neg f1) (not (eval-formula f1 l))]
      [(variable f1) (eval-var f1 l)]))
  (define (eval-aux ex lst)
    (match ex
      [(quantifier 'exists v f) (or (eval-aux f (append lst (list (cons v #t))))
                                    (eval-aux f (append lst (list (cons v #f)))))]
      [(quantifier 'forall v f) (and (eval-aux f (append lst (list (cons v #t))))
                                     (eval-aux f (append lst (list (cons v #f)))))]
      [_ (eval-formula ex lst)]))
  (match x
      [(quantifier 'exists v f) (or (eval-aux f (list (cons v #t)))
                                    (eval-aux f (list (cons v #f))))]
      [(quantifier 'forall v f) (and (eval-aux f (list (cons v #t)))
                                     (eval-aux f (list (cons v #f))))]))



;Zad5

(define (rename-var x y e)
  (match e
    [(var-expr z)
      (var-expr (if (eq? x z) y z))]
    [(const n)        (const n)]
    [(binop op e1 e2) (binop op (rename-var x y e1)
                                (rename-var x y e2))]
    [(let-expr z e1 e2)
      (let-expr z (rename-var x y e1)
                  (if (eq? x z) e2 (rename-var x y e2)))]))

(define (rename e)
  (define (fresh-symbol fresh)
    (string->symbol (string-append "x" (number->string fresh))))
  (define (rename e fresh)
    (match e
      [(var-expr x)       (var-expr x)]
      [(const n)          (const n)]
      [(binop op e1 e2)   (binop op (rename e1 fresh) (rename e2 fresh))]
      [(let-expr x e1 e2)
        (let* ([y   (fresh-symbol fresh)]
              [next-fresh (+ 1 fresh)]
              [e2y (rename-var x y e2)])
              (let-expr y (rename e1 fresh) (rename e2y next-fresh)))]))
  (rename e 0))


;Zad6

(struct environ (xs))

(define env-empty (environ null))
(define (env-add x v env)
  (environ (cons (cons x v) (environ-xs env))))
(define (env-lookup x env)
  (define (assoc-lookup xs)
    (cond [(null? xs) (error "Unknown identifier" x)]
          [(eq? x (car (car xs))) (cdr (car xs))]
          [else (assoc-lookup (cdr xs))]))
  (assoc-lookup (environ-xs env)))
  
(define (rename2 e)
  (define (walk e env)
    (match e
      [(const v) (const v)]
      [(binop op l r) (binop op (walk l env) (walk r env))]
      [(var-expr v) (env-lookup v env)]
      [(let-expr x e1 e2) 
       (let ([z (gensym 'x)]) 
         (let-expr z (walk e1 env) (walk e2 (env-add x z env))))]))
  (walk e env-empty))

(rename (binop '+
                 (let-expr 'x (const 1) (var-expr 'x))
                 (let-expr 'x (const 1) (var-expr 'x))))
(rename2 (binop '+
                 (let-expr 'x (const 1) (var-expr 'x))
                 (let-expr 'x (const 1) (var-expr 'x))))

(rename (let-expr 'x 
                    (const 3)
                    (binop '+
                           (var-expr 'x)
                           (let-expr 'x (const 5) (var-expr 'x)))))
(rename2 (let-expr 'x 
                    (const 3)
                    (binop '+
                           (var-expr 'x)
                           (let-expr 'x (const 5) (var-expr 'x)))))

;zad7


