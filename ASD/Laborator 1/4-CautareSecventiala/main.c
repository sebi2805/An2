#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, sir[100], x;
    printf("Dati numarul elementelor sirului: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("sir[%d]= ", i);
        scanf("%d", &sir[i]);
    }
    printf("Dati elementul pe care doriti sa il cautati in sir: ");
    scanf("%d", &x);
    i=0;
    while (i<n) {
        if(sir[i]==x)
            printf("Elementul %d a fost gasit pe pozitia %d", x, i);
        i++;
    }
   // if(i==n)
   // printf("Elementul %d nu a fost gasit", x);





return 0;
}
