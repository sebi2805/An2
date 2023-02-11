#include <stdio.h>
#include <stdlib.h>

struct NOD{
    struct NOD *st,*dr;
    int value;
};

void adaug(struct NOD **root,int value)
{
    struct NOD *p = (struct NOD*)malloc(sizeof(struct NOD)), *q;
    p -> value = value;
    p -> st = p -> dr = NULL;
    if(*root == NULL) *root = p;
    else
    {
        q = *root;
        while(q -> st != NULL || q -> dr != NULL)
        {
            if(p -> value < q -> value)
            {
                if(q -> st != NULL) q = q -> st;
                else {q -> st = p;break;}
            }
            else
            {
                if(q -> dr != NULL) q = q -> dr;
                else {q -> dr = p;break;}
            }
        }
        if(q -> st == NULL && q -> dr == NULL)
        {
            if(p -> value < q -> value) q -> st = p;
            else q -> dr = p;
        }
    }
}

void SRD(struct NOD *p,int k1,int k2)
{
    if(p == NULL) return;
    SRD(p -> st,k1,k2);
    if(p -> value >= k1 && p -> value <= k2) printf("%d ", p -> value);
    SRD(p -> dr,k1,k2);
}

void citire(struct NOD **root,int *k1,int *k2)
{
    struct NOD *p;
    int n,type,value;
    scanf("%d %d %d",&n,k1,k2);
    while(n--)
    {
        scanf("%d",&value);
        adaug(&(*root),value);
    }
}

int main()
{
    struct NOD *root = NULL;
    int k1,k2;
    citire(&root,&k1,&k2);
    SRD(root,k1,k2);
    return 0;
}
