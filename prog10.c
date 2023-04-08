#include <stdio.h>
#include <string.h>

void pm();
void plus();
void div();
void reverse(char* str);

int i, j, l;
char ex[100], exp1[100],expr[100],exper[100];

int main()
{
    printf("\nEnter the expression with arithmetic operator:");
    scanf("%s", ex);
    strcpy(expr, ex);
    l = strlen(expr);

    for (i = 0; i < l; i++)
    {
        if (expr[i] == '+' || expr[i] == '-')
        {
            if (expr[i+2] == '/' || expr[i+2] == '*')
            {
                pm();
                break;
            }
            else
            {
                plus();
                break;
            }
        }
        else if (expr[i] == '/' || expr[i] == '*')
        {
            div();
            break;
        }
    }
    return 0;
}

void pm()
{
    reverse(expr);
    j = l - i - 1;
    strncat(exp1, expr, j);
    reverse(exp1);
    printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n", exp1, expr[j+1], expr[j]);
}

void div()
{
    strncat(exp1, expr, i+2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", exp1, expr[i+2], expr[i+3]);
}

void plus()
{
    strncat(exp1, expr, i+2);
    reverse(exp1);
    strncat(exper,exp1,3);
    reverse(exper);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", exper, expr[i+2], expr[i+3]);
}

void reverse(char* str)
{
    char temp;
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
