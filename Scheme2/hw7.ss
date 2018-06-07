#lang scheme
;; UMBC CMSC 331 Fall 2017, HW7, Gabriel Kilungya, kilgab1@UMBC.EDU

(define (pass) null)

;; (1) Enigma: put your answer to problem one as a comment here.  User
;; as many lines as you need

(define (enigma x)
  ;; the enigma function ...
  ;; this function takes in a proper list
  ;; checks to see if the list is null or the rest of the list is null
  ;; and check if elements side-by-size are the same
  ;; if the same, return #t, otherwise return #f
  ;; note an empty list null is considered, even (null null) returns #f
  (or (null? x)
      (null? (rest x))
      (and (not (equal? (car x) (car (cdr x))))
           (enigma (rest x)))))

;; (2) connumdrum put your answer to problem two as a comment here.
;; User as many lines as you need.

(define (conundrum x y)
  ;; The amazing function conundrum ...
  ;; If  y is null return -1
  ;; else if y contains x return how many elements before it reaches x
  ;; otherwise return -1
  (cond ((null? y) -1)
        ((equal? x (first y)) 0)
        (else (let ((z (conundrum x (rest y))))
                   (if (< z 0) z (+ 1 z))))))


;; (3.1) Replace ONLY the commented with your actual implementation,
;; W/O CHANGING THE FIRST LINE!

(define do-nothing
  ;;a function that takse no arguments
  ;;and always return 0
  (lambda () 0)
  )

;; (3.2) Replace ONLY the commented with your actual implementation,
;; W/O CHANGING THE FIRST LINE!

(define first-str
  ;; a function that takes two strings and returns 
  ;; the one that should occur first in a alphabetic ordering. 
  ;; (Hint: the builtin function string<? will be helpful.)
  (lambda (s1 s2)
        (cond
        [(string<? s1 s2) s1]
        [else s2]))

  )

;; (3.3) Replace ONLY the commented with your actual implementation,
;; W/O CHANGING THE FIRST LINE!

(define converse-func
  ;; a function that takes a single argument, F, that is a predicate function 
  ;; and returns a new function that is F's converse. 
  ;; Whenever the predicate F is true for some argument, 
  ;; its converse will be false 
  ;; and whenever F is false, its converse will be true.
  (lambda (some-func)
        (lambda F
        (not (apply some-func F))))
  )

;; complete the following as answers to the remaining problems.  add
;; as many additional functions as needed.  Please add appropriate
;; comments to your functions.

;; (4) unique-atoms

(define (atoms x)
  ;; given a s-expression x, return a list of all of the atoms in it
  ;; if the list is null, return null
  ;; create a local variable z, and set it to the cdr of x and evaluate the rest of the cdr of x
  ;; nested if: if z is a list append the first element and the rest of the elements to end of list
  ;; return the new list with all of the atoms in it
        (if (null? x) null
                (let ((z (car x))
                        (rest (cdr x)))
                (if (list? z)
                        (append (atoms z) (atoms rest))
                        (cons z (atoms rest)))))

)

(define (unique-atoms s)

  ;; given an s-expression s, returns a list of the unique atoms in s.
  ;; The order is not important.  e.g.: (unique-atoms? '(a a)) => (a),
  ;; (unique-atoms? '(a (b (c (a))))) => (a b c), (unique-atoms? '())
  ;; => ()
  
  ;; create two local environments with new local variables and bind them to particular values
  ;; if the local variable y is empty, reverse rest of the list
  ;; bind the nested local variable x to the car of y and recursively call local function atom's cdr
  ;; if x is a member in the rest of the list then return a new list with all the atoms in it
  (let atom((y (atoms s)) (rest '()))
    (if (empty? y)
	(reverse rest)
	(let ((x (car y)))
	  (atom (cdr y)
		(if (member x rest) rest (cons x rest))))))
)  


;; (5) reverse-tree

(define (reverse-tree s)
  ;; given an s-expression s, returns the complete reversal of that
  ;; s-expression: not only the top-level list, but every nested sub-list,
  ;; is reversed.
  ;; So, "(reverse-tree '(a b (c d) (e (f g h))))" will yield:
  ;; '(((h g f) e) (d c) b a)

  ;; check to see if s is a proper list
  ;; if s is a list, map the function and s
  ;; map built-in function will map the entire list including sublists approriately
  ;; and then reverse it, then return the list
 (if (list? s)
     (reverse (map reverse-tree s)) s)
)

(provide
  enigma conundrum
  do-nothing first-str converse-func
  unique-atoms
  reverse-tree)