#include <iostream>

using namespace std;

struct nod
{
int key;
int ech;
nod *left, *right;
} *rad;
void drum_maxim(nod* p,int &max,int lung){
if (p!=NULL){
drum_maxim(p->right,max,lung+1);
if ((p->left==NULL)&&(p->right==NULL)&&(max<lung))
max=lung;
drum_maxim(p->left,max,lung+1);
}
}
void calcul_factor_echilibru(nod *p){
int hLeft,hRight;
hLeft=1; hRight=1;
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
nod* echilibrare(nod *p){
nod *w;
calcul_factor_echilibru(p);//se calculeaza factorul de echilibru a nodului curent p
if(p->ech==-2){// daca p nod este critic
w=p->left; // atunci w este copilul stanga al lui p
if (w->ech==1)// si daca acesta are factorul de echilibru 1
p = d_rot_right(p);// atunci se face dubla rotatie dreapta
else//altfel se face o simpla rotatie dreapta
p = s_rot_right(p);
}
else
if(p->ech==2){//daca p nod este critic
w=p->right;//w este copilul dreapta al nodului curent p
if (w->ech==-1)// si acesta are factorul de ech -1
p = d_rot_left(p);//se face o dubla rotatie stanga
else//altfel se face o simpla rotatie stanga
p = s_rot_left(p);
}
return p;
}
nod* insereaza(nod *&p,int x){
if (p==NULL){ // daca nodul curent este NULL atunci
p=new nod; //se aloca spatiu pentru el in zona heap
p->key=x; //informatia devine x
p->ech=0; // factorul de echilibru este 0 - nodul este echilibrat
p->right=NULL;// nodul se insereaza ca nod frunza
p->left=NULL; //deci referintele catre copii sai sunt NULL
return p;
}
else {
if (x<p->key) //daca cheia care se doreste inserata este
//mai mica ca valoare decat informatia din nodul curent
p->left = insereaza(p->left,x);// atunci se insereaza
//in subarborele stang al nodului curent
else
if (x>p->key) //altfel daca cheia care se va insera
//e mai mare decat informatia din nodul curent
p ->right = insereaza(p->right,x); // atunci se va insera
//in subarborele drept
else
cout<<"Nodul exista deja"<<endl;
}
p = echilibrare(p);// daca intervin cazuri de dezechilibru
//se va echilibra subarborele sau chiar arborele
}
nod* stergere(nod *&p,int x){
nod *q,*r,*w;
if (p!=NULL)// daca nodul curent este diferit de NULL
if (x<p->key) //cheia care se doreste stearsa este mai mica decat informatia din nod
p->left = stergere(p->left,x); // se cauta cheia de sters in subarborele stang al nodului curent
else
if (x>p->key) // daca cheia este mai mare
p->right = stergere(p->right,x);// se cauta in subarborele drept
else{
    //daca cheia este egala cu informatia din nodul curent
q=p;//un nod q devine p
if (q->right==NULL) // daca copilul drept al lui q eate NULL
p=q->left;// atunci p devine q->stanga
else
if (q->left==NULL) //altfel daca copilul stang al lui q este NULL
p=q->right;// p devine q->dreapta
else{
w=q->left;//altfel w este copilul stanga al lui q
r=q;// r devine q
if (w->right!=NULL)// daca copilul drept al lui w nun este NULL
{
while (w->right!=NULL){
r=w;
w=w->right;
}
p->key=w->key;
q=w;
r->right=w->left;
r=p->left;
w=w->left;
if (r!=NULL)
while ((r!=w)&&(r!=NULL)){
r = echilibrare(r);
r=r->right;
}
}
else{
p->key=w->key;
p->left=w->left;
q=w;
}
}
delete(q);// se sterge q
}
if (p!=NULL)
p = echilibrare(p);// se echilibreaza p daca nu este NULL
return p;
}

int cautare(nod *c,int k)
{
if(c)
    if(c->key==k)
            return 1;
    else
            if(c->key<k)
               cautare(c->right,k);
            else
               cautare(c->left,k);
 else
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
    //if(cautare(rad,5)==1)
        //cout<<"S-a gasit";
    //else cout<<"Nu s-a gasit";
    //cout<<endl;
    //cout<<findMax(rad);
    cout<<endl;
    stergere(rad,5);
    SRD(rad);
    cout<<endl;
    RSD(rad);
    return 0;
}
