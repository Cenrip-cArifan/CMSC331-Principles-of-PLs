Lexical Scanner in C++

Part a.

Write a program in Java, Python, or C/C++ that reads in a single character at a time, 
and when it reaches end-of-file, reports whether it has read in a decimal, octal, or 
hexadecimal number, and what that number is (as a string), 
or "NONSENSE" if it isn't a well-formed number. 

Part b.

Develop a lexical scanner for Anaconda integers using the Unix utility Lex or Flex. 
The file scanner.l is the input to lex. Running make with the Makefile will use lex to create 
scanner.c and compile this to produce an executable named scanner. 
Invoking this with a simple file input will produce this session.

When compiling and executing to test scanner.l and lexical.cpp in linux environment
either run:

> make

which outputs:

lex  -o scanner.c scanner.l

cc -o scanner scanner.c -lfl

then run:

> scanner < input

or if it's already up-to-date, run:

> lex  -o scanner.c scanner.l
> cc -o scanner scanner.c -lfl
> scanner < input

the results should be the same as the one in the session file
