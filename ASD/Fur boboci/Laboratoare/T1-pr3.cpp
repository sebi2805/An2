#include <iostream>
#include <fstream>

using namespace std;

int n,minim;
int a[1000];

void Citire()
{
    int i;
    ifstream fin("date.in");
    fin>>n;
    for(i=1;i<=n;i++)
        fin>>a[i];
    fin.close();
}

void Select()
{
    int i,j,aux,x,y;
    for(i=1;i<=n;i++)
    {
        x=i;
        for(j=i+1;j<=n;j++)
            if(a[x]>a[j])
                x=j;
        if(x!=i)
        {
            aux=a[i];
            a[i]=a[x];
            a[x]=aux;
        }
    }
}

int main()
{
    Citire();
    int i;
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    Select();
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}
