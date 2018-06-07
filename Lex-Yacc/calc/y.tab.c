#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 9 "calc.y"
 
#include "calc.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/************************************************************************
* Defines a yacc grammar for a simple calculator using prefix
* notation.  WHen executed, the calculator enters a loop in
* which it prints the prompt >>, reads a toplevel expression
* terminated by a newline, and prints its value.  Operators
* include +, -, *, and = (assignment). Note that all
* expressions return values, even assignment.  Parentheses
* can be used to override operator precedence and
* associativity rules. Based on zcalc by ruiz@capsl.udel.edu
************************************************************************/

#line 34 "calc.y"
typedef union {
  double dval;
  struct symtab *symp;
  } YYSTYPE;
#line 47 "y.tab.c"
#define NAME 257
#define NUMBER 258
#define EQ 259
#define GT 260
#define LT 261
#define OR 262
#define AND 263
#define NOT 264
#define IF 265
#define UMINUS 266
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    2,    2,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,
};
short yylen[] = {                                         2,
    0,    3,    1,    1,    1,    1,    1,    3,    4,    3,
    3,    2,    3,    3,    3,    3,    3,    3,    3,    2,
    3,
};
short yydefred[] = {                                      1,
    0,    7,    6,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    4,    5,    0,    0,    3,
    0,    0,    0,    0,    0,    0,   12,    0,    0,    0,
    0,    0,    0,   20,    0,    2,   13,   14,   15,   11,
   10,    0,    8,   17,   16,   18,   19,   21,    9,
};
short yydgoto[] = {                                       1,
   20,   21,
};
short yysindex[] = {                                      0,
  -40,    0,    0,  -31,  -31,  -31,  -31,  -31,  -31,  -31,
 -256,  -31,  -31,  -31,  -31,    0,    0,  -31,  -31,    0,
   -6,  -31,  -31,  -31,  -31,  -31,    0,  -31,  -31,  -31,
  -31,  -31,  -31,    0,  -33,    0,    0,    0,    0,    0,
    0,  -31,    0,    0,    0,    0,    0,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
   27,    0,
};
#define YYTABLESIZE 234
short yytable[] = {                                      19,
   29,   14,   13,   36,   12,   17,   15,   48,   19,    0,
   14,   13,    0,   12,    0,   15,    0,    0,    0,    0,
   11,    0,   16,    0,    0,    0,    0,    0,    0,   11,
   22,   23,   24,   25,   26,   27,   28,    0,   30,   31,
   32,   33,    0,    0,   34,   35,    0,    0,   37,   38,
   39,   40,   41,    0,   42,   43,   44,   45,   46,   47,
    0,    0,    0,    0,    0,    0,    0,    0,   49,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   18,    0,    0,    0,    0,
    0,    0,    0,    0,   18,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    2,    3,    4,    5,
    6,    7,    8,    9,   10,    2,    3,    4,    5,    6,
    7,    8,    9,   10,
};
short yycheck[] = {                                      40,
  257,   42,   43,   10,   45,   46,   47,   41,   40,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   61,   -1,   63,   -1,   -1,   -1,   -1,   -1,   -1,   61,
    4,    5,    6,    7,    8,    9,   10,   -1,   12,   13,
   14,   15,   -1,   -1,   18,   19,   -1,   -1,   22,   23,
   24,   25,   26,   -1,   28,   29,   30,   31,   32,   33,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   42,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  126,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  126,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,  262,  263,  264,  265,  257,  258,  259,  260,  261,
  262,  263,  264,  265,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 266
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'","'.'","'/'",0,0,0,0,0,0,0,0,0,
0,0,0,0,"'='",0,"'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'~'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"NAME","NUMBER","EQ","GT","LT","OR","AND","NOT","IF","UMINUS",
};
char *yyrule[] = {
"$accept : session",
"session :",
"session : session toplevel '\\n'",
"toplevel : expr",
"toplevel : '?'",
"toplevel : '.'",
"expr : NUMBER",
"expr : NAME",
"expr : '=' NAME expr",
"expr : IF expr expr expr",
"expr : AND expr expr",
"expr : OR expr expr",
"expr : NOT expr",
"expr : EQ expr expr",
"expr : GT expr expr",
"expr : LT expr expr",
"expr : '+' expr expr",
"expr : '-' expr expr",
"expr : '*' expr expr",
"expr : '/' expr expr",
"expr : '~' expr",
"expr : '(' expr ')'",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 114 "calc.y"

struct symtab *
symlook(s)
char *s;
{
   char *p;
   struct symtab *sp;

   /* given the name of a symbol, scan the symbol table and
      either return the entry with matching name or add it
      to the next free cell in the symbol table. */

   for(sp = symtab; sp < &symtab[SYMBOLTABLESIZE]; sp++) {

     /* If the symbol table entry has a name and its equal
	to the one we are looking for, return this entry */
     if (sp->name && !strcmp(sp->name, s))
       return sp;

     /* If the name is empty then this entry is free, so the
	symbol must not be in the table and we can add it here
        and return this entry. */
     if (!sp->name) {
       sp->name = strdup(s);
       return sp;
       }
   }

   /* We searched the entire symbol table and neither found
      the symbol or an unused entry.  So the table must be
      full.  Sigh. */
   yyerror("The symbol table is full, sorry...\n");
   exit(1);
}



void printHelp() 
{ /* print calculator help and return */
  printf("Enter an expression in prefix notation followed by a newline.\n");
  printf("Operators include +, -, * and =.  Defined functions include\n");
  printf("sqrt, exp and log.  You can assign a variable using the =\n");
  printf("operator. Type . to exit.  Syntax errors will terminate the\n");
  printf("program, so be careful.\n");
}


/* If error prints error and Do not accept to signify bad syntax in
   program */

void yyerror(char *msg)	/* yacc error function */
{
  printf("%s \n" , msg);  
}

main()
{ /* print herald and call parser */
  printf("331 Calculator\n(type ? for help and . to exit)\n\n>> ");
  yyparse();
}
#line 284 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 3:
#line 91 "calc.y"
{ printf("%g\n\n>> ", yyvsp[0].dval); }
break;
case 4:
#line 92 "calc.y"
{ printHelp(); printf("\n>> "); }
break;
case 5:
#line 93 "calc.y"
{ printf("Exiting 331 calc\n"); exit(1); }
break;
case 6:
#line 96 "calc.y"
{ yyval.dval = yyvsp[0].dval; }
break;
case 7:
#line 97 "calc.y"
{ yyval.dval = yyvsp[0].symp->value; }
break;
case 8:
#line 98 "calc.y"
{ yyvsp[-1].symp->value = yyvsp[0].dval; yyval.dval = yyvsp[0].dval; }
break;
case 9:
#line 99 "calc.y"
{ if(yyvsp[-2].dval == 1) yyval.dval = yyvsp[-1].dval; else yyval.dval = yyvsp[0].dval; }
break;
case 10:
#line 100 "calc.y"
{ yyval.dval = yyvsp[-1].dval && yyvsp[0].dval; }
break;
case 11:
#line 101 "calc.y"
{ yyval.dval = yyvsp[-1].dval || yyvsp[0].dval; }
break;
case 12:
#line 102 "calc.y"
{ yyval.dval = !yyvsp[0].dval; }
break;
case 13:
#line 103 "calc.y"
{ yyval.dval = yyvsp[-1].dval == yyvsp[0].dval; }
break;
case 14:
#line 104 "calc.y"
{ yyval.dval = yyvsp[-1].dval > yyvsp[0].dval; }
break;
case 15:
#line 105 "calc.y"
{ yyval.dval = yyvsp[-1].dval < yyvsp[0].dval; }
break;
case 16:
#line 106 "calc.y"
{ yyval.dval = yyvsp[-1].dval + yyvsp[0].dval; }
break;
case 17:
#line 107 "calc.y"
{ yyval.dval = yyvsp[-1].dval - yyvsp[0].dval; }
break;
case 18:
#line 108 "calc.y"
{ yyval.dval = yyvsp[-1].dval * yyvsp[0].dval; }
break;
case 19:
#line 109 "calc.y"
{ yyval.dval = yyvsp[-1].dval / yyvsp[0].dval; }
break;
case 20:
#line 110 "calc.y"
{ yyval.dval = -yyvsp[0].dval; }
break;
case 21:
#line 111 "calc.y"
{ yyval.dval = yyvsp[-1].dval; }
break;
#line 541 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
