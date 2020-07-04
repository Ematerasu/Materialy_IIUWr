#lang typed/racket
(provide parse typecheck)

(struct const    ([val : Value])                         #:transparent)
(struct binop    ([op : Symbol] [l : Expr] [r : Expr])   #:transparent)
(struct var-expr ([id : Symbol])                         #:transparent)
(struct let-expr ([id : Symbol] [e1 : Expr] [e2 : Expr]) #:transparent)
(struct if-expr ([e : Expr] [et : Expr] [ef : Expr])     #:transparent)

(define-type Expr (U const binop var-expr let-expr if-expr))
(define-type Value (U Number Boolean))
(define-type EType (U 'real 'boolean))

(define-predicate expr? Expr)
(define-predicate value? Value)


;;;Srodowisko;;;;
(struct environ ([xs : (U (Listof (Pairof Symbol (U EType #f))) Null)]))

(define-type Environ environ)

(define env-empty (environ null))

(: env-add (-> Symbol (U EType #f) Environ Environ))
(define (env-add x v env)
  (environ (cons (cons x v) (environ-xs env))))

(: env-lookup (-> Symbol Environ (U EType #f)))
(define (env-lookup x env)
  (: assoc-lookup (-> (U (Listof (Pairof Symbol (U EType False))) Null) (U EType #f))) 
  (define (assoc-lookup xs)
    (cond [(null? xs) (error "Unknown identifier" x)]
          [(eq? x (car (car xs))) (cdr (car xs))]
          [else (assoc-lookup (cdr xs))]))
  (assoc-lookup (environ-xs env)))

;;;;;;

(: typecheck (-> Expr (U EType #f)))
(define (typecheck e)
  (: type-env (-> Expr Environ (U EType #f)))
  (define (type-env e env)
    (match e
      [(const val) (if (number? val)
                     'real
                     'boolean)]
      [(var-expr x) (env-lookup x env)]
      [(binop op l r) (let ([x (type-env l env)]
                            [y (type-env r env)])
                      (if (and (eq? x 'real) (eq? y 'real) (arith-sym? op))
                                             'real
                                             (if (and (eq? x 'real) (eq? y 'real) (compare-sym? op))
                                                 'boolean
                                                 (if (and (eq? x 'boolean) (eq? y 'boolean) (logic-sym? op))
                                                     'boolean
                                                     #f))))]
      [(let-expr x e1 e2) (let ([t (type-env e1 env)])
                            (if (eq? t #f)
                                #f
                                (type-env e2 (env-add x t env))))]
      [(if-expr e et ef) (if (eq? 'boolean (type-env e env))
                             (let ([t (type-env et env)]
                                   [f (type-env ef env)])
                                 (if (eq? t f)
                                     t
                                     #f))
                           #f)]))
  (type-env e env-empty))

(: arith-sym? (-> Symbol Boolean))
(define (arith-sym? x)
  (or (eq? x '+)
      (eq? x '-)
      (eq? x '*)
      (eq? x '/)))

(: compare-sym? (-> Symbol Boolean))
(define (compare-sym? x)
  (or (eq? x '>)
      (eq? x '<)
      (eq? x '>=)
      (eq? x '<=)
      (eq? x '=)))
      

(: logic-sym? (-> Symbol Boolean))
(define (logic-sym? x)
  (or (eq? x 'and)
      (eq? x 'or)))

      
(: parse (-> Any Expr))
(define (parse q)
  (match q
    [_ #:when (value? q)
       (const q)]
    [_ #:when (eq? q 'false)
       (const false)]
    [_ #:when (eq? q 'true)
       (const true)]
    [_ #:when (symbol? q)
       (var-expr q)]
    [`(let (,id ,e1) ,e2) #:when (symbol? id)
     (let-expr id 
               (parse e1)
               (parse e2))]
    [`(,op ,e1 ,e2) #:when (symbol? op)
                    (binop op
                           (parse e1)
                           (parse e2))]
    [`(if ,e ,et ,ef)
     (if-expr (parse e)
              (parse et)
              (parse ef))]))

(typecheck (parse '(+ 1 false)))
(typecheck (parse '(+ 2 3)))
(typecheck (parse '(and true false)))
(typecheck (parse '(+ false true)))
(typecheck (parse '(if (and true true) 1 2)))
(typecheck (parse '(if (and true true) true 2)))
(typecheck (parse '(let (x (+ 2 true)) (if (and true false) 5 (+ 2 3)))))
(typecheck (parse '(let (x (+ 2 3)) (if (= x 5) 5 (+ 2 3)))))
