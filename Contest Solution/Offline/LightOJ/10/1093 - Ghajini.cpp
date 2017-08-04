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

struct tree {
    int mx, mn;
} seg [300010], inf;

int a [100010];

void Init (int node, int l, int r) {
    if (l == r) {
        seg [node].mx = a [l];
        seg [node].mn = a [l];
        return;
    }

    int lft = 2 * node;
    int rght = lft + 1;
    int mid = (l + r) / 2;

    Init (lft, l, mid);
    Init (rght, mid + 1, r);

    seg [node].mx = max (seg [lft].mx, seg [rght].mx);
    seg [node].mn = min (seg [lft].mn, seg [rght].mn);
    return;
}

tree query (int node, int i, int j, int l, int r) {
    if (l > j || r < i) return inf;
    if (l >= i && r <= j) return seg [node];

    int lft = 2 * node;
    int rght = lft + 1;
    int mid = (l + r) / 2;

    tree p1 = query (lft, i, j, l, mid);
    tree p2 = query (rght, i, j, mid + 1, r);
    tree p;
    p.mx = max (p1.mx, p2.mx);
    p.mn = min (p1.mn, p2.mn);

    return p;
}

int main(){
    inf.mx = -INF;
    inf.mn = INF;

    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int n, k;
        scanf ("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) scanf ("%d", &a [i]);
        Init (1, 1, n);
        int mx = 0;
        for (int i = 0; i < n - k; i++) {
            tree temp = query (1, i, i + k - 1, 1, n);
            mx = max (temp.mx - temp.mn, mx);
        }
        printf ("Case %d: %d\n", kase, mx);
    }

    return 0;
}
