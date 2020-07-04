#lang racket
(provide cont-frac)

(define (cont-frac num den)
  
  (define (good-enough a b)
    (< (abs (- a b)) 0.000001))

  (define (n-ta_wartosc num den n-1 n-2 m)
    (+ (* (den m) n-1) (* (num m) n-2)))
  
  (define (obliczanie_fk A B nextA nextB m)
    (if (good-enough (/ A B) (/ nextA nextB))
        (/ nextA nextB)
        (obliczanie_fk nextA nextB
                       (n-ta_wartosc num den nextA A (+ m 1))
                       (n-ta_wartosc num den nextB B (+ m 1))
                       (+ m 1))))
  (obliczanie_fk 0
                 1
                 (n-ta_wartosc num den 0 1 1)
                 (n-ta_wartosc num den 1 0 1)
                 1))

;Testy
(define (square x) (* x x))
(+ 3 (cont-frac (lambda (x) (square (+ 1(* (- x 1) 2)))) (lambda (x) 6))) ;liczba pi z cwiczenia 7
(/ 1 (cont-frac (lambda (x) 1) (lambda (x) 1))) ;zloty podzial z przykladu
(+ 1 (cont-frac (lambda (x) 1) (lambda (x) 2))) ; pierwiastek z 2 wziety z https://www.obliczeniowo.com.pl/18