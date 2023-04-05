%option noyywrap
%{
	#include<stdio.h>
	int lc=0,tc=0,ch=0,sc=0;
%}

%%
[\n]	lc++;
\t	tc++;
[ ]	sc++;
.	ch++;
%%
int main()
{
yylex();
printf("Line count=%d\n",lc);
printf("Tab count=%d\n",tc);
printf("character count=%d\n",ch);
printf("Space count=%d\n",sc);
return 0;
}
