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

void Pop(Stack *&S)
{
    Stack *p;
    p=S;
    S=S->leg;
    delete(p);
}

int Peek(Stack *S)
{
    return S->info;
}

bool IsEmpty(Stack *S)
{
    if(S==NULL)
        return 1;
    else
        return 0;
}

void Citire(Stack *&S)
{
    int n,i,y,sgn;
    char x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(IsEmpty(S))
        {
            Push(x,S);
            continue;
        }
        if(Peek(S)==x)
            Push(x,S);
        else
            Pop(S);
    }
    if(IsEmpty(S))
        cout<<"Nr este egal";
    else
        cout<<"Nr nu este egal";
}

int main()
{
    Stack *S;
    S=NULL;
    Citire(S);
    return 0;
}
