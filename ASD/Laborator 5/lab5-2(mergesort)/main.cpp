#include <iostream>

using namespace std;

void interclasare(int st, int dr, int v[])
{
    int mij=(st+dr)/2;
    int i=st;
    int j=mij+1;
    int temp[dr-st+1];
    int index=0;
    while(i<=mij && j<=dr)
    {
        if(v[i]<v[j])
            temp[index++]=v[i++];
        else temp[index++]=v[j++];
    }
    while(i<=mij)
    {
        temp[index++]=v[i++];
    }
    while(j<=dr)
    {
        temp[index++]=v[j++];
    }
    for(i=0; i<index; i++)
    {
        v[st+i]=temp[i];
    }
}
void mergesort(int st, int dr, int v[])
{
    if(st<dr)
    {
        int mij=(st+dr)/2;
        mergesort(st,mij,v);
        mergesort(mij+1,dr,v);
        interclasare(st,dr,v);
    }
}
int main()
{
    int n, i, v[100];
    cout<<"n=";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>v[i];
    }
    mergesort(0,n-1,v);
    for(i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
