#include <iostream>

using namespace std;

struct arb
{
    int info;
    arb *st;
    arb *dr;
}*radacina;
void inserare(arb*&r, int x)
{
    if(r==NULL)
    {
        r=new arb;
        r->info=x;
        r->st=r->dr=NULL;
        return;
    }
    if(x<r->info)
    {
        inserare(r->st,x);
    }
    else inserare(r->dr,x);
}
int cautare(arb *c,int k)
{
if(c)
    if(c->info==k)
            return 1;
    else
            if(c->info<k)
               cautare(c->dr,k);
            else
               cautare(c->st,k);
 else
    return 0;
}
int findMax(arb *r)
{
    while(r->dr!=NULL)
    {
        r=r->dr;
    }
    return r->info;
}

void cmd(arb* &c,arb* &f)
{arb *aux;
 if(f->dr)
    cmd(c,f->dr);
 else
     {c->info=f->info;
      aux=f;
      f=f->st;
      delete aux;
      }
}

void sterg(arb *&c,int k)
{arb *aux,*f;
 if(c)
   if(c->info==k)
       if(c->st==0&&c->dr==0)  //daca e nod terminal
               {delete c;
                c=0;
                }
            else
               if(c->st==0)      //are numai subordonat drept
                 {aux=c->dr;
                  delete c;
                  c=aux;}
                else
                   if(c->dr==0)    //are numai subordonat drept
                          {aux=c->st;
                           delete c;
                           c=aux;}
                   else
                           cmd(c,c->st);  //are ambii subordonati

   else
     if(c->info<k)
            sterg(c->dr,k);
     else
            sterg(c->st,k);

 else
      cout<<"valoarea de sters nu se gaseste in arbore ";
}
void SRD(arb *r)
{
    if(r==NULL)
        return;
    cout<<r->info<<" ";
    SRD(r->st);

    SRD(r->dr);
}
int main()
{
    int n, i, x;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x;
        inserare(radacina,x);
    }
    if(cautare(radacina,5)==1)
        cout<<"S-a gasit";
    else cout<<"Nu s-a gasit";
    cout<<endl;
    cout<<findMax(radacina);
    cout<<endl;
    sterg(radacina,4);
    SRD(radacina);
    return 0;
}
