#lang racket

(provide inc tagged-list? makeelem elempriority elemval leaf? hnode? make-hnode hnode-elem hnode-left hnode-right hnode-rank hord? heap? rank emptyheap heapinsert heapmerge heapmin heappop heapempty?)

(define (inc n)
  (+ n 1))

;;; tagged lists
(define (tagged-list? len-xs tag xs)
  (and (list? xs)
       (= len-xs (length xs))
       (eq? (first xs) tag)))

;;; ordered elements
(define (makeelem pri val)
  (cons pri val))

(define (elempriority x)
  (car x))

(define (elemval x)
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
      (<= p (elempriority (hnode-elem h)))))

(define (heap? h)
  (or (leaf? h)
      (and (hnode? h)
           (heap? (hnode-left h))
           (heap? (hnode-right h))
           (<= (rank (hnode-right h))
               (rank (hnode-left h)))
           (= (rank h) (inc (rank (hnode-right h))))
           (hord? (elempriority (hnode-elem h))
                  (hnode-left h))
           (hord? (elempriority (hnode-elem h))
                  (hnode-right h)))))

(define (rank h)
  (if (leaf? h)
      0
      (hnode-rank h)))

;; operations

(define emptyheap leaf)

(define (heapempty? h)
  (leaf? h))

(define (heapmin heap)
  (hnode-elem heap))

(define (heapinsert elt heap)
  (heapmerge heap (make-hnode elt leaf leaf)))

(define (heappop heap)
  (heapmerge (hnode-left heap) (hnode-right heap)))


;Zrobione we współpracy z
;Kacper Kingsford
;Mateusz Szwelengreber


;heapmerge
(define (heapmerge h1 h2)
  (cond
   [(leaf? h1) h2]
   [(leaf? h2) h1]
   [else (let ([e1 (elempriority (heapmin h1))]
               [e2 (elempriority (heapmin h2))])
           (let ([smaller (if (> e1 e2) h2 h1)]
                 [bigger (if (> e1 e2) h1 h2)])
             (let ([elem (heapmin smaller)]
                   [hr (hnode-right smaller)]
                   [hl (hnode-left smaller)])
               (make-hnode elem hl (heapmerge hr bigger)))))]))

;Test
(hnode? (heapmerge (make-hnode (makeelem 2 2) (make-hnode (makeelem 1 1) leaf leaf) (make-hnode (makeelem 3 3) leaf leaf))
                   (make-hnode (makeelem 5 5) (make-hnode (makeelem 6 6) leaf leaf) (make-hnode (makeelem 7 7) leaf leaf))))
(hnode? (heapmerge (make-hnode (makeelem 2 2) (make-hnode (makeelem 1 1) (make-hnode (makeelem 5 5) leaf leaf) leaf) (make-hnode (makeelem 3 3) leaf leaf))
                   (make-hnode (makeelem 5 5) (make-hnode (makeelem 6 6) leaf leaf) (make-hnode (makeelem 7 7) leaf (make-hnode (makeelem 8 8) leaf leaf)))))