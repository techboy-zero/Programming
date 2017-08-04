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

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e2, MAXE = 1e4;

struct edges {
    int x, y, inc, exp;
} road [MAXE + 7];

int n, r, p;
pair <int, int> cost [MAX + 7];

void Init () {
    for (int i = 0; i < n; i++) {
        cost [i].first = 0;
        cost [i].second = 0;
    }
}

bool profit (ll a, ll b, ll c, ll d) {
    return (a - b * p) > (c - d * p);
}

void bellmanFord (int kase) {
    Init ();
    bool update;
    for (int i = 0; i < n; i++) {
        update = false;
        for (int j = 0; j < r; j++) {
            int u = road [j].x, v = road [j].y, inc = road [j].inc, exp = road [j].exp;
            if (cost [u].first == -INF) continue;
            if (profit (cost [u].first + inc, cost [u].second + exp, cost [v].first, cost [v].second)) {
                cost [v].first = cost [u].first + inc;
                cost [v].second = cost [u].second + exp;
                update = true;
            }
        }
    }
    printf ("Case %d: ", kase);
    if (update) printf ("YES\n");
    else printf ("NO\n");
}

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d %d %d", &n, &r, &p);
        for (int i = 0; i < r; i++) {
            scanf ("%d %d %d %d", &road [i].x, &road [i].y, &road [i].inc, &road [i].exp);
        }
        bellmanFord (kase);
    }
    return 0;
}
