#include <fstream>
#define Mmax 100004

using namespace std;

int x[Mmax],y[Mmax];

int main()
{
    int n, m, k, i;

    ifstream f("stergeri.in");
    f >> n >> m >>k;
    for(i = 1;i <= m; ++i)
        f>>x[i]>>y[i];
    f.close();

    for(i = m; i; --i)
        if(x[i] <= k)
            k += y[i]-x[i]+1;

    ofstream g("stergeri.out");
    g<<k<<"\n";
    g.close();
    return 0;
}
