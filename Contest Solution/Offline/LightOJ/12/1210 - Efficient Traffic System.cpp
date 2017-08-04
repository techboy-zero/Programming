#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 2e4 + 7;

int n;
int m;

bool visit [MAX];
int par [MAX];
int indegree [MAX];
int outdegree [MAX];

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
                indegree [par [*v]]++;
                outdegree [par [*u]]++;
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
    memset (indegree, 0, sizeof indegree);
    memset (outdegree, 0, sizeof outdegree);
}

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            int n1, n2;
            scanf ("%d %d", &n1, &n2);
            edges [n1].push_back (n2);
            revedges [n2].push_back (n1);
        }
        for (int i = 1; i <= n; i++) {
            if (!visit [i]) dfs (i);
        }

        int comp = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (!par [order [i]]) {
                ++comp;
                kosaraju (order [i], comp);
            }
        }
        compress ();
        int incnt = 0, outcnt = 0;
        for (int i = 1; i <= comp; i++) {
            if (!indegree [i]) incnt++;
            if (!outdegree [i]) outcnt++;
        }
        if (comp == 1) incnt = outcnt = 0;
        printf ("Case %d: %d\n", kase, max (incnt, outcnt));
        Clean (comp);
    }

    return 0;
}
