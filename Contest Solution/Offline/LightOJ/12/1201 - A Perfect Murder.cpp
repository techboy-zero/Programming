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

#define mset(a,v)    memset(a, v, sizeof(a))

using namespace std;

vector <int> edges [1010];
bool visit [1010], bi [1010];
int n, m, par [1010];

void bicolor (int u, bool color) {
    visit [u] = true;
    bi [u] = color;

    int sz = edges [u].size ();
    for (int i = 0; i < sz; i++) {
        int v = edges [u][i];
        if (!visit [v]) bicolor (v, !color);
    }
}

bool Kuhn (int u) {
    if (visit [u]) return false;
    visit [u] = true;
    int sz = edges [u].size ();

    for (int i = 0; i < sz; i++) {
        int v = edges [u][i];
        if (par [v] == -1 || Kuhn (par [v])) {
            par [v] = u;
            return true;
        }
    }

    return false;
}

void Bipartite_matching () {
    mset (par, -1);
    for (int i = 1; i <= n; i++) {
        if (!bi [i]) continue;
        mset (visit, false);
        bool t = Kuhn (i);
    }
}

int main(){

    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n>>m;
        for (int i = 0; i < m; i++) {
            int n1, n2;
            cin>>n1>>n2;
            edges [n1].push_back (n2);
            edges [n2].push_back (n1);
        }

        mset (visit, false);
        for (int i = 1; i <= n; i++)
            if (!visit [i])
                bicolor (i, true);

        Bipartite_matching ();
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += (!bi [i] && par [i] != -1);

        printf ("Case %d: %d\n", kase, n - cnt);

        for (int i = 1; i <= n; i++)
            edges [i].clear ();
    }

    return 0;
}
