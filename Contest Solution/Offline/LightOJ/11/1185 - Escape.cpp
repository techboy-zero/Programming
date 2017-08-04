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

vector <int> edges[110];
bool visit[110][2],carry[110],first;

int n,m,mx;

void DFS(int u,bool stat) {
    if (first) visit[u][stat]=true;
    if (stat && first) carry[u]=stat;
    first=true;
    stat=!stat;

    int sz=edges[u].size();
    for (int i=0; i<sz; i++) {
        int v=edges[u][i];
        if (!visit[v][stat]) DFS(v,stat);
    }
}

int carry_counter() {
    int cnt=0;
    for (int i=1; i<=n; i++)
        if (carry[i])
            cnt++;

    return cnt;
}

void Clean() {
    for (int i=1; i<=n; i++)
        edges[i].clear();
    memset(carry,false,sizeof(carry));
    memset(visit,false,sizeof(visit));
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    for (int kase=1; kase<=t; kase++) {
        int nod1,nod2;
        cin>>n>>m;

        for (int i=0; i<m; i++) {
            cin>>nod1>>nod2;
            edges[nod1].push_back(nod2);
            edges[nod2].push_back(nod1);
        }

        first=false;
        DFS(1,true);

        printf("Case %d: %d\n",kase,carry_counter());
        Clean();
    }

    return 0;
}
