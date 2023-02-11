#include <iostream>
#include <cstdio>
using namespace std;
struct nod
{
    int val;
    nod *leg;
} *prim;

int main(){
    long long int nr1, nr2, transp;
    cin>>nr1;
    cin>>nr2;
    prim=NULL;
    transp=0;
    if(nr1>nr2)
    {
        while(nr1!=0 || nr2!=0)
        {
            nod *p;
            p = new nod;
            if(prim==NULL)
            {
                p->val=nr1%10+nr2%10;
                p->leg=NULL;
                prim=p;
                if(p->val>9)
                {
                    nod *r;
                    r=new nod;
                    r->val=prim->val/10;
                    r->leg=prim;
                    prim=r;
                    prim->leg->val=prim->leg->val%10;
                    transp=1;
                }
            }
            else if(prim!=NULL)
            {
                if(nr1%10+nr2%10+prim->val>=9 && transp==1)
                {
                    nod *r;
                    r=new nod;
                    r->val=(nr1%10+nr2%10+prim->val)/10;
                    r->leg=prim;
                    prim->val=(nr1%10+nr2%10+prim->val)%10;
                    prim=r;
                    prim->leg->val=prim->leg->val%10;
                    transp=1;
                }
                else if(nr1%10+nr2%10>9 && transp==0)
                {
                    nod *p;
                    p=new nod;
                    p->val=(nr1%10+nr2%10)%10;
                    p->leg=prim;
                    prim=p;
                    transp=1;
                    nod *r;
                    r=new nod;
                    r->val=prim->val/10;
                    r->leg=prim;
                    prim=r;
                    prim->leg->val=prim->leg->val%10;
                }
                else if(nr1%10+nr2%10<=9)
                {
                    nod *p;
                    p=new nod;
                    p->val=nr1%10+nr2%10;
                    p->leg=prim;
                    prim=p;
                }
            }
            nr1=nr1/10;
            nr2=nr2/10;
        }
    }
    nod *r;
    if(prim->val!=0) r = prim;
    else r=prim->leg;
    while(r != NULL)
    {
        printf("%d", r->val);
        r = r->leg;
    }
    return 0;
}
