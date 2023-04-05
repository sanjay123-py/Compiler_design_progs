#include <stdio.h>
#include <string.h>
#include<time.h>
int z, i, j, c;
char a[16], stk[15];

void reduce();

int main() {
    clock_t begin, end;
    double time_taken;
    begin = clock();
    puts("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->a");
    puts("enter input string ");
    gets(a);
    c = strlen(a);
    a[c] = '$';
    stk[0] = '$';
    puts("stack \t input \t action");

    for (i = 1, j = 0; j < c; i++, j++) {

            stk[i] = a[j];
            stk[i+1] = '\0';
            a[j] = ' ';
            printf("\n%s\t%s\tshift->%c", stk, a, stk[i]);
            reduce();
    }

    if (a[j] == '$')
        reduce();

    if ((stk[1] == 'E') && (stk[2] == '\0'))
        printf("\n%s\t%s\tAccept", stk, a);
    else
        printf("\n%s\t%s\terror", stk, a);

    end = clock(); 
    time_taken = (double)(end-begin) / CLOCKS_PER_SEC; 
    printf("\n\nTime taken: %f", time_taken);
}

void reduce() {
    for (z = 1; z <= strlen(stk); z++)
        if (stk[z] == 'a') {
            stk[z] = 'E';
            stk[z+1] = '\0';
            printf("\n%s\t%s\tReduce by E->a", stk, a);
        }

    for (z = 1; z <= strlen(stk); z++)
        if (stk[z] == 'E' && stk[z+1] == '+' && stk[z+2] == 'E') {
            stk[z] = 'E';
            stk[z+1] = '\0';
            stk[z+2] = '\0';
            printf("\n%s\t%s\tReduce by E->E+E", stk, a);
            i = i - 2;
        }

    for (z = 1; z <= strlen(stk); z++)
        if (stk[z] == 'E' && stk[z+1] == '*' && stk[z+2] == 'E') {
            stk[z] = 'E';
            stk[z+1] = '\0';
            stk[z+2] = '\0';
            printf("\n%s\t%s\tReduce by E->E*E", stk, a);
            i = i - 2;
        }

    for (z = 1; z <= strlen(stk); z++)
        if (stk[z] == '(' && stk[z+1] == 'E' && stk[z+2] == ')') {
            stk[z] = 'E';
            stk[z+1] = '\0';
            stk[z+2] = '\0';
            printf("\n%s\t%s\tReduce by E->(E)", stk, a);
            i = i - 2;
        }
}