#include <iostream>
#include <fstream>

using namespace std;

ifstream f("inv.in");
ofstream g("inv.out");

long long sol;
int n;
int v[100009];
int a[100009];
int b[100009];

void Citire()
{
    int i;
    f>>n;
    for(i=1;i<=n;i++)
        f>>v[i];
}

void Inter(int a[], int s, int m, int d)
{
	int i,j,k,c[100009];
	i=s;
	j=m+1;
	k=1;
	while(i<=m && j<=d)
		if(a[i]<a[j])
			c[k++]=a[i++];
		else
			c[k++]=a[j++];
	while(i<=m)
		c[k++]=a[i++];
	while(j<=d)
		c[k++]=a[j++];
	k=1;
	for(i=s;i<=d;i++)
		a[i]=c[k++];

}

long long Msort(int v[], int s, int d)
{
    if(s==d)
        return 0;
    int m=(s+d)/2,i,n1=m-s+1,n2=d-m,jMax=0;
    sol=Msort(v,s,m)+Msort(v,m+1,d);
    for(i=s;i<=m;i++)
        a[i-s+1]=v[i];
    for(i=m+1;i<=d;i++)
        b[i-m]=v[i];
    for(i=1;i<=n1;i++)
    {
        while(jMax<n2 && b[jMax+1]<a[i])
            jMax++;
        sol += jMax;
    }
    Inter(v,s,m,d);
    return sol;
}

int main()
{
    Citire();
    g<<Msort(v,1,n)%9917<<"\n";
    return 0;
}
