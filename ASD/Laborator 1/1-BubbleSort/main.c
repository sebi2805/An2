#include <stdio.h>
#include <stdlib.h>

int main()
{ int sir[100], i, ok, n, aux;
printf("Dati numarul elementelor sirului: ");
scanf("%d", &n);
for(i=0;i<n;i++)
{
    printf("sir[%d]= ", i)
    scanf("%d", &sir[i]);
}
ok=0;
while(ok==0)
{ok=1;
    for(i=0;i<n-1;i++)
    {
        if(sir[i]>sir[i+1])
        {   aux=sir[i];
            sir[i]=sir[i+1];
            sir[i+1]=aux;
            ok=0;
        }
    }
}
    printf("Sirul ordonat crescator este: ");
    for(i=0;i<n;i++)
        printf("%d ", sir[i]);
    return 0;
}
