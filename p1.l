%{
#include<stdio.h>
%}
%%

\n {printf("Hello world how are you");};
%%

int yywrap(void)
{
return 1;
}
int main()
{
yylex();
return 0;
}
