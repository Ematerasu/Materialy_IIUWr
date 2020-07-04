#lang racket

;Sposob na znalezienie pivota wzialem z https://gist.github.com/lambrospetrou/970bcf188eb6061e1bfbfa9e36c29042
;Reszta kodu jest zrobiona samodzielnie

(provide partition quicksort)

(define (partition n xs)
    (define (f xs n l1 l2)
      (if (null? xs)
          (list l1 l2)
          (if (> (car xs) n)
              (f (cdr xs) n l1 (append l2 (list (car xs))))
              (f (cdr xs) n (append l1 (list (car xs))) l2))))
  (f xs n '() '()))


(define (quicksort xs)
  (if (null? xs)
        xs
        (let ([pivot (car xs)])
          (append (quicksort (car (partition pivot (cdr xs))))
                  (list pivot)
                  (quicksort (car (cdr (partition pivot (cdr xs)))))))))

(quicksort '(8 1 4 7 6 2 3))
(quicksort '(8 7 6 5 4 3 2 1))
(quicksort '(1 2 1 2 1 2 1 2))
(quicksort '(9 9 9 9 1 1 1))
(quicksort '(1 2 3 4 5 6 7))

