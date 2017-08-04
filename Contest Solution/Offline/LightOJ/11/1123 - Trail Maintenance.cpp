#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

#define sqr(x) (x*x)
#define cube(x) (x*x*x)

using namespace std;

struct trail
{
    int x,y,cost;
}input;

class comp
{
    public:
    bool operator() (trail &a,trail &b)
    {
        return a.cost>b.cost;
    }
};

int n,m,par[201],counter;

int find_parent(int x)
{
    if (par[x]==x) return x;
    return par[x]=find_parent(par[x]);
}

bool Is_union(int x,int y)   { return (find_parent(x)==find_parent(y)); }
void Make_Union(int x,int y) { par[find_parent(x)]=find_parent(y); }

priority_queue <trail,vector<trail>,comp> pq,temp;

void init(void)
{
    for (int i=1; i<=n; i++)
        par[i]=i;
}

int MST(void)
{
    init();
    int cost=0,cnt=n;
    while (!pq.empty())
    {
        trail e=pq.top();
        pq.pop();
        if (!Is_union(e.x,e.y))
        {
            Make_Union(e.x,e.y);
            cost+=e.cost;
            cnt--;
            temp.push(e);
        }
        if (cnt==1) break;
    }
    pq=temp;
    while(!temp.empty()) temp.pop();

    if (cnt!=1) return -1;
    else        return cost;
}

int main()
{
    #ifdef Local
    freopen("input.txt","r",stdin);
    #endif
    int t;
    scanf("%d",&t);
    for (int i=1; i<=t; i++)
    {
        scanf("%d %d",&n,&m);
        counter=n;
        while (!pq.empty()) pq.pop();

        printf("Case %d:\n",i);
        if (m<n-1)
            for (int j=0; j<m; j++)
            {
                scanf("%d %d %d",&input.x,&input.y,&input.cost);
                printf("-1\n");
            }
        else
        {
            for (int j=0; j<m; j++)
            {
                scanf("%d %d %d",&input.x,&input.y,&input.cost);
                pq.push(input);
                printf("%d\n",MST());
            }
        }
    }

    return 0;
}
