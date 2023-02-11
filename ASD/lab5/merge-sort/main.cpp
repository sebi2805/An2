#include <iostream>
using namespace std;
int v[100], n;

/* Ordoneaza un subvector */
void ordonare(int p,int u)
{
    int aux;
    if(v[p]>v[u])
    {
        aux=v[p];
        v[p]=v[u];
        v[u]=aux;
    }
}

void interclasare(int p,int u,int m)
{
    int i,j,a[1000],k=0;
    i=p;
    j=m+1;
    while(i<=m && j<=u)
        if(v[i]<v[j])
        {
            k++;
            a[k]=v[i];
            i++;
        }
        else
        {
            k++;
            a[k]=v[j];
            j++;
        }
    if(i<=m)
        for(j=i; j<=m; j++)
        {
            k++;
            a[k]=v[j];
        }
    else for(i=j; i<=u; i++)
        {
            k++;
            a[k]=v[i];
        }
    for(i=1; i<=k; i++)
        v[p+i-1]=a[i];
}

/* Divide vectorul in mai multe submultimi */
void divide(int p,int u)
{
    int m;
    if(u-p <= 1)
        ordonare(p,u);
    else
    {
        m=(p+u)/2;
        divide(p,m);
        divide(m+1,u);
        interclasare(p,u,m);
    }
}

int main()
{
    int i;
    cout<<"Dati lungimea vectorului:";
    cin>>n;
    for(i=1; i<=n; i++)
        {   cout<<"v["<<i<<"]= ";
            cin>>v[i];
        }
    divide(1,n);
    for(i=1; i<=n; i++)
        cout<<v[i]<<" ";

    return 0;
}
