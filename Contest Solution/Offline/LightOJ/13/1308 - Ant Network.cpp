#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e4 + 7, MAXE = 2e4 + 7;

bool articulation_point [MAX];
bool visited [MAX];
int color [MAX];
int seen [MAX];
int low [MAX];

int n, m;
int ttl;
int cnt;
int coloredcomponent;
int artpoints;

vector <int> edges [MAX], path;
vector <int> bcc [MAX];

void Init () {
    memset (articulation_point, false, sizeof articulation_point);
    memset (visited, false, sizeof visited);
    for (int i = 0; i < n; i++) {
        color [i] = -1;
        seen [i] = low [i] = 0;
        edges [i].clear ();
    }
    ttl = 0;
    coloredcomponent = 0;
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
        }
    }
    if (children > 1 && par == -1) {
        articulation_point [u] = true;
    }
}

void dfs2 (int u) {
    visited [u] = true;
    cnt++;
    FOREACH (it, edges [u]) {
        int v = *it;
        if (!visited [v] && !articulation_point [v]) {
            dfs2 (v);
        }
        if (articulation_point [v] && color [v] != coloredcomponent) {
            color [v] = coloredcomponent;
            artpoints++;
        }
    }
}

int main () {
    //freopen ("input.txt", "r", stdin);
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d %d", &n, &m);
        Init ();
        for (int i = 1; i <= m; i++) {
            int node1, node2;
            scanf ("%d %d", &node1, &node2);
            edges [node1].push_back (node2);
            edges [node2].push_back (node1);
        }
        dfs (0, -1);
        ull ans = 1;
        int shaft = 0;
        for (int i = 0; i < n; i++) {
            if (!visited [i] && !articulation_point [i]) {
                artpoints = cnt = 0;
                coloredcomponent++;
                dfs2 (i);
                if (artpoints < 2) {
                    shaft++;
                    ans *= cnt;
                }
            }
        }
        if (shaft == 1) {
            shaft++;
            ans = (n * (n - 1) / 2);
        }
        printf ("Case %d: %d %llu\n", kase, shaft, ans);
    }

    return 0;
}
