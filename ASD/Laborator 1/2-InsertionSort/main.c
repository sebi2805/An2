#include <stdio.h>
#include <stdlib.h>

int main()
{ int n,i,sir[100],j, aux, val;
printf("Dati nr elementelor sirului: ");
scanf("%d", &n);
for(i=0;i<n;i++)
{
    printf("sir[%d]= ",i);
    scanf("%d", &sir[i]);
}
{
    for (i = 1; i < n; i++)
    {
        j = i;
        val = sir[i];
        while (j > 0 && sir[j - 1] > val)
        {
            sir[j] = sir[j - 1];
            j--;
        }
        sir[j] = val;
    }
}

 printf("Sirul ordonat crescator este: ");
 for(i=0;i<n;i++)
    printf("%d ", sir[i]);
    return 0;
}
