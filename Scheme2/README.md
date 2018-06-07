Scheme 2

Problem 1: An Enigma

Complete the comment so it describes in a sentence or two what the following function does and what kind of argument it should be called with to avoid getting a run time error.

(define (enigma x)

  ;; the enigma function ...
  
  (or (null? x)
  
      (null? (rest x))
      
      (and (not (equal? (car x) (car (cdr x))))
      
           (enigma (rest x)))))
           
Hint: it you can't see what enigma does by inspection, load it into a Scheme interpreter and experiment with it. If it is obvious from the code what it does, it's still wise to load it into Scheme and verify your theory.


Problem 2: A conundrum

Complete the comment so it describes in a sentence or two what the following function does and what kind of argument it should be called with to avoid getting a run time error.

(define (conundrum x y)

  ;; The amazing function conundrum ...
  
  (cond ((null? y) -1)
  
        ((equal? x (first y)) 0)
        
        (else (let ((z (conundrum x (rest y))))
        
                   (if (< z 0) z (+ 1 z))))))
                   
Recall that the let is used to create an environment with new local variables and to initially bind them to particular values. Let evaluates the expressions for the initial values outside the environment and then creates the new local variables and makes the initial assignments. A typical example is creating a local variable TEMP used to swap the values of two other variables, A and B:

(let ((temp #f)) 

   (set! temp a)
   
   (set! a b)
   
   (set! b temp))
   
Note that we might simplify this as follows:

(let ((temp a)) 

   (set! a b)
   
   (set! b temp))
   
   
Problem 3: lambda expressions 

Write lambda expressions that evaluate to the functionality described below, and assign each to the symbols do-nothing, first-str, and converse-func respectively. (In other words, do not use the (define (func arg1 arg2) ...) convenience form.) For example, your solution to question 3.1 below must start with:

    (define do-nothing
      (lambda ...
      
3.1 do-nothing: a function that takes no arguments and always returns 0

3.2 first-str: a function that takes two strings and returns the one that should occur first in a alphabetic ordering. (Hint: the builtin function string<? will be helpful.)

3.3 converse-func: a function that takes a single argument, F, that is a predicate function and returns a new function that is F's converse. Whenever the predicate F is true for some argument, its converse will be false and whenever F is false, its converse will be true. (Hints: the answer is simple and will have the form (define converse-func (lambda (some-func) ...)). NB: Since your function will return a function, you will need a lambda inside a lambda! Since you don't know how many arguments F will take (and might in fact take a variable number) you will have to use apply and the syntax for defining a lambda expression that takes any number of arguments -- e.g., ((lambda X (apply + (map square X))) 1 2 3 4) returns 30.

Be sure to test your lambda expression in the Scheme interpreter. Here is an example of a lambda expression that takes a single numberic argument and returns a value that is one more:

(lambda (n) (+ n 1))

and this shows how you would call it:

> ((lambda (n) (+ n 1)) 100)

101

Or:

(define s (lambda (n) (+ n 1)))

> (s 100)

101 


Problem 4: unique-atoms

Write a function unique-atoms that takes an arbitrary s-expression and returns a list of the unique atoms in it. The order of the atoms in the list is not important.

> (unique-atoms '(a (b) b ((c)) (a (b))))

(a c b)

> (unique-atoms '(a . a))

(a)

> (unique-atoms '())

()

Hint: Start by writing a function atoms that takes an s-expression and returns a list of all of the atoms in it. Then write a function unique-members that takes a list and returns a list of the unique top-level elements of the list. Once you have these two, you are almost done.


Problem 5: Tricky Lisp

Write a function called 'reverse-tree that will invert an entire list, recursively reversing any sublists. Some examples:

;; A simple list:

(reverse-tree '(A B C))

'(C B A)

;; A nested list:

(reverse-tree '(A (X Y Z) B C))

'(C B (Z Y X) A)

;; And the most complex example:

(reverse-tree '(A B (P Q R (X Y Z) (1 2 3) ()) D E (((F) G) H)))

'((H (G (F))) E D (() (3 2 1) (Z Y X) R Q P) B A)

Notice that you must be able to handle null sublists, as in the third example above, but you do *not* have to handle dotted pairs (after all, what would the reverse of '(1 2 . 3) even be?).

Note that you cannot just define 'reverse-tree to be another name for 'reverse: that function only operates on the top level list, and not on sublists. However, 'reverse would be a useful helper function to call from inside your function.

Sound simple enough? Here's the catch: I'm adding a few extra restrictions to make it more interesting. First, you can only define the one function -- 'reverse-tree; furthermore, you cannot use the 'lambda special form inside. Second, you can only use the following small set of functions:

reverse

map

if

cond

list?

null?

You do not have to use all of them.

The fact that all of the list-deconstructing and -constructing functions like 'cons', 'car', 'cdr', 'first', 'rest', 'append', etc. are left out implies that you cannot use the usual tail-recursive method that we have been predominantly using in class, where you operate on the first element and recurse on the rest of the list. Here, you need to use a different pattern that feels more like operating on the entire list at the same time. (Hint: refresh yourself on what the 'map function does.) A bit of good news: the entire solution will fit on one 80-character line (but you should break it into multiple lines for nice formatting).

Run code:

./scheme6 -t hw7test.ss
