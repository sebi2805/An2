#include <iostream>
#include <fstream>

using namespace std;

int n;
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

void Bubble()
{
    int i,j,aux;
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            if(a[i]>a[j])
            {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
}

int main()
{
    Citire();
    int i;
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    Bubble();
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}
