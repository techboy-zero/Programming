#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e4 + 7, MAXE = 1e5 + 7;

struct bridges {
    int u, v;
} br [MAXE];

int n, m;
bool articulation_point [MAX];
bool visited [MAX];
int seen [MAX];
int low [MAX];
int parent [MAX];
int ttl;
int bridgecnt;

vector <int> edges [MAX];

void Init () {
    memset (articulation_point, false, sizeof articulation_point);
    for (int i = 1; i <= n; i++) {
        seen [i] = low [i] = 0;
        parent [i] = -1;
        edges [i].clear ();
    }
    ttl = 0;
    bridgecnt = 0;
}

//DFS is used to find out both articulation points and bridges

void dfs (int u) {
    seen [u] = low [u] = ++ttl;
    int children = 0;

    FOREACH (it,edges [u]) {
        int v = *it;
        if (v == parent [u]) continue;
        if (seen [v]) low [u] = min (low [u], seen [v]);
        else {
            children++;
            parent [v] = u;
            dfs (v);
            low [u] = min (low [u], low [v]);
            if (seen [u] <= low [v] && parent [u] != -1) {
                articulation_point [u] = true;
            }
            if (seen [v] == low [v]) {
                br [bridgecnt].u = u;
                br [bridgecnt++].v = v;
            }
        }
    }
    if (children > 1 && parent [u] == -1) {
        articulation_point [u] = true;
    }
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> n >> m;
        Init ();
        for (int i = 1; i <= m; i++) {
            int node1, node2;
            cin >> node1 >> node2;
            edges [node1].push_back (node2);
            edges [node2].push_back (node1);
        }
        dfs (1);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (articulation_point [i]) cnt++;
        }
        printf ("Case %d: %d\n", kase, cnt);
    }

    return 0;
}
