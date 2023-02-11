#include <iostream>

using namespace std;

struct nod
{
     int key;
     int ech;
     nod *left, *right;
};
nod * rad;

///a
void drum(nod* p,int &maxim,int lung)
{
    if (p!=NULL)
    {
        drum(p->right,maxim,lung+1);
        if ((p->left==NULL)&&(p->right==NULL)&&(maxim<lung))
            maxim=lung;
        drum(p->left,maxim,lung+1);
    }
}

void fact_ech(nod *p)
{
     int hleft,hright;
     hleft=1; hright=1;
     if(p->left!=NULL)
        drum(p->left,hleft,1);
     else
        hleft=0;
     if(p->right!=NULL)
        drum(p->right,hright,1);
     else
        hright=0;
     p->ech=hright-hleft;
}

nod* s_rot_left(nod* p)
{
    nod* q;
    q=p->right;
    p->right=q->left;
    q->left=p;
    fact_ech(p);
    fact_ech(q);
    p=q;
    return p;
}

nod* s_rot_right(nod* p)
{
    nod* q;
    q=p->left;
    p->left=q->right;
    q->right=p;
    fact_ech(p);
    fact_ech(q);
    p=q;
    return p;
}

nod* d_rot_right(nod* p)
{
    p->left=s_rot_left(p->left);
    p=s_rot_right(p);
    return p;
}

nod* d_rot_left(nod* p)
{
    p->right=s_rot_right(p->right);
    p=s_rot_left(p);
    return p;
}

nod* echilibrare(nod *p)
{
    nod *w;
    fact_ech(p);///se calculeaza factorul de echilibru a nodului curent p
    if(p->ech==-2)
    {
        w=p->left; /// atunci w este copilul stanga al lui p
        if (w->ech==1)/// si daca acesta are factorul de echilibru 1
            p = d_rot_right(p);/// atunci se face dubla rotatie dreapta
        else///altfel se face o simpla rotatie dreapta
            p = s_rot_right(p);
    }
    else if(p->ech==2)
    {
        w=p->right;///w este copilul dreapta al nodului curent p
        if (w->ech==-1)/// si acesta are factorul de ech -1
            p = d_rot_left(p);///se face o dubla rotatie stanga
        else///altfel se face o simpla rotatie stanga
            p = s_rot_left(p);
    }
    return p;
}

nod* insereaza(nod *p,int x)
{
    if (p==NULL)
    {
         p=new nod;
         p->key=x;
         p->ech=0; ///factorul de echilibru este 0 - nodul este echilibrat
         p->right=NULL;/// nodul se insereaza ca nod frunza
         p->left=NULL; ///deci referintele catre copii sai sunt NULL
         return p;
    }
    else
    {
        if (x<p->key) ///daca cheia care se doreste inserata este mai mica ca valoare decat informatia din nodul curent
            p->left = insereaza(p->left,x);/// atunci se insereaza in subarborele stang al nodului curent
        else if (x>p->key) ///altfel daca cheia care se va insere e mai mare decat informatia din nodul curent
            p ->right = insereaza(p->right,x); /// atunci se va insera in subarborele drept
            else cout<<"Nodul exista deja"<<endl;
     }
     p = echilibrare(p);/// daca intervin cazuri de dezechilibre se va echilibra subarborele sau chiar arborele
}

///d
nod* stergere(nod *p,int x)
{
    nod *q,*r,*w;
    if (p!=NULL)
        if (x<p->key) ///cheia care se doreste stearsa este mai mica decat informatia din nod
            p->left = stergere(p->left,x); /// se cauta cheia de sters in subarborele stang al nodului curent
        else
            if (x>p->key) /// daca cheia este mai mare
                p->right = stergere(p->right,x);/// se cauta in subarborele drept
            else
            {
                ///daca cheia este egala cu informatia din nodul curent
                q=p;///un nod q devine p
                if (q->right==NULL) /// daca copilul drept al lui q eate NULL
                    p=q->left;/// atunci p devine q->stanga
                else
                    if (q->left==NULL) ///altfel daca copilul stang al lui q este NULL
                        p=q->right;/// p devine q->dreapta
                    else
                    {
                        w=q->left;///altfel w este copilul stanga al lui q
                        r=q;/// r devine q
                        if (w->right!=NULL)/// daca copilul drept al lui w nun este NULL
                        {
                            while (w->right!=NULL)
                            {
                                r=w;
                                w=w->right;
                            }
                            p->key=w->key;
                            q=w;
                            r->right=w->left;
                            r=p->left;
                            w=w->left;
                            if (r!=NULL)
                                while ((r!=w)&&(r!=NULL))
                                {
                                    r = echilibrare(r);
                                    r=r->right;
                                }
                        }
                        else
                        {
                            p->key=w->key;
                            p->left=w->left;
                            q=w;
                        }
                    }
                    delete(q);/// se sterge q
            }
     if (p!=NULL)
        p = echilibrare(p);/// se echilibreaza p daca nu este NULL
     return p;
}

///b
int cauta(nod* p, int x)
{
    if(p!=NULL)
    {
        cauta(p->left,x);
        if(p->key==x)
            return 1;
        cauta(p->right,x);
    }
    return 0;
}

///c
int elem_maxim(nod* p, int x, int &maxim)
{
    if(p!=NULL)
    {
        elem_maxim(p->left,x,maxim);
        if(p->key>maxim)
            maxim=p->key;
        elem_maxim(p->right,x,maxim);
    }
}

///e
void afisare(nod* p)
{
    if(p!=NULL)
    {
        afisare(p->left);
        cout<<p->key<<" ";
        afisare(p->right);
    }
}

int main()
{
    return 0;
}
