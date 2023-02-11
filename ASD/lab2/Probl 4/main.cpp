#include <iostream>
using namespace std;
struct NOD{
    int val;
    NOD *next;
}*prim;
int main()
{
    int n,valoare,i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>valoare;
        NOD *p= new NOD;
        p->next=prim;
        p->val=valoare;
        prim=p;
    }
    cout<<'\n';
    NOD *act=prim;
    int nr=0,s=0;
    while(act!=NULL){
        if((act->val)>0)
            nr++;
        else
            s+=act->val;
        act=act->next;
    }
    cout<<"Sunt "<<nr<<" numere pozitive\n";
    if (s!=0)
    cout<<"Media numerelor negative este "<<(s*1.0)/(n-nr);
    else
    cout<<" Nu exista numere negative";
    return 0;
}
