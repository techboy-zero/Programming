#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

//{{{ ************[  Floating points     ]************
#define ABS(x)          (((x) < 0) ? - (x) : (x))
#define ZERO(x)         (ABS (x) < EPS)
#define EQUAL(x, y)     (ZERO ((x) - (y)))
#define FOREACH(i, s)   for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); i++)

#define sqr(x)        (x*x)
#define cube(x)        (x*x*x)
#define INF            (int)1e9
#define EPS            1e-9

#define mset(a,v)    memset(a, v, sizeof(a))

using namespace std;

vector <int> g [50010], gr [50010], order, component [50010];
set <int> newlist [50010];

int n, in, par [50010], cnt;
bool visit [50010], first;

void dfs1 (int u) {
    visit [u] = true;

    FOREACH(i, g [u]) {
        int v = *i;
        if (!visit [v]) dfs1 (v);
    }
    if (first) order.push_back (u);
    else cnt++;
}

void dfs2 (int u) {
    visit [u] = true;

    FOREACH(i, gr [u]) {
        int v = *i;
        if (!visit [v]) dfs2 (v);
    }
    component [in].push_back (u);
}

void dfs3 (int u) {
    visit [u] = true;

    FOREACH(i, newlist [u]) {
        int v = *i;
        if (!visit [v]) dfs3 (v);
    }
    order.push_back (u);
}

void parent (int i) {
    FOREACH(j, component [i])
        par [*j] = i;
}

void compress () {
    for (int i = 1; i < in; i++)
        parent (i);

    for (int u = 1; u <= n; u++) {
        FOREACH(i, g [u]) {
            int v = *i;
            if (par [v] == par [u]) continue; //avoid self loop
            newlist [par [u]].insert (par [v]);
        }
    }
}

void Clean () {
    for (int i = 1; i <= n; i++) { g [i].clear (); gr [i].clear (); }
    for (int i = 1; i < in; i++) { newlist [i].clear(); component [i].clear (); }
    order.clear ();
}

int main(){

    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n;
        for (int i = 0; i < n; i++) {
            int n1, n2;
            cin>>n1>>n2;
            g [n1].push_back (n2);
            gr [n2].push_back (n1);
        }

        mset (visit, false); first = true;
        for (int i = 1; i <= n; i++)
            if (!visit [i]) dfs1 (i);

        mset (visit, false); first = false;
        in = 1;
        for (int i = 1; i <= n; i++) {
            int u = order [n - i];
            if (!visit [u]) {dfs2 (u); sort (component [in].begin (), component [in].end ()); in++;}
        }

        compress ();
        order.clear ();
        mset (visit, false);
        for (int u = 1; u < in; u++)
            if (!visit [u]) dfs3 (u);

        int mx = -1, mxindx = INF;
        for (int u = 1; u < in; u++) {
            mset (visit, false);
            int v = order [in - u - 1];

            cnt = 0;
            dfs1 (component [v][0]);
            if (cnt > mx) { mx = cnt; mxindx = component [v][0]; }
            if (cnt == mx) mxindx = min (component [v][0], mxindx);
        }

        printf ("Case %d: %d\n", kase, mxindx);

        Clean ();
    }
    return 0;
}
