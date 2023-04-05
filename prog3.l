%{
#include<stdio.h>
#include <ctype.h>
#include"y.tab.h"
void yyerror(char *s);
extern int yylval;
%}
digit [0-9]
%%
{digit}+ { yylval=atoi(yytext);return NUM; }
[a-z] { yylval=toascii(yytext[0])-97;
       return ID;}
[A-Z]  { yylval=toascii(yytext[0])-65;
      return ID;}
[-+*/=\n] { return yytext[0];}
[(] { return yytext[0];}
[)] { return yytext[0];}
. { yyerror("syntax error"); }
%%

