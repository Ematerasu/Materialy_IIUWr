#lang racket
(require "props.rkt")
(provide falsifiable-cnf?)

(define (make-neg f)
  (list 'neg f))

(define (make-conj l r)
  (list 'conj l r))

(define (make-disj l r)
  (list 'disj l r))

(define (neg-subf l)
  (second l))

(define (conj-left l)
  (second l))

(define (conj-rght l)
  (third l))

(define (disj-left l)
  (second l))

(define (disj-rght l)
  (third l))

(define (make-literal b p)
    (list 'literal b p))

(define (lit? f)
  (or (var? f)
      (and (neg? f)
           (var? (neg-subf f)))))

(define (lit-pos v)
  v)

(define (lit-neg v)
  (neg v))

(define (lit-var l)
  (if (var? l)
      l
      (neg-subf l)))

(define (lit-pos? l)
  (var? l))

(define (free-vars f)
    (define (go f)
        (cond ((var? f)
               (list f))
              ((neg? f)
               (go (neg-subf f)))
              ((disj? f)
               (append (go (disj-left f)) 
                       (go (disj-rght f))))
              ((conj? f)
               (append (go (conj-left f)) 
                       (go (conj-rght f))))))
    (remove-duplicates (go f))) 
 
(define (gen-vals xs)
  (if (null? xs)
      (list null)
      (let*
          ((vss  (gen-vals (cdr xs)))
           (x    (car xs))
           (vst  (map (lambda (vs) (cons (list x true)  vs)) vss))
           (vsf  (map (lambda (vs) (cons (list x false) vs)) vss)))
        (append vst vsf))))

(define (eval-formula xs val)
  (cond [(var? xs) (second (assoc xs val))]
        [(neg? xs) (not (eval-formula (neg-subf xs) val))]
        [(conj? xs) (and (eval-formula (conj-left xs) val)
                         (eval-formula (conj-rght xs) val))]
        [(disj? xs) (or (eval-formula (disj-left xs) val)
                        (eval-formula (disj-rght xs) val))]))

(define (falsifiable-eval? f)
  (define (is-false v)
    (if (not (eval-formula f v))
        v
        false))

  (let* [
        (vars (free-vars f))
        (all-vals (gen-vals vars))
        ]
    (ormap is-false all-vals)))

(define (to-nnf f)
  (cond
   [(var? f)  (lit-pos f)]
   [(neg? f)  (to-nnf-neg (neg-subf f))]
   [(conj? f) (conj (to-nnf (conj-left f))
                    (to-nnf (conj-right f)))]
   [(disj? f) (disj (to-nnf (disj-left f))
                    (to-nnf (disj-right f)))]))

(define (to-nnf-neg f)
  (cond
   [(var? f)  (lit-neg f)]
   [(neg? f)  (to-nnf (neg-subf f))]
   [(conj? f) (disj (to-nnf-neg (conj-left f))
                    (to-nnf-neg (conj-right f)))]
   [(disj? f) (conj (to-nnf-neg (disj-left f))
                    (to-nnf-neg (disj-right f)))]))

(define (mk-cnf xss)
  (cons 'cnf xss))

(define (clause? f)
  (and (list? f)
       (andmap lit? f)))

(define (cnf? f)
  (and (pair? f)
       (eq? 'cnf (car f))
       (list? (cdr f))
       (andmap clause? (cdr f))))

(define (to-cnf f)
  (define (join xss yss)
    (apply append (map (lambda (xs) (map (lambda (ys) (append xs ys)) yss)) xss)))
  (define (go f)
    (cond
     [(lit? f)  (list (list f))]
     [(conj? f) (append (go (conj-left f))
                        (go (conj-right f)))]
     [(disj? f) (join (go (disj-left f))
                      (go (disj-right f)))]))
  (mk-cnf (go f)))

(define (falsifiable-cnf? f)
  (define (false-clause? cl)
    (if (null? cl)
        false
        (let* ([klauzula (cons 'disj (car cl))]
              [wartosciowanie (falsifiable-eval? klauzula)])
          (if (eq? #f wartosciowanie)
              (false-clause? (cdr cl))
              wartosciowanie))))            
  (false-clause? (cdr (to-cnf f))))

;Idea jest taka by (po sprowadzeniu do CNF) sprawdzac kazda klauzule po kolei, jesli jedna klauzula ma wartosciowanie dla ktorego
;jest falszywa to cala formula w cnf jest falszywa. Skorzystalem z procedury falsifiable-eval? oraz innych z nia zwiazanych ktore
;byly na liscie zadan oraz korzystam z plikow dolaczonych na skosie do tego zadania.
;Taki sposob moze okazac sie wydajny jezeli np. pierwsza klauzula pozwoli podac wartosciowanie dla ktorego formula jest falszywa,
;w przeciwienstwie do sposobu z listy zadan, w ktorym generujemy wszystkie wartosciowania i po kolei szukamy takiego dla ktorego
;formula jest falszywa.

;Testy
(falsifiable-cnf? (make-conj (make-disj (make-conj 'p (make-neg 'q)) 't) (make-disj 's (make-neg 'p))))
(falsifiable-cnf? (make-disj 'p (make-neg 'p)))
(falsifiable-cnf? (make-disj 'p (make-conj (make-neg 'q) 't)))
(falsifiable-cnf? (make-conj
                     (make-disj
                      (make-conj 'p 'p)
                      (make-conj (make-neg 'p) (make-neg 'p)))
                     (make-disj 'p (make-neg 'p))))

