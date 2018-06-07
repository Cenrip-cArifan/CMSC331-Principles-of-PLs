Scheme

Problem 1: chop and unchop

You will write a pair of complementary Scheme functions named chop and unchop. Chop takes a proper list L with at least one element and returns a list like L but without it's last element. (recall that a proper list is one that ends in a null.) Unchop takes two arguments, a proper list L (possibly empty) and an arbitrary s-expression X and returns a list like L but with X added as it's last element. Here is an example of their use.

gl3% mzscheme

Welcome to Racket v5.1.3.

> (load "hw6.ss")

> (chop '(1 2 3))

(1 2)

> (chop '(1))

()

> (chop '())

cdr: expects argument of type <pair>; given ()

=== context ===

/Users/Park/Sites/331s13/hw/hw6/hw6.ss:7:0: chop

/opt/racket/collects/racket/private/misc.rkt:85:7

> (unchop '() 100)

(100)

> (unchop '(1 2 3) 'infinity)

(1 2 3 infinity)

> (unchop '(1 2 3) '(47))

(1 2 3 (47))

(Note: there is an error message shown in the example above. Your own code might produce a completely different error message, depending on your implementation.)


Problem 2: shift-left and shift-right

Write functions shift-left and shift-right that take a single argument that is assumed to be a list, possibly empty. Shift-left and returns a new list like its argument but with first element moved to the end of the list. Shift right returns a new list with the last element moved to the front. Here are some examples:

> (shift-left '(1 2 3))

(2 3 1)

> (shift-left '(1))

(1)

> (shift-left '())

()

> (shift-left (shift-left '(1 2 3)))

(3 1 2)

> (shift-right '(1 2 3))

(3 1 2)

> (shift-right '(1))

(1)

> (shift-right '())

()

> (shift-right (shift-right '(a b c)))

(b c a)


Problem 3: zipper?, zip and unzip

a) Let's define a zipper as a proper list where each element is itself a list with exactly two elements which can be any expressions. Write a function zipper? that returns #t if its single argument is a zipper and #f if it is not, like so:

> (zipper? '((a 1)(b 2)))

#t

> (zipper? '((foo 100)(bar 2 3)))

#f

> (zipper? '((a 1) b (c 3)))

#f

> (zipper? '((a 1) . 2))

#f

> (zipper? '((a (1)) ((b) 2)))

#t

b) Next, write a function zip that takes any two proper lists and creates a zipper out of them, pairing up elements from the first and second arguments. If the either of the two lists is shorter than the other, use null for the missing elements. Here are some examples:

> (zip '(a b c) '(1 2 3))

((a 1) (b 2) (c 3))

> (zip '(a b c) '(1))

((a 1) (b ()) (c ()))

> (zip '(a b) '(1 2 3))

((a 1) (b 2) (() 3))

> (zip '() '())

()

c) Lastly, write a function unzip that reverses the process, taking a zipper and returning a list of two lists. Again, some examples:

> (unzip '((a 1)(b 2)(c 3)))

((a b c) (1 2 3))

> (unzip '())

(() ())


Run the code:

> mzscheme -t hw6test.ss
