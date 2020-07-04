#lang racket
;Zadanie1
#|
x ; nie zwiazany

(let ([ x 3]) 
  (+ x y ) ) ;x zwiazane z 3, y nie jest zwiazany

(let ([ x 1] [ y (+ x 2) ])
  (+ x y ) ) ;x w (+ x y) zwiazany z [x 1] lecz x w [ y (+ x 2) ] nie, y zwiazany z [y (+ x 2)]

(let ([ x 1])
  ( let ([ y (+ x 2) ]) ;x zwiazany z [x 1] i [y (+ x 2)], y zwiazany z [y (+ x 2)]
     (* x y ) ) )

( lambda ( x y )
   (* x y z ) ) ;x zwiazany, y zwiazany i z nie zwiazane

(let ([ x 1])
  ( lambda ( y z )
     (* x y z ) ) ) ;x zwiazany z [x 1], y zwiazany i z zwiazany
|#
;Zadanie2

(define (square x) (* x x))

(define (inc x) (+ x 1))

(define (compose f g)
  (lambda (x)
    (f (g x))))

;Zadanie3

(define (identity x) x)

(define (repeated p n)
  (if (= n 0)
      (identity p)
      (compose p (repeated p (- n 1)))))

;Zadanie 4

(define (product-rek val next start end)
  (define (zadanie4-rek start)
    (if (> start end)
      1.0
      (* (val start) (zadanie4-rek (next start)))))
  (zadanie4-rek start)
  )

(define (count-pi x)
  (* 4 (product-iter (lambda (x)
                       (/ (* x (+ x 2))
                          (square (+ x 1))))
                     (lambda (x)
                       (+ x 2))
                     2
                     x)))

(define (product-iter val next start end)
  (define (zadanie4-iter start result)
    (if(> start end)
     result
     (zadanie4-iter (next start) (* (val start) result))))
  (zadanie4-iter start 1)
  )
           
  

;Zadanie 5

;(define (accumulate combiner null-value term a next b))
  

