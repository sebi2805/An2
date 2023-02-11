#include <iostream>
#include <cstdio>
using namespace std;
struct nod
{
    int val;
    nod *next;
} *prim;
void push_final(int x)
{
    if(prim == NULL)
    {
        prim=new nod;
        prim->val = x;
        prim->next = NULL;
        return;
    }
    nod *r;
    r=prim;
    while(r->next != NULL){
        r = r->next;
    }
    nod *p;
    p = new nod;
    r->next = p;
    p->val = x;
    p->next = NULL;
}

int main()
{
    push_final(2);
    push_final(-5);
    push_final(3);
    push_final(-4);
    push_final(-101);
    nod *r;
    r = prim;
    int contorpoz, contorneg, sumaneg;
    float ma;
    contorpoz=0;
    contorneg=0;
    sumaneg=0;
    while(r != NULL){
        if(r->val>=0)
        {
            contorpoz++;
        }
        else
        {
            contorneg++;
            sumaneg=sumaneg+r->val;
        }
        r = r->next;
    }
    if(contorneg==0)
    {
        cout<<"Nu exista numere negative in lista"<<endl;
    }
    else
    {
        ma=(float)sumaneg/contorneg;
        cout<<"Media aritmetica a numerelor negative din lista este "<<ma<<endl;
    }
    cout<<endl;
    cout<<"In sir sunt "<<contorpoz<<" numere pozitive";
    cout<<endl;
    return 0;
}
