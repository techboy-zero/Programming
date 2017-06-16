#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 2e4 + 7;

bool visit [MAX];
int par [MAX];

vector <int> order;
vector <int> edges [MAX];
vector <int> revedges [MAX];
vector <int> component [MAX];
set <int> newList [MAX];

void dfs (int u) {
    visit [u] = true;
    FOREACH(v, edges [u]) {
        if (!visit [*v]) dfs (*v);
    }
    order.push_back (u);
}

void kosaraju (int u, int comp) {
    par [u] = comp;
    FOREACH(v, revedges [u]) {
        if (!par [*v]) kosaraju (*v, comp);
    }
    component [comp].push_back (u);
}

void compress () {
    FOREACH(u, order) {
        FOREACH(v, edges [*u]) {
            if (par [*v] == par [*u]) continue;
            if (newList [par [*u]].find (par [*v]) == newList [par [*u]].end ()) {
                newList [par [*u]].insert (par [*v]);
            }
        }
    }
}

void Clean (int comp) {
    for (int i = 1; i <= comp; i++) {
        component [i].clear ();
        newList [i].clear ();
    }
    for (int i = 1; i <= n; i++) {
        edges [i].clear ();
        revedges [i].clear ();
    }
    order.clear ();
    memset (visit, false, sizeof visit);
    memset (par, 0, sizeof par);
}
