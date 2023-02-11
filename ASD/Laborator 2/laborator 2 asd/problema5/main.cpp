#include <iostream>
#include <cstdio>
using namespace std;
struct nod
{
    float val;
    nod *next;
} *prim;
void push_final(float x)
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
void afiseaza()
{
    nod *r;
    r = prim;
    while(r != NULL){
        cout<<r->val<<" ";
        r = r->next;
    }
    printf("\n");
}

int main(){
    push_final(100);
    push_final(1);
    push_final(3);
    push_final(4);
    push_final(5);
    afiseaza();
    nod *r, *p;
    r=prim;
    while(r->next!=NULL)
    {
        nod *q;
        q=new nod;
        p=r;
        r=r->next;
        q->val=(p->val+r->val)/2;
        q->next=r;
        p->next=q;
    }
    afiseaza();
    return 0;
}
