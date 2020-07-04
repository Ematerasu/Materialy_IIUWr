#lang racket
(define (tagged-list? len sym x)
  (and (list? x)
       (= (length x) len)
       (eq? (first x) sym)))

(define leaf 'leaf)

(define (leaf? x)
  (eq? x 'leaf))

(define (node e l r)
  (list 'node e l r))

(define (node? x)
  (tagged-list? 4 'node x))

(define (node-elem x)
  (second x))

(define (node-left x)
  (third x))

(define (node-right x)
  (fourth x))

(define (tree? x)
  (or (leaf? x)
      (and (node? x)
           (tree? (node-left  x))
           (tree? (node-right x)))))

( define (btree? t)
   (or (eq? t 'leaf)
       (and (list? t)
            (= 4 (length t))
            (eq? (car t) 'node)
            (btree? (caddr t))
            (btree? (cadddr t)))))

;Zad3
(define (mirror node)
     (if (leaf? node)
         leaf
         (list 'node (node-elem node)
               (mirror (node-right node))
               (mirror (node-left node)))))

;Zad4
(define (flatten node)
  (define (f node acc)
    (if (leaf? node)
      acc
      (f (node-left node) (cons (node-elem node) (f (node-right node) acc)))))
  (f node null))


;Zad5
(define (find x t)
  (cond
    [(leaf? t)            false]
    [(= (node-elem t) x)  true]
    [(> (node-elem t) x)  (find x (node-left t))]
    [(< (node-elem t) x)  (find x (node-right t))]))

(define (insert x t)
  (cond
    [(leaf? t)            (node x leaf leaf)]
    [(= (node-elem t) x)  t]
    [(> (node-elem t) x)  (node (node-elem t)
                                (insert x (node-left t))
                                (node-right t))]
    [(< (node-elem t) x)  (node (node-elem t)
                                (node-left t)
                                (insert x (node-right t)))]))

(define empty leaf)

(define (treesort node)
  (define (f node res)
    (if (leaf? node)
        res
        (f ()
