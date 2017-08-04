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
    for (int i = 0; i < n; i++) {
        seen [i] = low [i] = 0;
        edges [i].clear ();
    }
    ttl = 0;
    bridgecnt = 0;
}

//DFS is used to find out both articulation points and bridges

void dfs (int u, int par) {
    seen [u] = low [u] = ++ttl;
    int children = 0;

    FOREACH (it,edges [u]) {
        int v = *it;
        if (v == par) continue;
        if (seen [v]) low [u] = min (low [u], seen [v]);
        else {
            children++;
            dfs (v, u);
            low [u] = min (low [u], low [v]);
            if (seen [u] <= low [v] && par != -1) {
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

bool comp (bridges a, bridges b) {
    if (a.u == b.u) return a.v < b.v;
    return a.u < b.u;
}

void sortout () {
    for (int i = 0;  i < bridgecnt; i++) {
        if (br [i].u > br [i].v) {
            swap (br [i].u, br [i].v);
        }
    }
    sort (br, br + bridgecnt, comp);
}

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d", &n);
        Init ();
        for (int i = 1; i <= n; i++) {
            int node, k;
            scanf ("%d ", &node);
            scanf ("(%d)", &k);
            for (int j = 1; j <= k; j++) {
                int adjcnt;
                scanf ("%d", &adjcnt);
                edges [node].push_back (adjcnt);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!seen [i]) dfs (i, -1);
        }
        sortout ();
        printf ("Case %d:\n", kase);
        printf ("%d critical links\n", bridgecnt);
        for (int i = 0; i < bridgecnt; i++) {
            printf ("%d - %d\n", br [i].u, br [i].v);
        }
    }

    return 0;
}
