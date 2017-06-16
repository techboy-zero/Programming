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
int seen [MAX];
int low [MAX];
int ttl;
int cntbcc;

vector <int> edges [MAX], path;
vector <pair <int, int> > bridges;
vector <int> bcc [MAX];

void Init () {
    memset (articulation_point, false, sizeof articulation_point);
    for (int i = 1; i <= n; i++) {
        seen [i] = low [i] = 0;
        edges [i].clear ();
    }
    for (int i = 0; i < cntbcc; i++) {
        bcc [i].clear ();
    }
    ttl = 0;
    cntbcc = 0;
    path.clear ();
}

//DFS is used to find out both articulation points and bridges and bcc

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
                bridges.push_back (make_pair (u, v));
            }
        }
    }
    if (children > 1 && par == -1) {
        articulation_point [u] = true;
    }

    if (low [u] == seen [u]) {
        int v;
        do {
            v = path.back();
            path.pop_back();
            bcc [cntbcc].push_back (v);
        } while (v != u);
        cntbcc++;
    }
}
