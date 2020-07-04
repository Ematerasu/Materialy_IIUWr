#lang racket
;Wzorowalem sie na przykladzie z wykladu.

(provide cube-root)

(define (cube-root x)
     (define (approximation y)
       (define (square) (* y y))
       
       (/ (+ (/ x (square)) (* 2 y)) 3))
     
     (define (iter y)
       
       (define (good-enough? guess)
         (define (cube) (* guess guess guess))
         (< (abs (- x (cube))) 0.000000001))
       
       (if (good-enough? y) y (iter (approximation y))))

     (iter 1.0))


(cube-root 27)
(cube-root 64)
(cube-root -1)
(cube-root 1)
(cube-root 1000)
(cube-root 0.125)
(cube-root 0.008)
(cube-root 216)
(cube-root -125)
(cube-root 1000)
(cube-root 12167) ;23^3
(cube-root 884736) ;96^3
(cube-root 31.003533398375) ;(3.1415)^3

