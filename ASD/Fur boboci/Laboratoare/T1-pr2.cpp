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

void Insert()
{
    int i,j,val;
    for(i=1;i<=n;i++)
    {
        val=a[i];
        j=i;
        while(j>0 && a[j-1]>val)
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=val;
    }
}

int main()
{
    Citire();
    int i;
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    Insert();
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}
