#lang racket
;; CMSC 331 Spring 2012 hw6.ss, Gabriel Kilunga, kilgab1@UMBC.EDU

(define (PASS . ARGS)
  ;; This is a a dummy function that takes any number of arguments and
  ;; always returns null.  You should replace calls to it with your
  ;; own scheme code.
  null)

;; problem one: chop and unchop

(define (chop l)
  ;; chop takes a proper list l with at least one element and returns
  ;; one like it with the last element removed.
  ;; Examples: (chop '(1 2))=>(1), (chop '(1))=>()
  (reverse (cdr (reverse l)))

)

(define (unchop l x)
  ;; unchop takes two arguments, a proper list L(possibly empty)
  ;; an arbitrary s-expression X and returns a list L but with X added
  ;; as it's last element
  ;; Examples: (unchop '() 100)=>(100), (unchop '(1 2 3) '(47))=>(1 2 3 (47))
  (reverse (cons x (reverse l)))  
)

;; problem two: shift-right and shift-left

(define (shift-right l)
  ;; shift-right takes a single argument, assumed to a list, possibly empty
  ;; returns a new list with the last element moved to the front
  ;; Exmaples: (shift-right '())=>(), (shift-right '(1 2 3))=>(3 1 2)
  (if (or (null? l) (null? (cdr l)))
      l
      (append (cons (car (reverse l)) '()) (reverse (cdr (reverse l)))))
  )

(define (shift-left l)
  ;; shift-left takes a single argument, assumed to a list, possibly empty
  ;; returns a new list with the first element moved to the end of the list
  ;; Examples: (shift-left '(1))=>(1), (shift-left '(1 2 3))=>(2 3 1)
  (if (or (null? l) (null? (cdr l)))
      l
      (append (cdr l) (cons (car l) '())))  
  )

;; problem three: zipper?, zip and unzip

(define (zipper? l)
  ;; a proper list where each element is a list with exactly two elements
  ;; which can be any expressions
  ;; returns #t if its single argument is a zipper, otherwise #f
  ;; Examples: (zipper? '((a 1) b (c 3)))=>#f, (zipper? null)=>#t
  (cond
   ((null? l) #t)
   ((not (list? l)) #f)
   ((not (list? (car l))) #f)
   ((not (= (length (car l)) 2)) #f)
   (else(zipper? (cdr l))))
  )

(define (zip l1 l2)
  ;; takes any two proper lists and creates a zipper out of them, pairing up 
  ;; elements from the first and second argument
  ;; if either of two lists is shorter than the other, use null for missing
  ;; elements
  ;; Examples: (zip '(a b) '(1 ))=>((a 1)(b ())), (zip '(a) '(1))=>((a 1))

  (define (uneven-car l1)
    (if (null? l1) null (car l1)))
  (define (uneven-cdr l1)
    (if (null? l1) l1 (cdr l1)))
  
  (let recur ((l1 l1) (l2 l2) (rest '()))
    (if (and (null? l1) (null? l2))
	(reverse rest)
	(recur (uneven-cdr l1) (uneven-cdr l2)
	       (cons (list (uneven-car l1) (uneven-car l2)) rest))))  
  )

(define (unzip l) 
  ;; reverses the process, taking a zipper and returning a list of two lists 
  ;; Examples: (unzip null)=>(() ()), (unzip '((a 1)(b ())))=>((a 1)(() 2))
  (list (map first l) 
          (map second l))
)


(provide chop unchop
	  shift-left shift-right
	   zipper? zip unzip)