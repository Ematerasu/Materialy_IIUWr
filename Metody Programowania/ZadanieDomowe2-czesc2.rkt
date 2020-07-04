#lang racket

(provide nth-root)

;Procedury z wykladu i z cwiczen

(define (identity x) x)

(define (repeated p n)
  (if (= n 0)
      (identity p)
      (compose p (repeated p (- n 1)))))


(define (close-to? x y)
  (< (abs (- x y)) 0.00001))

(define (average x y)
  (/ (+ x y) 2))

(define (average-damp f)
  (lambda (x)
    (average x (f x))))

(define (fixed-point s f)
  (if (close-to? s (f s))
      s
      (fixed-point (f s) f)))

(define (sqrt x)
  (let ((op (lambda (y) (/ x y))))
    (fixed-point 1.0 (average-damp op))))

;Pomocnicza procedura obliczająca n-tą potęge

(define (nth-power x n)
  (define (nth-power-iter x n result)
    (if (= n 0)
        result
        (nth-power-iter x (- n 1) (* result x))))
  (nth-power-iter x n 1.0))

;;

(define (nth-root n x)
  (if (= n 1)
      x
      (let ([op (lambda (y) (/ x (nth-power y (- n 1))))])
      (fixed-point 1.0 ((repeated average-damp (floor(sqrt n))) op)))))
      
;Podczas eksperymentowania podloga z sqrt(n) tlumien dalo zadowalajace wyniki,
;Procedura nth-root to poprostu przerobiona procedura sqrt z wykladu

(nth-root 5 100000)
(nth-root 2 225)
(nth-root 4 81)
(nth-root 4 16)
(nth-root 5 305.97456093718098884375) ;pi^5
(nth-root 10 1024)
(nth-root 11 2048)
