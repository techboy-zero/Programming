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

struct edges
{
    int n1,n2,cost;
}array[12001];

int t,n,par[101],n1,n2,cost,in;
long long total;

int findparent(int x)
{
    if (par[x]==x) return x;

    return par[x]=findparent(par[x]);
}

void makeunion(int x,int y)
{
    par[findparent(x)]=findparent(y);
}

inline bool isunion(int x,int y)
{
    return (findparent(x)==findparent(y));
}

inline bool comp1(edges a,edges b)
{
    return a.cost<b.cost;
}

inline bool comp2(edges a,edges b)
{
    return a.cost>b.cost;
}

int main()
{
    cin>>t;

    for (int i=1; i<=t; i++)
    {
        cin>>n;
        in=0;

        while (cin>>n1>>n2>>cost && (n1+n2+cost) )
        {
            array[in].n1=n1;
            array[in].n2=n2;
            array[in].cost=cost;
            in++;
        }

        for (int j=0; j<=n; j++)
            par[j]=j;

        total=0;

        sort(array,array+in,comp1);

        for (int j=0; j<in; j++)
        {
            int p1=array[j].n1, p2=array[j].n2;

            if ( !isunion(p1,p2) )
            {
                makeunion(p1,p2);
                total+=array[j].cost;
            }
        }

        for (int j=0; j<=n; j++)
            par[j]=j;

        sort(array,array+in,comp2);

        for (int j=0; j<in; j++)
        {
            int p1=array[j].n1, p2=array[j].n2;

            if ( !isunion(p1,p2) )
            {
                makeunion(p1,p2);
                total+=array[j].cost;
            }
        }

        printf("Case %d: ",i);

        if (total%2) cout<<total<<"/"<<2<<endl;
        else         cout<<total/2<<endl;
    }

    return 0;
}
