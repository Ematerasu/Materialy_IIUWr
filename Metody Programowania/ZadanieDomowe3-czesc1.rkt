#lang racket

(provide merge split mergesort)

(define (merge l1 l2)
    (if (null? l1)
        l2
        (if (null? l2)
            l1
            (if (> (car l1) (car l2))
                (cons (car l2) (merge l1 (cdr l2)))
                (cons (car l1) (merge (cdr l1) l2))))))

(define (split xs)
  (if (null? xs)
      (list '() '())
      (if (null? (cdr xs))
          (list xs '())
          (list (cons (car xs) (car (split (cdr (cdr xs)))))
                (cons (car (cdr xs)) (car (cdr (split (cdr (cdr xs))))))))))

(define (mergesort xs)
  (if (null? xs)
      null
      (if (null? (cdr xs))
          xs
          (merge (mergesort (car (split xs))) (mergesort (car (cdr (split xs))))))))                

(mergesort '(8 1 4 7 6 2 3))
(mergesort '(8 7 6 5 4 3 2 1))
(mergesort '(1 2 1 2 1 2 1 2))
(mergesort '(9 9 9 9 1 1 1))
(mergesort '(1 2 3 4 5 6))
              