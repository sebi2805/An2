
#include <iostream>
using namespace std;

struct nod {

  int info;
  nod *next;
} *v, *sf;

void push(nod* &v,nod* &sf,int a)
{
    nod *c;
    if(!v)
    {
     v = new nod;
     v -> info = a;
     v -> next = NULL;
     sf = v;
    }
     else
     {
      c = new nod;
      sf -> next = c;
      c -> info = a;
      sf = c;
      sf -> next = NULL;
     }
}

void popp(nod* &v)
{
    nod* c;
    if(!v)   cout<<"coada este vida si nu mai ai ce elimina!";
    else
      {
         c = v;
         v = v -> next;
         cout<<c->info<<endl;
         delete c;
      }
 }

int peek(nod* &v)
{
    return v ->info;
}

bool emptyy(nod* &v)
{
    if(v == NULL) return 0;
    else return 1;
}
void citire()
{
    int n,a;
    cin >> n;
    while(n--)
    {
        cin >> a;
        push(v, sf,a);
    }
}

int searchh(int a, nod* &v)
{

    int i;
    i = 0;
    while(v != NULL)
    {
        if(a == v -> info) return i+1;
        v = v -> next;
        i++;
    }
    return -1;
}
void afisare(nod *v)
{
 nod *c;
 c = v;
 while(c != NULL)
    {
     cout << c -> info<<" ";
     c = c -> next;
    }
}
int main()
{
    //4
    citire();
    afisare(v);
    cout<<endl;
    cout<<peek(v);

    cout<<endl;
    afisare(v);
    cout<<'\n'<<searchh(4,v)<<"\n";
    popp(v);
    return 0;
}
