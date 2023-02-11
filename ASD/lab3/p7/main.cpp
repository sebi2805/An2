#include <iostream>
using namespace std;
int a[101][101], eticheta = 2,n;
int di[5]={0,-1,1,0,0};
int dj[5]={0,0,0,-1,1};
struct coada{
    int i;
    int j;
    coada *next;
}*prim,*ultim;
void etichetare(){
    int k;
    a[prim->i][prim->j]=eticheta;
    while(prim!=NULL){

        for(k=1;k<=4;k++){
            if(a[ (prim->i) + di[k] ][ (prim->j) + dj[k] ] == 1){
                a[ (prim->i) + di[k] ][ (prim->j) + dj[k] ] = eticheta;
                coada *nou = new coada ;
                nou->i = (prim->i) + di[k];
                nou->j = (prim->j) + dj[k];
                nou->next=NULL;
                ultim->next=nou;
                ultim=nou;
            }
        }
        coada *old = prim;
        prim=prim->next;
        delete old;
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]==1){
                prim=new coada;
                ultim=prim;
                prim->i=i;
                prim->j=j;
                ultim->next=NULL;
                etichetare();
                eticheta++;
            }
    cout<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';

    }
    return 0;
}
