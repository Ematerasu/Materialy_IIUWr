#lang racket

(provide (struct-out complex) parse eval)

(struct complex (re im) #:transparent)
(struct i () #:transparent)

(define value?
  complex?)

;; Ponizej znajduje sie interpreter zwyklych wyrazen arytmetycznych.
;; Zadanie to zmodyfikowac go tak, by dzialal z liczbami zespolonymi.

(struct const (val)    #:transparent)
(struct binop (op l r) #:transparent)

(define (op->proc op)
  (match op ['+ +] ['- -] ['* *] ['/ /]))

(define (eval e)
  (match e
    [(const n) (complex n 0)]
    [(complex 0 1) (complex 0 1)]
    [(binop '* (const n) (complex 0 1)) (complex 0 n)]
    [(binop '* (complex 0 1) (const n)) (complex 0 n)]
    [(binop '* (complex rel iml) (complex rep imp)) (complex (- (* rel rep) (* iml imp)) (+ (* iml rep) (* rel imp)))]
    [(binop '/ (complex rel iml) (complex rep imp))
     (let ((x (+ (* rep rep) (* imp imp))))
       (complex (/ (+ (* rel rep) (* iml imp)) x) (/ (- (* iml rep) (* rel imp)) x)))] 
    [(binop '+ (complex rel iml) (complex rep imp)) (complex (+ rel rep) (+  iml imp))]
    [(binop '- (complex rel iml) (complex rep imp)) (complex (- rel rep) (-  iml imp))]
    [(binop op l r) (eval (binop op (eval l) (eval r)))]))


(define (parse q)
  (cond [(number? q) (const q)]
        [(eq? q 'i) (complex 0 1)]
        [(and (list? q) (eq? (length q) 3) (symbol? (first q)))
         (binop (first q) (parse (second q)) (parse (third q)))]
        ))
        