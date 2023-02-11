#include <iostream>

using namespace std;

struct Nod
{
    int info;
    Nod *lft, *rgt;
};
Nod *rad;

void Inserare(int x)
{
    Nod *p,*q;
    p=rad;
    if(rad==NULL)
    {
        p=new Nod;
        p->info=x;
        p->lft=p->rgt=NULL;
        rad=p;
    }
    else
    {
        while(p!=NULL)
        {
            q=p;
            if(x<=p->info)
                p=p->lft;
            else
                p=p->rgt;
        }
        p=new Nod;
        p->info=x;
        p->lft=p->rgt=NULL;
        if(x>q->info)
            q->rgt=p;
        else
            q->lft=p;
    }
}

int Search(Nod *rad, int x)
{
    if(rad!=NULL)
    {
        if(rad->info==x)
            return 1;
        Search(rad->lft,x);
        Search(rad->rgt,x);
    }
}

int maxim;
void FindMax(Nod *rad)
{
    if(rad!=NULL)
    {
        FindMax(rad->lft);
        if(rad->info>maxim)
            maxim=rad->info;
        FindMax(rad->rgt);
    }
}

void RSD(Nod *rad)
{
    if(rad!=NULL)
    {
        cout<<rad->info<<" ";
        RSD(rad->lft);
        RSD(rad->rgt);
    }
}

void functie_supl(Nod *&c, Nod *&f)
{
    Nod *aux;
    if(f->lft)
        functie_supl(c, f->lft);
    else
    {
        c->info=f->info;
        aux=f;
        f=f->rgt;
        delete aux;
    }
}

void sterg(Nod *&c, int n)
{
    Nod *f;
    if(c)
        if(c->info==n)
            if(c->rgt==0 && c->lft==0)
            {
                delete c;
                c=0;
            }
            else
                if(c->rgt==0)
                {
                    f=c->lft;
                    delete c;
                    c=f;
                }
                else
                    if(c->rgt==0)
                    {
                        f=c->rgt;
                        delete c;
                        c=f;
                    }
                    else
                        functie_supl(c, c->rgt);
        else
            if(c->info<n)
                sterg(c->lft, n);
            else
                sterg(c->rgt, n);
    else
    cout<<"eroare";
}

int main()
{
    rad=NULL;
    int i,n,x,maxii=0;
    ///a
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>x;
        Inserare(x);
    }

    RSD(rad);

    ///b
    cout<<"\n";
    if(Search(rad,45)==1)
        cout<<"DA\n";
    else
        cout<<"NU\n";

    ///c
    FindMax(rad);
    cout<<maxim<<"\n";

    ///d
    sterg(rad,67);
    return 0;
}
