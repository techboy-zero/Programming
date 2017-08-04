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
#define INF 999999999
#define MOD 100000007

using namespace std;

int sz[60],par[60],connections;

struct edges {
    int x,y,cost;
}edgelist[2550];

int find_parent(int x) {
    if (par[x]==x) return x;
    return par[x]=find_parent(par[x]);
}

bool is_united(int x,int y) {
    return find_parent(x)==find_parent(y);
}

void make_united(int x,int y) {
    int u=find_parent(x);
    int v=find_parent(y);

    if (sz[u]<sz[v]) swap(u,v);
    par[v]=u;
    sz[u]+=sz[v];
}

void set_parent(int n) {
    connections=n;

    for (int i=1; i<=n; i++) {
        par[i]=i;
        sz[i]=1;
    }
}

bool comp(edges a,edges b) {
    return a.cost<b.cost;
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    for (int kase=1; kase<=t; kase++) {
        int n,in=0,total=0,value;
        cin>>n;
        set_parent(n);

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cin>>value;
                if (i==j && value) total+=value;
                else if (i!=j && value) {
                    in++;
                    edgelist[in].x=i;
                    edgelist[in].y=j;
                    edgelist[in].cost=value;
                }
            }
        }

        sort(edgelist,edgelist+in+1,comp);

        for (int i=1; i<=in; i++) {
            if (!is_united(edgelist[i].x,edgelist[i].y)) {
                make_united(edgelist[i].x,edgelist[i].y);
                connections--;
            }
            else total+=edgelist[i].cost;
        }

        printf("Case %d: %d\n",kase,connections==1?total:-1);
    }

    return 0;
}
