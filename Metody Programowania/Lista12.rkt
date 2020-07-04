#lang racket

;Zad1
(define/contract (dist x y)
  (-> number? number? number?)
  (abs (- x y)))

(define/contract (average x y)
  (-> number? number? number?)
  (/ (+ x y) 2))

(define/contract (square x)
  (-> number? number?)
  (* x x))
  
(define (close-enough? a b)
  (< (dist a b) 0.0001))

(define/contract (sqrt x)
    (->i ([in (or/c positive? zero?)])
          [result (in) (and/c (or/c positive? zero?)
                              (lambda (x) (close-enough? (square x) in)))])
     
    
  (define (improve approx)
    (average (/ x approx) approx))
  
  (define (good-enough? approx)
    (< (dist x (square approx)) 0.0001))
  
  (define (iter approx)
    (cond
      [(good-enough? approx) approx]
      [else                  (iter (improve approx))]))
  
  (iter 1.0))

;Zad2
;***Kontrakt parametryczny***
(define filter-old/c (parametric->/c [a] (-> (-> a boolean?) (listof a) (listof a))))
(define/contract (filter-old p xs)
  filter-old/c
  (if (null? xs)
      null
      (if (p (car xs))
          (cons (car xs) (filter p (cdr xs)))
          (filter p (cdr xs)))))

;***Kontrakt zależny***
(define (contains? l1 l2)
  (andmap (lambda (x) (member x l1)) l2))

(define (contains/c l1)
  (lambda (l2) (contains? l1 l2)))

(define filter-new/c (->i ([p (-> any/c boolean?)]
                           [l list?])
                           [result (p l) (and/c list?
                                                (contains/c l))]))

;;lepszy kontrakt
(define (check-list/c p)
  (lambda (r) (andmap p r)))

(define (is-sub xs ys) ;ys jest podciągiem xs
    (cond [(null? ys) #t]
           [(null? xs) #f]
           [(eq? (car xs) (car ys)) (is-sub (cdr xs)(cdr ys))]
           [else (is-sub (cdr xs) ys)]))
  
(define filter-best/c (->i ([p (-> any/c boolean?)]
                           [l list?])
                           [result (p) (and/c list?
                                              (check-list/c p))]
                            #:post (result l)
                            (is-sub l result)))

(define/contract (filter-new p xs)
  filter-best/c
  (if (null? xs)
      null
      (if (p (car xs))
          (cons (car xs) (filter p (cdr xs)))
          (filter p (cdr xs)))))
;Zad3

(define-signature monoid^
  ((contracted
    [elem? (-> any/c boolean?)]
    [neutral elem?]
    [oper (-> elem? elem? elem?)])))
    
(define-unit monoid-int@
    (import)
    (export monoid^)
    
    (display "monoid-int@ started\n")
    
    (define elem? integer?)
    
    (define neutral 0)
    
    (define oper +))
    
;(define-values/invoke-unit/infer monoid-int@)

(define-unit monoid-list@
    (import)
    (export monoid^)
    
    (display "monoid-list@ started\n")
    
    (define elem? list?)
    
    (define neutral '())
    
    (define oper append))
    
;(define-values/invoke-unit/infer monoid-list@)

;Zad4
(require quickcheck)

;testy dla int
#|(quickcheck
  (property 
      ([x arbitrary-integer])
      (and (= (oper neutral x) x)
           (= (oper x neutral) x))))

(quickcheck
   (property 
     ([x arbitrary-integer]
      [y arbitrary-integer]
      [z arbitrary-integer])
     (= (oper x (oper y z)) (oper (oper x y) z))))|#

;test dla list
#|(quickcheck
  (property 
      ([xs (arbitrary-list arbitrary-integer)])
      (and (equal? (oper neutral xs) xs)
           (equal? (oper xs neutral) xs))))|#

;Zad5

(define-signature set^
  ((contracted
    [set? (-> any/c boolean?)]
    [elem? (-> integer? set? boolean?)]
    [empty-set set?]
    [singleton (-> integer? set?)]
    [union (-> set? set? set?)]
    [intersection (-> set? set? set?)])))
    
    
(define-unit set-list@
    (import)
    (export set^)
    
    (define (set? xs)
      (and (list? xs)
           (andmap integer? xs)))
    
    (define (elem? x xs)
        (if (member x xs)
            #t
            #f))
            
    (define empty-set null)
    
    (define (singleton x)
        (list x))
        
    (define (union xs1 xs2)
        (remove-duplicates (append xs1 xs2)))
        
    (define (intersection xs1 xs2)
        (filter (lambda (x) (member x xs2)) xs1))
)

;Zad6

(define-values/invoke-unit/infer set-list@)

(quickcheck
 (property
  ([x arbitrary-integer])
  (not (elem? x empty-set))))
  
(quickcheck
  (property
    ([x arbitrary-integer]
     [y arbitrary-integer])
     (==> (elem? y (singleton x)) (= x y))))

(quickcheck
 (property
  ([x arbitrary-integer])
  (not (elem? x empty-set))))
  
(quickcheck
  (property
    ([x arbitrary-integer]
     [y arbitrary-integer])
     (==> (elem? y (singleton x)) (= x y))))
     

(define (list-to-set xs)
    (if (null? xs)
        empty-set
        (union (singleton (car xs)) 
               (list-to-set (cdr xs)))))
    
(quickcheck
    (property
        ([xs (arbitrary-list arbitrary-integer)]
         [ys (arbitrary-list arbitrary-integer)])
         (let ([s1 (list-to-set xs)]
               [s2 (list-to-set ys)])
          (property
           ([x arbitrary-integer]) ;;może być przed letem
               (==> (elem? x (union s1 s2)) 
                   (or (elem? x s1) (elem? x s2)))))))

