"""
   File: Scanner.l
   Name: Gabriel Kilungya
   Date: 10/6/2017
   Email: kilgab1@umbc.edu
"""


/*
 A scanner for a Anaconda integers. Outputs lines like
 "token: lexeme", for example "decimal_integer: +12".
*/

%option noyywrap

%{
%}

/* your definitions go here */

OCT [-+]?[0][0]|[-+]?[0][1-7]*

DECIMAL [-+]?[0]|[-+]?[1-9][0-9]*

HEX [-+]?[0][xX][0]|[-+]?[0][xX][0][1-9A-Fa-f][0-9A-Fa-f]*|[-+]?[0][xX][1-9A-Fa-f][0-9A-Fa-f]*


%%

"/* your rules go here */"

^{DECIMAL}$           printf("decimal_int: %s\n", yytext);
^{OCT}$               printf("octal_int: %s\n", yytext);
^{HEX}$               printf("hex_int: %s\n", yytext);

"#".*\n               printf("COMMENT: %s", yytext);
[ \t\n]+              /* skip space, tab and newline */
.                     printf("ignore: %s\n", yytext);

%%

main(argc, argv)
  int argc; char **argv;
  { 
    if (argc>1) yyin=fopen(argv[1],"r"); else yyin=stdin;
    yylex();
  }

