#include <stdio.h>
#include <stdlib.h>

int main()
{
    int min, i, j, sir[100], aux,n;
    printf("Dati numarul elementor sirului: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("sir[%d]= ",i);
        scanf("%d", &sir[i]);
    }
    for (i=0;i<n-1;i++)
    {
        min=i;
        for (j=i+1;j<n;j++)
            if (sir[j]>sir[min])
                min=j;
        if (sir[min]>sir[i])
        {
            aux=sir[min];
            sir[min]=sir[i];
            sir[i]=aux;
        }
    }

    printf("Sirul ordonat descrescator este: ");
    for(i=0;i<n;i++)
        printf("%d ", sir[i]);
    return 0;
}
