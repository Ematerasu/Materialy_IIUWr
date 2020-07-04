#lang racket

(require "leftist.rkt")    
(provide heapsort)

;heapsort Zad8
(define (heapsort xs)
  
  (define (kopiec)
    (define (makekopiec h ls)
      (if (null? ls)
          h
          (makekopiec (heap-insert (make-elem (car ls) (car ls)) h) (cdr ls))))
  (makekopiec empty-heap xs))
  
  
  (define (sort h1)
    (if (heap-empty? h1)
        null
        (cons (elem-val (heap-min h1)) (sort (heap-pop h1)))))
        
  (sort (kopiec)))


;;testy

(sorted? (heapsort '(3 9 8 1 3 5 6 2 3 1 7 5 7 9 7 0 1 3 5)))
(sorted? (heapsort (randomlist 100 100)))
(sorted? (heapsort (randomlist 500 1000)))