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
typedef union {
  double dval;
  struct symtab *symp;
  } YYSTYPE;
extern YYSTYPE yylval;
