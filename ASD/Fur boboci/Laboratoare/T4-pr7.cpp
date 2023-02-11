#include <iostream>

using namespace std;

struct Queue{
    int info;
    Queue *leg;
};

Queue *Q[55];
int v[55],a[55];

void Init()
{
    int i;
    for(i=1;i<=50;i++)
        Q[i]=NULL;
}

void Push(int x, int poz)
{
    Queue *p,*q;
    p=new Queue;
    p->info=x;
    if(Q[poz]==NULL)
    {
        p->leg=NULL;
        Q[poz]=p;
    }
    else
    {
        p=Q[poz];
        while(p->leg!=NULL)
            p=p->leg;
        q=new Queue;
        q->info=x;
        q->leg=p->leg;
        p->leg=q;
    }
}

int Pop(int poz)
{
    int x;
    Queue *p;
    p=Q[poz];
    x=p->info;
    Q[poz]=Q[poz]->leg;
    delete p;
    return x;
}

int Peek(int poz)
{
    return Q[poz]->info;
}

bool Empty(int poz)
{
    if(Q[poz]==NULL)
        return 1;
    else
        return 0;
}

void Citire()
{
    int i,x,n,j,maxim,poz,vag,k;
    vag=1;
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=n;i>0;i--)
    {
        x=a[i];
        for(j=1;j<=k;j++)
            if(v[j]<x)
            {
                poz=j;
                break;
            }
        Push(x,j);
        v[j]=x;
        for(j=1;j<=k;j++)
            if(Peek(j)==vag)
            {
                cout<<Pop(j)<<"\n";
                vag++;
            }
    }
}

int main()
{
    Init();
    Citire();
    return 0;
}
