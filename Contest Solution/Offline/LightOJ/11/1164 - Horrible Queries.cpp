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
typedef long long ll;

struct tree {
    ll prop;
    ll total;
} seg [300010];

int n, q;

void Init (int node, int l, int r) {
    if (l == r) {
        seg [node].prop = seg [node].total = 0;
        return;
    }

    int lft = 2 * node;
    int rght = lft + 1;
    int mid = (l + r) / 2;

    Init (lft, l, mid);
    Init (rght, mid + 1, r);
    seg [node].prop = seg [node].total = 0;
    return;
}

void update (int node, int i, int j, int l, int r, ll v) {
    if (l > j || r < i) return;
    if (l >= i && r <= j) {
        seg [node].prop += v;
        seg [node].total += (r - l + 1) * v;
        return;
    }

    int lft = 2 * node;
    int rght = lft + 1;
    int mid = (l + r) / 2;

    update (lft, i, j, l, mid, v);
    update (rght, i, j, mid + 1, r, v);
    seg [node].total = seg [lft].total + seg [rght].total + (r - l + 1) * seg [node].prop;
    return;
}

ll query (int node, int i, int j, int l, int r, ll carry) {
    if (l > j || r < i) return 0;
    if (l >= i && r <= j) return seg [node].total + (r - l + 1) * carry;

    int lft = 2 * node;
    int rght = lft + 1;
    int mid = (l + r) / 2;

    ll p1 = query (lft, i, j, l, mid, carry + seg [node].prop);
    ll p2 = query (rght, i, j, mid + 1, r, carry + seg [node].prop);

    return p1 + p2;
}

int main () {
    //freopen ("input.txt", "r", stdin);
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d %d", &n, &q);
        Init (1, 1, n);

        int choice;
        printf ("Case %d:\n", kase);
        for (int i = 1; i <= q; i++) {
            scanf ("%d", &choice);
            if (choice) {
                int l, r;
                scanf ("%d %d", &l, &r);
                printf ("%lld\n", query (1, l + 1, r + 1, 1, n, 0));
            }else {
                int l, r;
                ll v;
                scanf ("%d %d %lld", &l, &r, &v);
                update (1, l + 1, r + 1, 1, n, v);
            }
        }
    }

    return 0;
}
