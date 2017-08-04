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

struct bio {
    int h, a;
    bool d;
}a [110];

int n, m, par [110];
vector <int> edges [110];
bool visit [110];

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
    mset (par, - 1);
    for (int i = 0; i < n; i++) {
        mset (visit, false);
        bool t = Kuhn (i);
    }
}

int main(){
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n>>m;
        for (int i = 0; i < n + m; i++)
            cin>>a [i].h >> a [i].a >> a [i].d;

        for (int i = 0; i < n; i++) {
            for (int j = n; j < n + m; j++) {
                if (abs (a [i].h - a [j].h) <= 12 && abs (a [i].a - a [j].a) <= 5 && a [i].d == a [j].d) {
                    edges [i].push_back (j);
                    edges [j].push_back (i);
                }
            }
        }

        Bipartite_matching ();
        int cnt = 0;
        for (int i = n; i < n + m; i++)
            cnt += (par [i] != -1);
        printf ("Case %d: %d\n", kase, cnt);

        for (int i = 0; i < n + m; i++)
            edges [i].clear ();
    }
    return 0;
}
