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

vector <int> edges[1010];
int places[110],counter[1010];
bool visit[1010];

void DFS(int u) {
    visit[u]=true;
    counter[u]++;

    int sz=edges[u].size(),v;
    for (int i=0; i<sz; i++) {
        v=edges[u][i];
        if (!visit[v]) DFS(v);
    }
}

void clean(int n) {
    for (int i=1; i<=n; i++)
        edges[i].clear();
}

int main() {
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    for (int kase=1; kase<=t; kase++) {
        int k,n,m,nod1,nod2;
        cin>>k>>n>>m;

        memset(counter,0,sizeof(int)*(n+1));
        for (int i=0; i<k; i++)
            cin>>places[i];

        for (int i=0; i<m; i++) {
            cin>>nod1>>nod2;
            edges[nod1].push_back(nod2);
        }

        for (int i=0; i<k; i++) {
            memset(visit,false,n+1);
            DFS(places[i]);
        }
        int cnt=0;
        for (int i=1; i<=n; i++)
            if (counter[i]==k)
                cnt++;

        printf("Case %d: %d\n",kase,cnt);
        clean(n);
    }

    return 0;
}
