#include <iostream>

using namespace std;

struct Queue{
    int info;
    Queue *leg;
};

int n;

void Push(Queue *&Q, int x)
{
    Queue *p,*q;
    p=new Queue;
    p->info=x;
    if(Q==NULL)
    {
        p->leg=NULL;
        Q=p;
        ///cout<<"bbb"<<p->info<<" ";
    }
    else
    {
        p=Q;
        while(p->leg!=NULL)
            p=p->leg;
        q=new Queue;
        q->info=x;
        q->leg=p->leg;
        p->leg=q;
        ///cout<<"aaa"<<p->info<<" ";
    }
}

int Pop(Queue *&Q)
{
    int x;
    Queue *p;
    p=Q;
    x=p->info;
    Q=Q->leg;
    delete p;
    return x;
}

int Peek(Queue *Q)
{
    return Q->info;
}

void Citire(Queue *&Q)
{
    int i,x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        Push(Q,x);
    }
}

bool Empty(Queue *Q)
{
    if(Q==NULL)
        return 1;
    else
        return 0;
}

int Search(Queue *Q, int x)
{
    int i=0,ok=1;
    Queue *p;
    p=Q;
    while(p->leg!=NULL && ok==1)
    {
        if(x==p->info)
            ok=0;
        p=p->leg;
        i++;
    }
    i--;
    if(ok==1)
        return -1;
    else
        return i;


}

void Afisare(Queue *Q)
{
    Queue *p;
    p=Q;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->leg;
    }
    cout<<"\n";
}

int main()
{
    Queue *Q;
    Q=NULL;
    Citire(Q);
    Afisare(Q);
    cout<<Pop(Q)<<"\n";
    Afisare(Q);
    cout<<Peek(Q)<<"\n";
    Afisare(Q);
    cout<<Search(Q,5);
    return 0;
}
