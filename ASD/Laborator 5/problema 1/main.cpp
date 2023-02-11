#include <iostream>
#include <cstdio>

using namespace std;

struct nod
{
    int key;
    int ech;
    nod *left, *right;
} *rad;
void drum_maxim(nod* p,int &max,int lung)
{
    if (p!=NULL)
    {
        drum_maxim(p->right,max,lung+1);
        if ((p->left==NULL)&&(p->right==NULL)&&(max<lung))
            max=lung;
        drum_maxim(p->left,max,lung+1);
    }
}
void calcul_factor_echilibru(nod *p)
{
    int hLeft,hRight;
    hLeft=1;
    hRight=1;
    if(p->left!=NULL)
        drum_maxim(p->left,hLeft,1);
    else
        hLeft=0;
    if(p->right!=NULL)
        drum_maxim(p->right,hRight,1);
    else
        hRight=0;
    p->ech=hRight-hLeft;
}
nod *s_rot_right(nod *p)
{
    nod*q;
    q=p->left;
    p->left=q->right;
    q->right=p;
    calcul_factor_echilibru(p);
    calcul_factor_echilibru(q);
    p=q;
    return p;
}
nod *s_rot_left(nod *p)
{
    nod*q;
    q=p->right;
    p->right=q->left;
    q->left=p;
    calcul_factor_echilibru(p);
    calcul_factor_echilibru(q);
    p=q;
    return p;
}
nod *d_rot_right(nod *p)
{
    p->left=s_rot_left(p->left);
    p=s_rot_right(p);
    return p;
}
nod *d_rot_left(nod *p)
{
    p->right=s_rot_right(p->right);
    p=s_rot_left(p);
    return p;
}
nod* echilibrare(nod *p)
{
    nod *w;
    calcul_factor_echilibru(p);
    if(p->ech==-2)
    {
        w=p->left;
        if (w->ech==1)
            p = d_rot_right(p);
        else
            p = s_rot_right(p);
    }
    else if(p->ech==2)
    {
        w=p->right;
        if (w->ech==-1)
            p = d_rot_left(p);
        else
            p = s_rot_left(p);
    }
    return p;
}
nod* insereaza(nod *&p,int x)
{
    if (p==NULL)
    {
        p=new nod;
        p->key=x;
        p->ech=0;
        p->right=NULL;
        p->left=NULL;
        return p;
    }
    else
    {
        if (x<p->key)

            p->left = insereaza(p->left,x);

        else if (x>p->key)
            p ->right = insereaza(p->right,x);
        else
            cout<<"Nodul exista deja"<<endl;
    }
    p = echilibrare(p);
    return p;
}
nod* stergere(nod *&p,int x)
{
    nod *q,*r,*w;
    if (p!=NULL)
    {
        if (x<p->key)
            p->left = stergere(p->left,x);
        else if (x>p->key)
            p->right = stergere(p->right,x);
        else
        {

            q=p;
            if (q->right==NULL)
                p=q->left;
            else if (q->left==NULL)
                p=q->right;
            else
            {
                w=q->left;
                r=q;
                if (w->right!=NULL)
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
            delete(q);
        }
    }
    if (p!=NULL)
        p = echilibrare(p);
    return p;
}

int cautare(nod *c,int k)
{
    if(c)
    {
        if(c->key==k)
            return 1;
        else if(c->key<k)
            cautare(c->right,k);
        else
            cautare(c->left,k);
    }
    return 0;
}
int findMax(nod *r)
{
    while(r->right!=NULL)
    {
        r=r->right;
    }
    return r->key;
}
void SRD(nod *r)
{
    if(r==NULL)
        return;
    SRD(r->left);
    cout<<r->key<<" ";
    SRD(r->right);
}
void RSD(nod *r)
{
    if(r==NULL)
        return;
    cout<<r->key<<" ";
    RSD(r->left);
    RSD(r->right);
}
int main()
{
    int n, i, x;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x;
        insereaza(rad,x);
    }

    cout<<endl;
    int nr;
    cout<<"SRD: ";
    SRD(rad);
    cout<<endl;
    cout<<"RSD: ";
    RSD(rad);
    cout<<endl;
    cin>>nr;
    stergere(rad,nr);
    SRD(rad);
    return 0;
}
