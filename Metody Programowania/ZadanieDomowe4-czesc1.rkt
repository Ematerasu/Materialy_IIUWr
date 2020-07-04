#lang racket

(define (inc n)
  (+ n 1))

;;; tagged lists
(define (tagged-list? len-xs tag xs)
  (and (list? xs)
       (= len-xs (length xs))
       (eq? (first xs) tag)))

;;; ordered elements
(define (make-elem pri val)
  (cons pri val))

(define (elem-priority x)
  (car x))

(define (elem-val x)
  (cdr x))

;;; leftist heaps (after Okasaki)

;; data representation
(define leaf 'leaf)

(define (leaf? h) (eq? 'leaf h))

(define (hnode? h)
  (and (tagged-list? 5 'hnode h)
       (natural? (caddr h))))

(define (make-hnode elem heap-a heap-b)
  (if (>= (rank heap-a) (rank heap-b))
      (list 'hnode elem (+ (rank heap-b) 1) heap-a heap-b)
      (list 'hnode elem (+ (rank heap-a) 1) heap-b heap-a)
      ))

(define (hnode-elem h)
  (second h))

(define (hnode-left h)
  (fourth h))

(define (hnode-right h)
  (fifth h))

(define (hnode-rank h)
  (third h))

(define (hord? p h)
  (or (leaf? h)
      (<= p (elem-priority (hnode-elem h)))))

(define (heap? h)
  (or (leaf? h)
      (and (hnode? h)
           (heap? (hnode-left h))
           (heap? (hnode-right h))
           (<= (rank (hnode-right h))
               (rank (hnode-left h)))
           (= (rank h) (inc (rank (hnode-right h))))
           (hord? (elem-priority (hnode-elem h))
                  (hnode-left h))
           (hord? (elem-priority (hnode-elem h))
                  (hnode-right h)))))

(define (rank h)
  (if (leaf? h)
      0
      (hnode-rank h)))

;; operations

(define empty-heap leaf)

(define (heap-empty? h)
  (leaf? h))

(define (heap-min heap)
  (hnode-elem heap))

(define (heap-insert elt heap)
  (heapmerge heap (make-hnode elt leaf leaf)))

(define (heap-pop heap)
  (heapmerge (hnode-left heap) (hnode-right heap)))

;;; check that a list is sorted (useful for longish lists)
(define (sorted? xs)
  (cond [(null? xs)              true]
        [(null? (cdr xs))        true]
        [(<= (car xs) (cadr xs)) (sorted? (cdr xs))]
        [else                    false]))


;Zrobione we współpracy z
;Kacper Kingsford
;Mateusz Szwelengreber


;heapmerge Zad7
(define (heapmerge h1 h2)
  (cond
   [(leaf? h1) h2]
   [(leaf? h2) h1]
   [else (let ([e1 (elem-priority (heap-min h1))]
               [e2 (elem-priority (heap-min h2))])
           (let ([smaller (if (> e1 e2) h2 h1)]
                 [bigger (if (> e1 e2) h1 h2)])
             (let ([e (heap-min smaller)]
                   [hr (hnode-right smaller)]
                   [hl (hnode-left smaller)])
               (make-hnode e hl (heapmerge hr bigger)))))]))

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
(define (randomlist n mx)
  (cond
    [(= n 0) empty]
    [else
     (cons (+ 1 (random mx))
           (randomlist (- n 1) mx))]))
;;procedura random list do testow

(sorted? (heapsort '(3 9 8 1 3 5 6 2 3 1 7 5 7 9 7 0 1 3 5)))
(sorted? (heapsort (randomlist 100 100)))
(sorted? (heapsort (randomlist 500 1000)))

