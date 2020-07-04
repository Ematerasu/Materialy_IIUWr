#lang racket
(struct const (val)    #:transparent)
(struct binop (op l r) #:transparent)
(struct variable ()    #:transparent)
(struct ∂ (exp) #:transparent)

; 2 + 2 * 2
;(define 2+2*2 (binop '+ (const 2)
 ;                       (binop '* (const 2)
  ;                                (const 2))))

; Co to są wyrażenia?
(define (expr? e)
  (match e
    [(const n) (number? n)]
    [(binop op l r) (and (symbol? op) (expr? l) (expr? r))]
    [_ false]))

; Co to są wartości?
(define (value? v)
  (number? v))




; ------------------------- ;
; Trochę składni konkretnej ;
; ------------------------- ;

(define (parse q)
  (cond [(number? q) (const q)]
        [(and (list? q) (eq? (length q) 3) (symbol? (first q)))
         (binop (first q) (parse (second q)) (parse (third q)))]))

;(define (test) (eval (parse '(+ (* 2 3) (* 4 5)))))

;Zad1
;a)
#|(define a-cs (+ (+ (/ 8 (+ 2 3)) 10) 1))

(define a-ast 
	(binop '+ 
		(binop '+
			(binop '/
				(const 8)
				(binop '+ (const 2) (const 3)))
			(const 10))
		(const 1)))

;(parse a-cs)

;(equal? (parse '(+ (+ (/ 8 (+ 2 3)) 10) 1))
 ;    a-ast)

;b)
(define b-cs (+ (+ (+ 1 2) (* 3 4)) 5))

(define b-ast (binop '+
                          (binop '+
                                 (binop '+ (const 1) (const 2))
                                 (binop '* (const 3) (const 4)))
                         (const 5)))

;(parse b-cs)

;(equal? (parse '(+ (+ (+ 1 2) (* 3 4)) 5))
 ;    b-ast)|#

;Zad2
(define (square x) (binop '* x x))

(define (cont-frac num den k)
  (define (frac i)
    (if (< i k)
        (binop '/ (num i) (binop '+ (den i) (frac (+ i 1))))
        (binop '/ (num i) (den i))))
  (frac 1.0))

(define (pi-expr n)
  (define (num k)
    (square (binop '- 
                   (binop '* 
                          (const 2) 
                          (const k)) 
                   (const 1))))
  (define (den k)
    (const 6))
  (binop '+ (const 3) (cont-frac num den n)))

(define (eval-pi n)
  (eval (pi-expr n)))

;Zad3
(struct unop (op v) #:transparent)

(define (op->proc op)
  (match op ['+ +] ['- -] ['* *] ['/ /] ['^ expt] ['|| abs]))


(define (eval e)
  (match e
    [(const n) n]
    [(binop op l r) ((op->proc op) (eval l) (eval r))]
    [(unop op v) ((op->proc op) (eval v))]))

(define (parse2 q)
  (cond [(number? q) (const q)]
        [(and (list? q) (eq? (length q) 3) (symbol? (first q)))
            (binop (first q) (parse2 (second q)) (parse2 (third q)))]
        [(and (list? q) (eq? (length q) 2) (symbol? (first q)))
            (unop (first q) (parse2 (second q)))]))

(define (test2) (eval (parse2 '(+ (^ 2 3) (|| (* 4 -5))))))

;zad4

(define (pretty-print e)
    (match e
      [(const n) 
       (number->string n)]
      [(binop op l r) 
       (string-append "(" (pretty-print l) ")"
                      (symbol->string op) 
                      "(" (pretty-print r) ")")]))

(define (pretty-print2 e)
  (match e
    [(const n) 
     (number->string n)]
    [(binop op l r)
     (string-append (pretty-print2-paren l)
                    (symbol->string op) 
                    (pretty-print2-paren r))]))

(define (pretty-print2-paren e)
    (match e
        [(const n) 
         (number->string n)]
        [_ 
         (string-append "(" (pretty-print2 e) ")")]))

;zad5

(define (expr2? e)
  (match e
    [(variable)     true]
    [(const n)      (number? n)]
    [(binop op l r) (and (symbol? op) (expr2? l) (expr2? r))]
    [_              false]))

(define (parse3 q)
  (cond [(number? q) (const q)]
        [(eq? q 'x) (variable)]
        [(and (list? q) (eq? (length q) 3) (symbol? (first q)))
         (binop (first q) (parse3 (second q)) (parse3 (third q)))]))

(define (pochodna e)
  (match e
    [(const n) (const 0)]
    [(variable) (const 1)]
    [(binop '+ l r) (binop '+ (pochodna l) (pochodna r))]
    [(binop '* l r) (binop '+ (binop '* (pochodna l) r) (binop '* l (pochodna r)))]))
;Zad6

(define (simpl e)
  (match e
    [(binop '* (const 1) r) (simpl r)]
    [(binop '* l (const 1)) (simpl l)]
    [(binop '* (const 0) r) (const 0)]
    [(binop '* l (const 0)) (const 0)]
    [(binop '+ l (const 0)) (simpl l)]
    [(binop '+ (const 0) r) (simpl r)]
    [(const n) (const n)]
    [(variable) (variable)]               
    [(binop op l r) (binop op (simpl l) (simpl r))]))

;Zad7

(define (eval2 e val)
  (define (simplify e)
  (match e
    [(const n) n]
    [(variable) (variable)]
    [(binop op l r) (binop op (simplify l) (simplify r))]
    [(unop op v) (unop op (simplify v))]
    [(∂ exp) (pochodna (simplify exp))]))

  (define (substitution e)
    (match e
    [(const n) n]
    [(variable) val]
    [(binop op l r) ((op->proc op) (substitution l) (substitution r))]
    [(unop op v) ((op->proc op) (substitution v))]))
  (substitution (simplify e)))
    

(define (parse4 q)
  (cond [(number? q) (const q)]
        [(eq? q 'x) (variable)]
        [(and (list? q) (eq? (length q) 3) (or (eq? '+ (first q)) (eq? '* (first q))))
         (binop (first q) (parse4 (second q)) (parse4 (third q)))]
        [(and (list? q) (eq? (length q) 2) (eq? '∂ (first q)))
         (∂ (parse4 (second q)))]))
              
(eval2 (parse4 '(∂ (+ x (∂ (* x (* x x)))))) 10)

    
  