#lang racket
(provide (struct-out const) (struct-out binop) rpn->arith)

(struct stack (xs))

(define empty-stack (stack null))
(define (empty-stack? s) (null? (stack-xs s)))
(define (top s) (car (stack-xs s)))
(define (push a s) (stack (cons a (stack-xs s))))
(define (pop s) (stack (cdr (stack-xs s))))

;; -------------------------------
;; Wyrazenia w odwr. not. polskiej
;; -------------------------------

(define (rpn-expr? e)
  (and (list? e)
       (pair? e)
       (andmap (lambda (x) (or (number? x) (member x '(+ - * /))))
               e)))

;; ----------------------
;; Wyrazenia arytmetyczne
;; ----------------------

(struct const (val)    #:transparent)
(struct binop (op l r) #:transparent)

(define (arith-expr? e)
  (match e
    [(const n) (number? n)]
    [(binop op l r)
     (and (symbol? op) (arith-expr? l) (arith-expr? r))]
    [_ false]))

;; ----------
;; Kompilacja
;; ----------

(define (rpn->arith e)
  (define (f e xs)
    (if (null? e)
        (top xs)
        (cond [(number? (car e)) (f (cdr e) (push (const (car e)) xs))]
              [(symbol? (car e))
               (let ([x (top xs)]
                     [y (top (pop xs))])
                     (f (cdr e) (push (binop (car e) x y) (pop (pop xs)))))])))
  (f e empty-stack))
    


      
      

; Mozesz tez dodac jakies procedury pomocnicze i testy