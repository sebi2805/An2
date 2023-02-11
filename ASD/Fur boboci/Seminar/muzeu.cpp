#include<cstdio>
#include<queue>
using namespace std;
struct Coord
{
    int lin,col,cost;
    bool operator < (const Coord&z) const
    {
        return cost>z.cost;
    }
};
int a[260][260],n;
priority_queue<Coord>q;
void Afisare();
void Bordare();

void Citire()
{
    int i,j;
    char ch;
    Coord p;
    freopen("muzeu.in","r",stdin);
    freopen("muzeu.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%c",&ch);
        for(j=1;j<=n;j++)
        {
            scanf("%c",&ch);
            if(ch=='#')
                a[i][j]=-2;
                else
            if(ch=='P')
            {
                p.lin = i;
                p.col = j;
                p.cost = 0;
                q.push(p);
            }
            else
                a[i][j]=-1;
        }
    }
}

void Lee()
{
    int dl[]={0 ,-1, 0, 1};
    int dc[]={-1, 0, 1, 0};
    Coord p,v;
    int i;
    while(!q.empty())
    {
        p = q.top();
        q.pop();
        for(i=0;i<4;i++)
        {
            v.lin = p.lin+ dl[i];
            v.col = p.col+ dc[i];
            if(a[v.lin][v.col]==-1)
            {
                a[v.lin][v.col] = a[p.lin][p.col]+1;
                v.cost = a[v.lin][v.col];
                q.push(v);
            }
            else
            {
                if(a[v.lin][v.col] > a[p.lin][p.col]+1)
                {
                    a[v.lin][v.col] = a[p.lin][p.col]+1;
                    v.cost = a[v.lin][v.col];
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    Citire();
    Bordare();
    Lee();
    Afisare();
    return 0;
}

void Bordare()
{
    int i;
    for(i=0;i<=n+1;i++)
        a[i][0]=a[i][n+1]=a[0][i]=a[n+1][i]=-2;
}

void Afisare()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
