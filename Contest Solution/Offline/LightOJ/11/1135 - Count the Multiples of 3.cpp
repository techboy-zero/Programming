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

#define sqr(x)   (x*x)
#define cube(x)  (x*x*x)
#define INF      (int)1e9
#define EPS      1e-9
#define lc(x)   2 * x
#define rc(x)   2 * x + 1

#define mset(a,v)    memset(a, v, sizeof(a))

using namespace std;

struct tree {
    int prop;
    int a [4];
}seg [300010];

void merge_child (int node) {
    int lft = lc (node), rght = rc (node);
    int lp = seg [lft].prop, rp = seg [rght].prop;

    for (int i = 0; i < 3; i++)
        seg [node].a [i] = seg [lft].a [(i + lp) % 3] + seg [rght].a [(i + rp) % 3];
    seg [node].prop = 0;
}

void split (int node) {
    int lft = lc (node), rght = rc (node);
    seg [lft].prop += seg [node].prop;  seg [lft].prop %= 3;
    seg [rght].prop += seg [node].prop; seg [rght].prop %= 3;
}

void Init (int node, int l, int r) {
    if (l == r) {
        seg [node].prop = 0;
        mset (seg [node].a, 0);
        seg [node].a [0] = 1;
        return;
    }

    int mid = (l + r) / 2;
    Init (lc (node), l, mid);
    Init (rc (node), mid + 1, r);
    merge_child (node);
    return;
}

void update (int node, int i, int j, int l, int r) {
    if (l > j || r < i) return;
    if (l >= i && r <= j) {
        seg [node].prop++;
        seg [node].prop %= 3;
        return;
    }

    if (seg [node].prop) split (node);
    int mid = (l + r) / 2;
    update (lc (node), i, j, l, mid);
    update (rc (node), i, j, mid + 1, r);
    merge_child (node);
    return;
}

int query (int node, int i, int j, int l, int r) {
    if (l > j || r < i) return 0;
    if (l >= i && r <= j) return seg [node].a [seg [node].prop % 3];

    int mid = (l + r) / 2;
    if (seg [node].prop) split (node);
    int p1 = query ( lc (node), i, j, l, mid);
    int p2 = query ( rc (node), i, j, mid + 1, r);
    merge_child (node);
    return p1 + p2;
}

int main(){
    //freopen ("input.txt", "r", stdin);
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int n, q;
        scanf ("%d %d", &n, &q);
        Init (1, 1, n);
        printf ("Case %d:\n", kase);
        while (q--) {
            int c, i, j;
            scanf ("%d %d %d", &c, &i, &j);
            i++; j++;

            if (!c) update (1, i, j, 1, n);
            else printf ("%d\n", query (1, i, j, 1, n));
        }
    }
    return 0;
}
