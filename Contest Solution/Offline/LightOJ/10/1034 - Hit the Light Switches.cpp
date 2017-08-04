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

vector <int> edges[10010];
stack  <int> order;
int n,m;
bool visit[10010];

void dfs1(int u) {
    visit[u]=true;

    int sz=edges[u].size();
    for (int i=0; i<sz; i++) {
        int v=edges[u][i];
        if (!visit[v])
            dfs1(v);
    }

    order.push(u);
}

void dfs2(int u) {
    visit[u]=true;

    int sz=edges[u].size();
    for (int i=0; i<sz; i++) {
        int v=edges[u][i];
        if (!visit[v])
            dfs2(v);
    }
}

void Clean() {
    for (int i=1; i<=n; i++)
        edges[i].clear();
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    for (int kase=1; kase<=t; kase++) {
        cin>>n>>m;
        memset(visit,false,n+1);

        for (int i=1; i<=m; i++) {
            int nod1,nod2;
            cin>>nod1>>nod2;
            edges[nod1].push_back(nod2);
        }

        for (int i=1; i<=n; i++)
            if (!visit[i])
                dfs1(i);

        memset(visit,false,n+1);
        int cnt=0;
        while(!order.empty()) {
            int u=order.top();
            order.pop();

            if (!visit[u]) {
                cnt++;
                dfs2(u);
            }
        }

        printf("Case %d: %d\n",kase,cnt);
        Clean();
    }

    return 0;
}
