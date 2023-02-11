#include <iostream>

using namespace std;

struct Nod
{
    int info;
    Nod *next,*prev;
};

int n;

void Add_begin(Nod *&Fst, int val)
{
    Nod *p;
    p=new Nod;
    p->info=val;
    p->prev=NULL;
    p->next=Fst;
    if(Fst!=NULL)
        Fst->prev=p;
    Fst=p;
}

void Add_end(Nod *&Fst, Nod *&Lst, int val)
{
    Nod *p;
    p=new Nod;
    p->info=val;
    p->next=NULL;
    p->prev=NULL;

    if(Fst==NULL)
    {
        Fst=p;
        Lst=Fst;
    }
    else
    {
        Lst->next=p;
        p->prev=Lst;
        Lst=p;
    }
}

void Add_inside(Nod *&Fst, Nod *&Lst, int val, int poz)
{
    int cnt=0;
    Nod *p,*q;
    q=new Nod;
    q->info=val;

    p=Fst;
    while(p->next!=NULL && cnt<poz-1)
    {
        cnt++;
        p=p->next;
    }

    ///SAU
    /*p=Lst;
    while(p->prev!=NULL && cnt<poz-1)
    {
        cnt++;
        p=p->prev;
    }*/
    q->next=p->next;
    q->prev=p;
    p->next->prev=q;
    p->next=q;
}

void Delete_poz(Nod *&Fst, Nod *&Lst, int poz)
{
    int cnt=0;
    Nod *p,*q;

    if(poz==1)
    {
        q=Fst->next;
        q->prev=NULL;
        Fst=q;
    }

    else if(poz==n)
    {
        q=Lst->prev;
        q->next=NULL;
        Lst=q;
    }

    else
    {
        p=Fst;
        while(p->next!=NULL && cnt<poz-1)
        {
            cnt++;
            p=p->next;
        }
        q=p->next;
        q->prev->next=q->next;
        q->next->prev=q->prev;
        delete q;
    }

    ///SAU
    /*else
    {
        p=Lst;
        while(p->prev!=NULL && cnt<poz-1)
        {
            cnt++;
            p=p->prev;
        }
        q=p->prev;
        q->prev->next=q->next;
        q->next->prev=q->prev;
        delete q;
    }*/
}

void Delete_val(Nod *&Fst, Nod *&Lst, int val)
{
    Nod *p,*q;

    if(Lst->info==val)
    {
        q=Lst->prev;
        q->next=NULL;
        Lst=q;
    }
    else if(Fst->info==val)
    {
        q=Fst->next;
        q->prev=NULL;
        Fst=q;
    }

    else
    {
        p=Fst;
        while(p->next!=NULL && p->next->info!=val)
            p=p->next;
        q=p->next;
        q->prev->next=q->next;
        q->next->prev=q->prev;
        delete q;
    }

    ///SAU
    /*else
    {
        p=Lst;
        while(p->prev!=NULL && p->prev->info!=val)
            p=p->prev;
        q=p->prev;
        q->prev->next=q->next;
        q->next->prev=q->prev;
        delete q;
    }*/
}

void Afisare(Nod *K)
{
    Nod *p;
    if(K->prev==NULL)
    {
        p=K;
        while(p!=NULL)
        {
            cout<<p->info<<" ";
            p=p->next;
        }
    }
    if(K->next==NULL)
    {
        p=K;
        while(p!=NULL)
        {
            cout<<p->info<<" ";
            p=p->prev;
        }
    }
    cout<<"\n";
}

int main()
{
    Nod *First, *Last;
    First=NULL;

    int i,x;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        Add_end(First,Last,x);
        //Add_begin(First,x);
    }

    Afisare(First);
    Afisare(Last);

    Add_inside(First,Last,7,1);
    Afisare(First);

    ///Sterge elementul aflat dupa pozitia p.
    Delete_poz(First,Last,5);
    Afisare(First);

    ///Sterge elementul cu valoarea x
    Delete_val(First,Last,1);
    Afisare(First);
    return 0;
}
