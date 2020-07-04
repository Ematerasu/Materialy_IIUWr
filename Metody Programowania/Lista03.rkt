#lang racket
;Zadanie1

;punkt

(define (make-point x y)
  (cons x y))

(define (point? x)
  (and (cons? x)
       (number? (car x))
       (number? (cdr x))))

(define (point-x x)
  (car x))

(define (point-y x)
  (cdr x))

;Wektor

(define (make-vect x y)
  (cons x y))

(define (vect? x)
  (and (cons? x)
       (point? (car x))
       (point? (cdr x))))

(define (vect-begin x)
  (car x))

(define (vect-end x)
  (cdr x))

(define (display-point p)
  (display "(")
  (display (point-x p))
  (display ", ")
  (display (point-y p))
  (display ")"))

(define (display-vect v)
  (display "[")
  (display-point (vect-begin v))
  (display ", ")
  (display-point (vect-end v))
  (display "]"))

(define (vect-length v)
  (sqrt (+
         (* (- (point-x (vect-end v)) (point-x (vect-begin v))) (- (point-x (vect-end v)) (point-x (vect-begin v)))
         (* (- (point-y (vect-end v)) (point-y (vect-begin v))) (- (point-y (vect-end v)) (point-y (vect-begin v))))))))

;(vect-length (make-vect (make-point 1 1) (make-point 2 2)))
;(vect-length (make-vect (make-point 1 3) (make-point 8 5)))

;......duzo tego

;Zadanie2

(define (make-vect2 p k dl)
  (cons (cons p k) dl))

;wszystko analogicznie

;Zadanie3

(define (reverse l)
  (if (null? l)
      null
      (append (reverse (cdr l)) (list (car l)))))

(define (reverse-iter l)
  (define (f l result)
    (if (null? l)
        result
        (f (cdr l) (cons (car l) result))))
  (f l null))

;Zadanie 4

(define (insert xs n)
  (if (null? xs)
      (list n)
      (if (> n (car xs))
          (append (list (car xs)) (insert (cdr xs) n))
          (append (list n) xs))))

(define (insert-sort xs)
  (define (sort xs l)
    (if (null? xs)
        l
        (sort (cdr xs) (insert l (car xs)))
    ))
  (sort xs null))

;Zadanie 5

(define (select-min xs)
  (define (search l min)
    (if (null? l)
        min
        (if (> min (car l))
            (search (cdr l) (car l))
            (search (cdr l) min))))
  (search (cdr xs) (car xs)))

(define (selection-sort xs)
  (define (sort xs l)
    (if (null? xs)
        l
        (sort (cdr xs) (insert l (select-min (cdr xs))))))
  (sort xs null))

;Zadanie 6
  