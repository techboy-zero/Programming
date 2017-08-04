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
#define FOREACH(i,s) for(__typeof ((s).end()) i = (s).begin(); i != (s).end(); i++)

#define sqr(x)        (x*x)
#define cube(x)        (x*x*x)
#define INF            (int)1e9
#define EPS            1e-9

#define mset(a,v)    memset(a, v, sizeof(a))

using namespace std;

const int MAX = 2e4 + 10;
vector <int> edges [MAX], revedges [MAX];
stack <int> order;

bool visit [MAX];
int color, comp [MAX];

int id (int u) {
    if (u < 0) {
        u = -u;
        u--;
        return (u << 1) + 1;
    }
    u--;
    return u << 1;
}

void topo (int u) {
    visit [u] = true;
    FOREACH (v, edges [u]) {
        if (!visit [*v]) {
            topo (*v);
        }
    }
    order.push (u);
}

void scc (int u) {
    visit [u] = true;
    FOREACH (v, revedges [u]) {
        if (!visit [*v]) {
            scc (*v);
        }
    }
    comp [u] = color;
}

void Clean (int m) {
    color = 1;
    mset (visit, false);
    mset (comp, -1);
    for (int i = 0; i < 2 * m; i++) {
        edges [i].clear ();
        revedges [i].clear ();
    }
}

bool twosat (int m) {
    for (int i = 0; i < 2 * m; i += 2) {
        if (comp [i] == comp [i + 1]) {
            return false;
        }
    }
    return true;
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n, m;
        cin >> n >> m;
        Clean (m);

        for (int i = 1; i <= n; i++) {
            int node1, node2;
            cin >> node1 >> node2;
            node1 = id (node1);
            node2 = id (node2);

            edges [node1 ^ 1].push_back (node2);
            edges [node2 ^ 1].push_back (node1);

            revedges [node1].push_back (node2 ^ 1);
            revedges [node2].push_back (node1 ^ 1);
        }

        for (int i = 0; i < 2 * m; i++) {
            if (!visit [i]) {
                topo (i);
            }
        }

        mset (visit, false);
        while (!order.empty ()) {
            int u = order.top ();
            order.pop ();
            if (!visit [u]) {
                scc (u);
                color++;
            }
        }

        printf ("Case %d: ", kase);
        if (!twosat (m)) {
            cout << "No" <<endl;
            continue;
        }
        vector <int> sol;
        for (int i = 0; i < 2 * m; i += 2) {
            if (comp [i] < comp [i + 1]) continue;
            sol.push_back (i / 2);
        }
        int sz = sol.size ();
        cout << "Yes" << endl;
        cout << sz;
        for (int i = 0; i < sz; i++) {
            cout << " " << sol [i] + 1;
        }
        cout << endl;
    }

    return 0;
}
