#lang racket

(define (Cw4 a b c)
  (define (square x) (* x x))

  (cond [(and (< a b) (< c b)) (+ (square b) (square(if (< a c) c a)))]
        [(and (< b a) (< c a)) (+ (square a) (square(if (< b c) c b)))]
        [else (+ (square c) (square(if (< b a) a b)))]
                          ))

( define ( a-plus-abs-b a b )
   ((if ( > b 0) + -) a b ))


(define (power-close-to b n)

   (define (check x)
     (if (> (expt b x) n) x (check (+ x 1))))
  
  (check 1.0))


(define (p) (p))

(power-close-to 2 5)
(power-close-to 3 80)
(power-close-to 3 81)
(power-close-to 5 35215)
(power-close-to 4 5)
(power-close-to 2 1)






