#include <stdio.h>
#include <stdlib.h>

struct stiva
{
    int poz;
    char chr;
} v[1000];

int main()
{
    //5
    char c;
    int top = 0,n,i = 0,ok = 1;
    scanf("%d",&n);
    scanf("%c",&c);
    while(n-- && ok)
    {
        scanf("%c",&c);
        i++;
        if(top == 0)
        {
            if(c == ')')

ok=0;


                else v[++top].chr = c;
        }
        else
        {
            if(v[top].chr == '(' && c == ')') top--;
            else v[++top].chr = c;
        }
    }
    if(ok == 0) printf("\nPrima parateza care nu are corespondent se afla pe pozitia %d",i);
    else
    {
        if(top) printf("\nPrima parateza care nu are corespondent se afla pe pozitia %d",i);
        else printf("\nParantezare corecta\n");
    }
    return 0;
}
