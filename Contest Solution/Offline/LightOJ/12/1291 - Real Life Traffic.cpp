#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e4 + 7, MAXE = 1e5 + 7;

int n, m;
bool articulation_point [MAX];
bool visited [MAX];

int component [MAX];
int seen [MAX];
int low [MAX];
int ttl;
int cntbcc;

vector <int> edges [MAX], path;
map <int, bool> bridges [MAX];
vector <int> bcc [MAX];
set <int> newList [MAX];

void Init () {
    memset (articulation_point, false, sizeof articulation_point);
    memset (visited, false, sizeof visited);
    for (int i = 0; i < n; i++) {
        seen [i] = low [i] = 0;
        edges [i].clear ();
        newList [i].clear ();
        bridges [i].clear ();
    }
    for (int i = 0; i < cntbcc; i++) {
        bcc [i].clear ();
    }
    ttl = 0;
    cntbcc = 0;
    path.clear ();
}

void dfs (int u, int par) {
    seen [u] = low [u] = ++ttl;
    int children = 0;
    path.push_back (u);

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
                bridges [u][v] = bridges [v][u] = true;
            }
        }
    }
    if (children > 1 && par == -1) {
        articulation_point [u] = true;
    }
}

void dfs2 (int u) {
    visited [u] = true;
    component [u] = cntbcc;
    FOREACH (it,edges [u]) {
        int v = *it;
        if (!visited [v] && bridges [u].find (v) == bridges [u].end ()) {
            dfs2 (v);
        }
    }
}

void compress () {
    for (int u = 0; u < n; u++) {
        FOREACH(v, edges [u]) {
            if (component [*v] == component [u]) continue;
            if (newList [component [u]].find (component [*v]) == newList [component [u]].end ()) {
                newList [component [u]].insert (component [*v]);
            }
        }
    }
}

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d %d", &n, &m);
        Init ();
        for (int i = 0; i < m; i++) {
            int node1, node2;
            scanf ("%d %d", &node1, &node2);
            edges [node1].push_back (node2);
            edges [node2].push_back (node1);
        }

        dfs (0, -1);
        for (int i = 0; i < n; i++) {
            if (!visited [i]) {
                dfs2 (i);
                cntbcc++;
            }
        }
        printf ("Case %d: ", kase);
        if (cntbcc == 1) printf ("%d\n", 0);
        else {
            compress ();
            int ans = 0;
            for (int i = 0; i < cntbcc; i++) {
                if (newList [i].size () == 1) {
                    ans++;
                }
            }
            if (ans % 2) ans++;
            ans /= 2;
            printf ("%d\n", ans);
        }
    }

    return 0;
}
