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

/* Macros */
#define EPS 1e-9
#define PI acos(-1)
#define INF 1e9
#define FOREACH(i,s) for(__typeof((s).end()) i = (s).begin(); i != (s).end(); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5, MAXLG = 20;
int spars [MAX + 7][MAXLG], maxCost [MAX + 7][MAXLG], minCost [MAX + 7][MAXLG], L [MAX + 7];
int par [MAX + 7], dist [MAX + 7];
int t, n, q;

vector <pair <int, int> > edges [MAX + 7];

void dfs (int u, int p, int d) {
    L [u] = d;
    par [u] = p;

    FOREACH (i, edges [u]) {
        int v = i -> first, c = i -> second;
        if (v == p) continue;
        dist [v] = c;
        dfs (v, u, d + 1);
    }
}

void preProcess () {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; (1 << j) <= n; j++) {
            spars [i][j] = -1;
            maxCost [i][j] = -INF;
            minCost [i][j] = INF;
        }
    }
    dist [1] = 0;
    dfs (1, -1, 0);

    for (int i = 1; i <= n; i++) {
        spars [i][0] = par [i];
        maxCost [i][0] = minCost [i][0] = dist [i];
    }

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (spars [i][j - 1] == -1) continue;
            spars [i][j] = spars [spars [i][j - 1]][j - 1];
            maxCost [i][j] = max (maxCost [i][j - 1], maxCost [spars [i][j - 1]][j - 1]);
            minCost [i][j] = min (minCost [i][j - 1], minCost [spars [i][j - 1]][j - 1]);
        }
    }
}

pair <int, int> LCA (int p, int q) {
    if (L [p] < L [q]) swap (p, q);
    int logn, mn = INF, mx = 0;

    for (logn = 1; (1 << logn) <= L [p]; logn++); logn--;
    for (int i = logn; i >= 0; i--) {
        if (L [p] - (1 << i) >= L [q]) {
            mn = min (mn, minCost [p][i]);
            mx = max (mx, maxCost [p][i]);
            p = spars [p][i];
        }
    }

    if (p == q) return make_pair (mn, mx);

    for (int i = logn; i >= 0; i--) {
        if (spars [p][i] != -1 && spars [p][i] != spars [q][i]) {
            mn = min (mn, min (minCost [p][i], minCost [q][i]));
            mx = max (mx, max (maxCost [p][i], maxCost [q][i]));
            p = spars [p][i];
            q = spars [q][i];
        }
    }

    mn = min (mn, min (minCost [p][0], minCost [q][0]));
    mx = max (mx, max (maxCost [p][0], maxCost [q][0]));

    return make_pair (mn, mx);
}

void reset () {
    for (int i = 1; i <= n; i++) edges [i].clear ();
}

int main () {
    //freopen ("input.txt", "r", stdin);
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d", &n);
        reset ();
        for (int i = 1; i < n; i++) {
            int p, q, w;
            scanf ("%d %d %d", &p, &q, &w);
            edges [p].push_back (make_pair (q, w));
            edges [q].push_back (make_pair (p, w));
        }

        preProcess ();
        printf ("Case %d:\n", kase);
        scanf ("%d", &q);
        for (int i = 1; i <= q; i++) {
            int p, q;
            scanf ("%d %d", &p, &q);
            pair <int, int> res = LCA (p, q);
            printf ("%d %d\n", res.first, res.second);
        }
    }
    return 0;
}
