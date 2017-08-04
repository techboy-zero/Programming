/* C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/* C++ STL */
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <utility>

/* Macros */
#define EPS 1e-9
#define INF 1e9
#define PI acos(-1)
#define FOREACH(i,s) for(__typeof((s).end()) i = (s).begin(); i != (s).end(); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5, MAXLG = 20;

struct tree {
    int x, y, cost;
} ar [MAX + 7];

vector < pair <int, int> > edges [MAX + 7];
bool visit [MAX + 7];
int n, m, par [MAX + 7];
int L [MAX + 7], T [MAX + 7], spars [MAX + 7][MAXLG], maxCost [MAX + 7][MAXLG];

/*MST*/
int findparent (int x) {return par [x] = par [x] == x? x : findparent (par [x]);}
bool isunion (int x, int y) {return findparent (x) == findparent (y);}
void makeunion (int x, int y) {par [findparent (x)] = findparent (y);}
bool comp (tree a, tree b) {
    if (a.cost == b.cost) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    }
    return a.cost < b.cost;
}

void MST () {
    for (int i = 1; i <= n; i++) par [i] = i;
    sort (ar, ar + m, comp);
    for (int i = 0; i < m; i++) {
        if (!isunion (ar [i].x, ar [i].y)) {
            int u = ar [i].x, v = ar [i].y, c = ar [i].cost;
            edges [u].push_back (make_pair (v, c));
            edges [v].push_back (make_pair (u, c));
            makeunion (u, v);
        }
    }
}
/*MST*/

/*LCA*/
void dfs (int u, int p, int d) {
    visit [u] = true;
    T [u] = p;
    L [u] = d;
    FOREACH(i, edges [u]){
        int v = i -> first , w = i -> second;
        if(visit [v]) continue;
        spars [v][0] = u;
        maxCost [v][0] = w;
        dfs (v, u, d + 1);
    }
}

void tableGen () {
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 0 ; (1 << j) <= n; j++) {
            spars [i][j] = -1;
            maxCost [i][j] = -INF;
        }
    }

    dfs(1, -1, 0);
    for(int j = 1; (1 << j) < n; j++) {
        for(int i = 1 ; i <= n; i++) {
            if(spars [i][j - 1] == -1) continue;
            spars [i][j] = spars [spars [i][j - 1]][j - 1];
            maxCost [i][j] = max (maxCost [i][j - 1], maxCost [spars [i][j - 1]][j - 1]);
        }
    }
}

int query (int a, int b) {
    if (L [a] < L [b]) swap (a, b);
    int mx = 0;
    int logn;
    for (logn = 1; (1 << logn) <= L [a]; logn++);
    logn--;
    for (int i = logn; i >= 0; i--) {
        if (L [a] - (1 << i) >= L [b]) {
            mx = max (mx, maxCost [a][i]);
            a = spars [a][i];
        }
    }
    if (a == b) return mx;

    for (int i = logn; i >= 0; i--) {
        if (spars [a][i] != -1 && spars [a][i] != spars [b][i]) {
            mx = max (mx, max (maxCost [a][i], maxCost [b][i]));
            a = spars [a][i];
            b = spars [b][i];
        }
    }
    mx = max (mx, max (maxCost [a][0], maxCost [b][0]));

    return mx;
}
/*LCA*/

void Clean () {
    for (int i = 1; i <= n; i++) edges [i].clear ();
    memset (visit, false, sizeof (visit));
    memset (spars, -1, sizeof (spars));
}

int main () {
    //freopen ("input.txt", "r", stdin);
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf ("%d %d %d", &ar [i].x, &ar [i].y, &ar [i].cost);
        }
        MST ();
        tableGen ();
        int q;
        scanf ("%d", &q);
        printf ("Case %d:\n", kase);
        for (int i = 1; i <= q; i++) {
            int n1, n2;
            scanf ("%d %d", &n1, &n2);
            printf ("%d\n", query (n1, n2));
        }
        Clean ();
    }

    return 0;
}
