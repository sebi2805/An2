#include <stdio.h>
#include <stdlib.h>

int main()
{ int n, i, sir[100], x, a, b, mij, ok=0;
printf("Dati numarul elementelor sirului: ");
scanf("%d", &n);
printf("Scrieti elementele sirului in ordine crescatoare: \n");
for(i=1;i<=n;i++)
{
    printf("sir[%d]= ", i);
    scanf("%d", &sir[i]);
}
printf("Dati elementul pe care doriti sa il cautati.");
scanf("%d", &x);
a=1;
b=n;
while(ok==0 && a<=b)
{
    mij=(a+b)/2;
    if(x==sir[mij])
    {
        printf("Valoarea a fost gasita pe pozitia %d", mij);
        ok=1;
    }
    else
        if (x<sir[mij])
        b=mij-1;
        else a=mij+1;
}
if(ok==0)
    printf("Valoarea nu a fost gasita");

    printf("\nHello world!\n");
    return 0;
}
