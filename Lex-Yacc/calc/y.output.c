   0  $accept : session $end

   1  session :
   2          | session toplevel '\n'

   3  toplevel : expr
   4           | '?'
   5           | '.'

   6  expr : NUMBER
   7       | NAME
   8       | '=' NAME expr
   9       | IF expr expr expr
  10       | AND expr expr
  11       | OR expr expr
  12       | NOT expr
  13       | EQ expr expr
  14       | GT expr expr
  15       | LT expr expr
  16       | '+' expr expr
  17       | '-' expr expr
  18       | '*' expr expr
  19       | '/' expr expr
  20       | '~' expr
  21       | '(' expr ')'

state 0
	$accept : . session $end  (0)
	session : .  (1)

	.  reduce 1

	session  goto 1


state 1
	$accept : session . $end  (0)
	session : session . toplevel '\n'  (2)

	$end  accept
	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'?'  shift 16
	'.'  shift 17
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 20
	toplevel  goto 21


state 2
	expr : NAME .  (7)

	.  reduce 7


state 3
	expr : NUMBER .  (6)

	.  reduce 6


state 4
	expr : EQ . expr expr  (13)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 22


state 5
	expr : GT . expr expr  (14)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 23


state 6
	expr : LT . expr expr  (15)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 24


state 7
	expr : OR . expr expr  (11)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 25


state 8
	expr : AND . expr expr  (10)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 26


state 9
	expr : NOT . expr  (12)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 27


state 10
	expr : IF . expr expr expr  (9)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 28


state 11
	expr : '=' . NAME expr  (8)

	NAME  shift 29
	.  error


state 12
	expr : '-' . expr expr  (17)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 30


state 13
	expr : '+' . expr expr  (16)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 31


state 14
	expr : '*' . expr expr  (18)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 32


state 15
	expr : '/' . expr expr  (19)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 33


state 16
	toplevel : '?' .  (4)

	.  reduce 4


state 17
	toplevel : '.' .  (5)

	.  reduce 5


state 18
	expr : '~' . expr  (20)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 34


state 19
	expr : '(' . expr ')'  (21)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 35


state 20
	toplevel : expr .  (3)

	.  reduce 3


state 21
	session : session toplevel . '\n'  (2)

	'\n'  shift 36
	.  error


state 22
	expr : EQ expr . expr  (13)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 37


state 23
	expr : GT expr . expr  (14)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 38


state 24
	expr : LT expr . expr  (15)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 39


state 25
	expr : OR expr . expr  (11)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 40


state 26
	expr : AND expr . expr  (10)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 41


state 27
	expr : NOT expr .  (12)

	.  reduce 12


state 28
	expr : IF expr . expr expr  (9)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 42


state 29
	expr : '=' NAME . expr  (8)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 43


state 30
	expr : '-' expr . expr  (17)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 44


state 31
	expr : '+' expr . expr  (16)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 45


state 32
	expr : '*' expr . expr  (18)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 46


state 33
	expr : '/' expr . expr  (19)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 47


state 34
	expr : '~' expr .  (20)

	.  reduce 20


state 35
	expr : '(' expr . ')'  (21)

	')'  shift 48
	.  error


state 36
	session : session toplevel '\n' .  (2)

	.  reduce 2


state 37
	expr : EQ expr expr .  (13)

	.  reduce 13


state 38
	expr : GT expr expr .  (14)

	.  reduce 14


state 39
	expr : LT expr expr .  (15)

	.  reduce 15


state 40
	expr : OR expr expr .  (11)

	.  reduce 11


state 41
	expr : AND expr expr .  (10)

	.  reduce 10


state 42
	expr : IF expr expr . expr  (9)

	NAME  shift 2
	NUMBER  shift 3
	EQ  shift 4
	GT  shift 5
	LT  shift 6
	OR  shift 7
	AND  shift 8
	NOT  shift 9
	IF  shift 10
	'='  shift 11
	'-'  shift 12
	'+'  shift 13
	'*'  shift 14
	'/'  shift 15
	'~'  shift 18
	'('  shift 19
	.  error

	expr  goto 49


state 43
	expr : '=' NAME expr .  (8)

	.  reduce 8


state 44
	expr : '-' expr expr .  (17)

	.  reduce 17


state 45
	expr : '+' expr expr .  (16)

	.  reduce 16


state 46
	expr : '*' expr expr .  (18)

	.  reduce 18


state 47
	expr : '/' expr expr .  (19)

	.  reduce 19


state 48
	expr : '(' expr ')' .  (21)

	.  reduce 21


state 49
	expr : IF expr expr expr .  (9)

	.  reduce 9


23 terminals, 4 nonterminals
22 grammar rules, 50 states
