#include <stdio.h>
#include <stdlib.h>

struct NOD{
    struct NOD *st,*dr;
    int value,index;
};

void adaug(struct NOD **root,int value)
{
    struct NOD *p = (struct NOD*)malloc(sizeof(struct NOD)), *q;
    p -> value = value;
    p -> st = p -> dr = NULL;
    p -> index = 0;
    if(*root == NULL) {*root = p; (*root) -> index = 0;}
    else
    {
        q = *root;
        while(q -> st != NULL || q -> dr != NULL)
        {
            if(p -> value < q -> value)
            {
                (q -> index)++;
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
            if(p -> value < q -> value) {q -> st = p;q -> index++;}
            else q -> dr = p;
        }
    }
}

void SRD(struct NOD *p)
{
    if(p == NULL) return;
    SRD(p -> st);
    printf("%d ", p -> index);
    SRD(p -> dr);
}

void citire(struct NOD **root,int *k)
{
    struct NOD *p;
    int n,type,value;
    scanf("%d %d",&n,k);
    while(n--)
    {
        scanf("%d",&value);
        adaug(&(*root),value);
    }
}

void cautare(struct NOD *root,int k)
{
    if(root -> index == k)
    {
        printf("\n%d\n",root -> value);
        return;
    }
    else if(root -> index > k) cautare(root -> st,k);
    else cautare(root -> dr,k - (root -> index) - 1);
}

int main()
{
    struct NOD *root = NULL;
    int k;
    citire(&root,&k);
    cautare(root,k);
    return 0;
}
