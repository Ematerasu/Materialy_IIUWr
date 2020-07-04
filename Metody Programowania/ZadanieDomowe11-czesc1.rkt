#lang racket

(provide (contract-out
          [with-labels with-labels/c]
          [foldr-map foldr-map/c]
          [pair-from pair-from/c]))
(provide with-labels/c foldr-map/c pair-from/c)

(define (with-labels f xs)
  (parametric->/c [a b] (-> (-> a b) (listof a) (listof (cons/c b (listof a)))))
  (if (null? xs)
      null
      (cons (list (f (car xs)) (car xs)) (with-labels f (cdr xs)))))

(define with-labels/c (parametric->/c [a b] (-> (-> a b) (listof a) (listof (cons/c b (listof a))))))

(with-labels number->string (list 1 2 3))


(define (foldr-map f a xs)
  (parametric->/c [a acc b] (-> (-> a acc (cons/c b acc)) acc (listof a)
                              (cons/c (listof b) acc)))
   (define (it a xs ys)
      (if (null? xs)
          (cons ys a)
          (let [(p (f (car xs) a))]
            (it (cdr p)
                 (cdr xs)
                 (cons (car p) ys)))))
   (it a (reverse xs) null))

(define foldr-map/c (parametric->/c [a acc b] (-> (-> a acc (cons/c b acc)) acc (listof a)
                              (cons/c (listof b) acc))))


(foldr-map (lambda (x a) (cons a (+ a x ))) 0 '(1 2 3))

(define (pair-from f g)
  (parametric->/c [a b c] (-> (-> c a) (-> c b) (-> c (cons/c a b))))
  (lambda (x) (cons (f x) (g x))))

(define pair-from/c (parametric->/c [a b c] (-> (-> c a) (-> c b) (-> c (cons/c a b)))))

((pair-from (lambda (x) (+ x 1)) (lambda (x) (* x 2))) 2)
