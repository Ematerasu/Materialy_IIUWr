#lang racket

(require racklog)

;;------------RODZINKA--------------

;; predykat unarny %male reprezentuje zbiór mężczyzn
(define %male
  (%rel ()
        [('adam)]
        [('john)]
        [('joshua)]
        [('mark)]
        [('david)]))

;; predykat unarny %female reprezentuje zbiór kobiet
(define %female
  (%rel ()
        [('eve)]
        [('helen)]
        [('ivonne)]
        [('anna)]))

;; predykat binarny %parent reprezentuje relację bycia rodzicem
(define %parent
  (%rel ()
        [('adam 'helen)]
        [('adam 'ivonne)]
        [('adam 'anna)]
        [('eve 'helen)]
        [('eve 'ivonne)]
        [('eve 'anna)]
        [('john 'joshua)]
        [('helen 'joshua)]
        [('ivonne 'david)]
        [('mark 'david)]))

;; predykat binarny %sibling reprezentuje relację bycia rodzeństwem
(define %sibling
  (%rel (a b c)
        [(a b)
         (%parent c a)
         (%parent c b)
         (%/= a b)]))

;; predykat binarny %sister reprezentuje relację bycia siostrą
(define %sister
  (%rel (a b)
        [(a b)
         (%sibling a b)
         (%female a)]))

;; predykat binarny %ancestor reprezentuje relację bycia przodkiem
(define %ancestor
  (%rel (a b c)
        [(a b)
         (%parent a b)]
        [(a b)
         (%parent a c)
         (%ancestor c b)]))

;; predykat binarny %grandson
(define %grandson
  (%rel (a b c)
        [(a b)
         (%parent b c)
         (%parent c a)
         (%male a)]))

;; predykat binarny %cousine
(define %cousin
  (%rel (a b c d)
        [(a b)
         (%parent c a)
         (%parent d b)
         (%sibling c d)]))

;; predykat unarny %is_mother
(define %is_mother
  (%rel (a b)
        [(a)
         (%parent a b)
         (%female a)]))

;; predykat unarny %is_father
(define %is_father
  (%rel (a b)
        [(a)
         (%parent a b)
         (%male a)]))


;;------------LISTY--------------;;

(define %my-append
  (%rel (x xs ys zs)
        [(null ys ys)]
        [((cons x xs) ys (cons x zs))
         (%my-append xs ys zs)]))

(define %my-member
  (%rel (x xs y)
        [(x (cons x xs))]
        [(y (cons x xs))
         (%my-member y xs)]))

(define %select
  (%rel (x xs y ys)
        [(x (cons x xs) xs)]
        [(y (cons x xs) (cons x ys))
         (%select y xs ys)]))

;; prosta rekurencyjna definicja
(define %simple-length
  (%rel (x xs n m)
        [(null 0)]
        [((cons x xs) n)
         (%simple-length xs m)
         (%is n (+ m 1))]))

;; test w trybie +- (działa)
;(%find-all (a) (%simple-length (list 1 2) a))
;; test w trybie ++ (działa)
;(%find-all () (%simple-length (list 1 2) 2))
;; test w trybie -+ (1 odpowiedź, pętli się)
;(%which (xs) (%simple-length xs 2))
;; test w trybie -- (nieskończona liczba odpowiedzi)
;(%which (xs a) (%simple-length xs a))


(define %sublist
 (%rel (xs ys y)
    [(null null)]
    [(xs (cons y ys))
     (%sublist xs ys)]
    [((cons y xs) (cons y ys))
     (%sublist xs ys)]))

(define %permi
 (%rel (x xs ys zs)
   [(null null)]
   [((cons x xs) ys)
    (%permi xs zs)
    (%select x ys zs)]))

(define %perms
 (%rel (x xs ys zs)
  [(null null)]
  [(xs (cons x ys))
   (%select x xs zs)
   (%perms zs ys)]))

(define (list->num xs)
  (define (aux xs acc)
    (if (null? xs)
      acc
      (aux (cdr xs) (+ (* 10 acc) (car xs)))))
  (aux xs 0))

