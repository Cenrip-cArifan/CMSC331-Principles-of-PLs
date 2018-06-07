Lex & Yacc

Lex (or the gnu version which is called flex) is a program that takes a set of descriptions of possible tokens and produces a C routine that implements a scanner. Yacc takes a concise description of a grammar and produces a C routine that implements a parser for the grammar.

Lex and yacc are tools which can be used to solve a variety of interesting problems, even outside the realm of compilers. 

If we want to use prefix notation with just one token look ahead, an operator must take a fixed number of arguments. So we can not use the same operator (-) for both binary and unary minus. Instead, we will use the ~ character to represent unary minus. This is one simple change you will have to make.

We will use words for the logical operators: and, or and not and the conditional if. The rules, as they are, will treat these tokens as NAMEs; we want to modify the scanner to treat them as distinct token types. So you will have to modify the file calc.l, to add four new rules, one for each of these strings that will return the appropriate token for which you might use the symbol AND, OR, NOT and IF. Here is an example lex rule you will have to add.
and     { return AND; }

But be careful where you place the rule. The lex rule that recognizes a NAME can also match the sequence 'and'. Since both rules match the same number of characters, the one that comes first will be the one used. We always want to match a keyword like 'and', 'or' and 'not' as a token, so these rules must come before the one that matches a NAME. We do not have the same problem with a token like '<' because that will not be matched by any other rule.

Since we have added new tokens, you have to add a %token declaration for each in the first section of the calc.y file. These four new tokens will not have a type associated with them, so add a declaration like "%token AND". Because we are using a Polish prefix grammar, we do not have to worry about precedence or associativity. However, you can just leave these declarations in the first section of the calc.y file -- they will not cause a problem. You can also delete them.

Don't worry if yacc complains about shift/reduce conflicts so long as the parser works properly. Recall that yacc applies a deterministic resolution to these conflicts (preferring shifts).
