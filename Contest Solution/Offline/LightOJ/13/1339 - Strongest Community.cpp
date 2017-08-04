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

/*Segment tree*/
#define Lc(i) (2 * i)
#define Rc(i) (2 * i + 1)
#define Lr(i) (tree [i].l)
#define Rr(i) (tree [i].r)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5;
int ar [MAX + 7], pos [MAX + 7], br [MAX + 7];
int n, c, q;

struct segment {
    int l, r, prop, mx;
} tree [3 * MAX + 7];

struct querylist {
    int l, r, pos;
} qr [MAX + 7];

void mergeup (int i) {
    Lr (i) = Lr (Lc (i));
    Rr (i) = Rr (Rc (i));
    tree [i].mx = max (tree [Lc (i)].mx - tree [Lc (i)].prop, tree [Rc (i)].mx - tree [Rc (i)].prop);
}

void build (int l, int r, int i) {
    if (l == r) {
        tree [i].mx = br [l];
        Lr (i) = Rr (i) = l;
        tree [i].prop = 0;
        return;
    }

    int mid = (l + r) >> 1;
    build (l, mid, Lc (i));
    build (mid + 1, r, Rc (i));
    mergeup (i);
    tree [i].prop = 0;
}

void update (int x, int y, int p, int i) {
    if (x > y) return;
    if (Lr (i) > y || Rr (i) < x) return;
    if (Lr (i) >= x && Rr (i) <= y) {
        tree [i].prop = p;
        return;
    }

    update (x, y, p, Lc (i));
    update (x, y, p, Rc (i));
    mergeup (i);
}

int query (int x, int y, int i) {
    if (Lr (i) > y || Rr (i) < x) return 0;
    if (Lr (i) >= x && Rr (i) <= y) {
        return tree [i].mx - tree [i].prop;
    }

    int p = query (x, y, Lc (i));
    int q = query (x, y, Rc (i));

    return max (p, q);
}

bool comp (querylist a, querylist b) {
    if (a.l == b.l) {
        if (a.r == b.r) return a.pos < b.pos;
        return a.r < b.r;
    }
    return a.l < b.l;
}

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d %d %d", &n, &c, &q);
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &ar [i]);
            if (ar [i] != ar [i - 1]) {
                br [i] = 1;
            }else {
                br [i] = br [i - 1] + 1;
            }
        }
        int prev = INF, fin;
        for (int i = n; i >= 1; i--) {
            if (ar [i] != prev) {
                prev = ar [i];
                fin = i;
            }
            pos [i] = fin;
        }

        build (1, n, 1);
        for (int i = 1; i <= q; i++) {
            scanf ("%d %d", &qr [i].l, &qr [i].r);
            qr [i].pos = i;
        }
        sort (qr + 1, qr + 1 + q, comp);
        for (int i = 1; i <= q; i++) {
            if (qr [i].l == 1) {
                ar [qr [i].pos] = query (qr [i].l, qr [i].r, 1);
            } else {
                int rght = min (pos [qr [i].l - 1], qr [i].r);
                update (qr [i].l, rght, br [qr [i].l - 1], 1);
                ar [qr [i].pos] = query (qr [i].l, qr [i].r, 1);
            }
        }

        printf ("Case %d:\n", kase);
        for (int i = 1; i <= q; i++) {
            printf ("%d\n", ar [i]);
        }
    }

    return 0;
}
