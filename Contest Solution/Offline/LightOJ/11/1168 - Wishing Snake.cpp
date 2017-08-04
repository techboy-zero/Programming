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

#define sqr(x)        (x*x)
#define cube(x)        (x*x*x)
#define INF            (int)1e9
#define EPS            1e-9
#define FOREACH(i, s)   for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

#define mset(a,v)    memset(a, v, sizeof(a))

using namespace std;
typedef long long ll;

int t, n, w, par [1010], in, cnt;
bool check [1010], visit [1010];

vector <int> g [1010], gr [1010], component [1010], order;
set <int> newList [1010];
bool possible;

void dfs1 (int u) {
    visit [u] = true;
    FOREACH(i, g [u]) {
        int v = *i;
        if (!visit [v]) dfs1 (v);
    }
    order.push_back (u);
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
    FOREACH(i, newList [u]) {
        if (i != newList [u].begin()) possible = false;
        int v = *i;
        if (!visit [v]) dfs3 (v);
    }
    cnt++;
}

void parent (int u) {
    FOREACH(v, component [u])
        par [*v] = u;
}

void compress () {
    for (int i = 1; i < in; i++)
        parent (i);

    int sz = order.size ();
    for (int i = 1; i <= sz; i++) {
        int u = order [sz - i];
        FOREACH(v, g [u]) {
            if (par [*v] == par [u]) continue;
            if (newList [par [u]].find (par [*v]) == newList [par [u]].end ()) newList [par [u]].insert (par [*v]);
            else possible = false;
        }
    }
}

void SCC () {
    mset (visit, false);
    for (int u = 0; u < 1000; u++)
        if (check [u] && !visit [u])
            dfs1 (u);

    mset (visit, false);
    int sz = order.size ();
    for (int u = 1; u <= sz; u++) {
        int v = order [sz - u];
        if (!visit [v]) {
            dfs2 (v);
            sort (component [in].begin (), component [in].end ());
            in++;
        }
    }
}

void Clean () {
    for (int i = 1; i < in; i++) { component [i].clear (); newList [i].clear (); }
    for (int i = 0; i < 1000; i++) { g [i].clear (); gr [i].clear (); }
    order.clear ();
    mset (check, false);
}

int main() {
    //freopen ("input.txt","r",stdin);
    cin>>t;
    for (int kase = 1; kase <= t; kase++) {
        in = 1;
        possible = true;

        cin>>n;
        for (int i = 0; i < n; i++) {
            cin>>w;
            for (int j = 0; j < w; j++) {
                int n1, n2;
                cin>>n1>>n2;
                check [n1] = check [n2] = true;
                g [n1].push_back (n2);
                gr [n2].push_back (n1);
            }
        }

        check [0] = true;
        SCC ();
        compress ();

        int zero;
        for (int i = 1; i < in; i++)
            if (component [i][0] == 0) {
                zero = i;
                break;
            }
        mset (visit, false);
        cnt = 0;
        dfs3 (zero);

        if ((cnt == in - 1) && possible) printf ("Case %d: YES\n", kase);
        else printf ("Case %d: NO\n", kase);

        Clean ();
    }
    return 0;
}
