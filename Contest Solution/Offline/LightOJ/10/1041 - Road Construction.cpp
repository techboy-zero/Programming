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

struct road
{
    int n1,n2,cost;
}array[51];

int t,n,cost,in,par[101];
char city1[51],city2[51];

map <string,int> cities;

int findparent(int x)
{
    if (par[x]==x) return x;

    return par[x]=findparent(par[x]);
}

inline void makeunion(int x,int y)
{
    par[findparent(x)]=findparent(y);
}

inline bool isunion(int x,int y)
{
    return (findparent(x)==findparent(y));
}

inline bool comp(road a,road b)
{
    return a.cost<b.cost;
}

int main()
{
    cin>>t;

    for (int i=1; i<=t; i++)
    {
        cin>>n;
        in=0;

        for (int j=0; j<n; j++)
        {
            cin>>city1>>city2>>cost;

            if (!cities[city1])
            {
                cities[city1]=++in;
                par[in]=in;
            }
            if (!cities[city2])
            {
                cities[city2]=++in;
                par[in]=in;
            }

            array[j].n1=cities[city1];
            array[j].n2=cities[city2];
            array[j].cost=cost;
        }

        int cnt=in,total=0;

        sort(array,array+n,comp);

        for (int j=0; j<n; j++)
        {
            int p1=array[j].n1, p2=array[j].n2;

            if (!isunion(p1,p2))
            {
                makeunion(p1,p2);
                total+=array[j].cost;
                cnt--;
            }
        }

        printf("Case %d: ",i);

        if (cnt>1) cout<<"Impossible"<<endl;
        else       cout<<total<<endl;

        cities.clear();
    }

    return 0;
}
