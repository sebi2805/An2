#include <iostream>

using namespace std;

struct Stack
{
    int info;
    Stack *leg;
};

void Push(int x, Stack *&S)
{
    Stack *p;
    p=new Stack;
    p->info=x;
    if(S==NULL)
    {
        p->leg=NULL;
        S=p;
    }
    else
    {
        p->leg=S;
        S=p;
    }
}

int Pop(Stack *&S)
{
    int x;
    Stack *p;
    p=S;
    x=p->info;
    S=S->leg;
    delete(p);
    return x;
}

int Peek(Stack *S)
{
    return S->info;
}

bool IsEmpty(Stack *S)
{
    if(S!=NULL)
        return 1;
    else
        return 0;
}

int Search(int x, Stack *S)
{
    int ok=1,i=0;
    Stack *p;
    p=S;
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

void Citire(Stack *&S)
{
    int x,n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        Push(x,S);
    }
}

void Afisare(Stack *S)
{
    Stack *p;
    p=S;
    if(p==NULL)
        cout<<"Vida";
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->leg;
    }
}

int main()
{
    Stack *S;
    S=NULL;
    Citire(S);
    Afisare(S);cout<<"\n";
    Pop(S);
    Afisare(S);
    cout<<Peek(S)<<"\n";
    cout<<Pop(S)<<"\n";
    Afisare(S);cout<<"\n";
    cout<<Search(21,S)<<"\n";
    return 0;
}
