%{
#include<stdio.h>
#include<stdlib.h>
extern int yylex(void);
void yyerror(char *);
%}
%token INT
%left '+''-'    
%left '*''/'
%left '('')'
%%

S: E {printf("\n value of the arithmetic expression is=%d",$$);exit(0);}
 E:|E'+'E {$$=$1+$3;}
   |E'-'E {$$=$1-$3;}
   |E'*'E {$$=$1*$3;}
   |E'/'E  {$$=$1/$3;}
   |'('E')' {$$=$2;}
   |INT {$$=$1;}
   ;
%%
void yyerror(char *s)
{
printf("%s",s);
exit(0);
}
int main()
{
printf("\n Enter the expression:");
yyparse();
return 0;
}

