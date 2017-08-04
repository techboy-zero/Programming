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

void dfs (int u, int p) {
    FOREACH (i, edges [u]) {
        int v = i -> first, w = i -> second;
        if (v == p) continue;
        dist [v] = dist [u] + w;

        if (mx < dist [v]) {
            mx = dist [v];
            far = v;
        }
        dfs (v, u);
    }
}

void Reset () {
    for (int i = 0; i <= n; i++) edges [i].clear ();
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> n;
        Reset ();
        for (int i = 1; i < n; i++) {
            int p, q, w;
            cin >> p >> q >> w;
            edges [p].push_back (make_pair (q, w));
            edges [q].push_back (make_pair (p, w));
        }

        dist [0] = 0;
        mx = -1;
        dfs (0, -1);

        dist [far] = 0;
        mx = -1;
        dfs (far, -1);

        printf ("Case %d: %d\n", kase, mx);
    }
    return 0;
}
