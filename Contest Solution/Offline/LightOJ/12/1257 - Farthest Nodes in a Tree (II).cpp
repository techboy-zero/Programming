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
#define FOREACH(i,s) for(__typeof((s).end()) i = (s).begin(); i != (s).end(); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 3e4;
vector < pair <int, int> > edges [MAX + 7];
int dist [MAX + 7], mx, far, n;

void dfs (int u, int p, int d) {
    if (d > mx) {
        mx = d;
        far = u;
    }
    dist [u] = max (dist [u], d);

    FOREACH (i, edges [u]) {
        int v = i -> first, w = i -> second;
        if (v == p) continue;
        dfs (v, u, d + w);
    }
}

void Reset () {
    memset (dist, 0, sizeof (dist));
    for (int i = 0; i <= n; i++) edges [i].clear ();
}

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d", &n);
        Reset ();
        for (int i = 1; i < n; i++) {
            int p, q, w;
            scanf ("%d %d %d", &p, &q, &w);
            edges [p].push_back (make_pair (q, w));
            edges [q].push_back (make_pair (p, w));
        }
        mx = -1;
        dfs (0, -1, 0);
        mx = -1;
        dfs (far, -1, 0);
        dfs (far, -1, 0);

        printf ("Case %d:\n", kase);
        for (int i = 0; i < n; i++) printf ("%d\n", dist [i]);
    }
    return 0;
}
