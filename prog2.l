%{
#include<stdio.h>
#include "y.tab.h"
void yyerror(char *);
extern int yylval;
%}
%%
[0-9]+ { yylval=atoi(yytext);return INT;}
[-*+/] { return yytext[0];}
[)] { return yytext[0];}
[(] { return yytext[0];}
[ \t]+ {;}
\n { return 0;}
. { yyerror("Enter valid expression");}
%%

