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
#define mset(a,v) memset(a, v, sizeof(a))

/*Segment tree*/
#define Lc(i) (2 * i)
#define Rc(i) (2 * i + 1)
#define Lr(i) (tree [i].l)
#define Rr(i) (tree [i].r)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5;
int n, q, ans [MAX + 7], arr [MAX + 7], lat [MAX + 7], pos [MAX + 7];

struct segment {
    int l, r;
    int sum;
} tree [3 * MAX + 7];

struct queries {
    int l, r, pos;
} qr [MAX + 7];

void mergeup (int i) {
    Lr (i) = Lr (Lc (i));
    Rr (i) = Rr (Rc (i));
    tree [i].sum = tree [Lc (i)].sum + tree [Rc (i)].sum;
}

void build (int l, int r, int i) {
    if (l == r) {
        Lr (i) = Rr (i) = l;
        tree [i].sum = 0;
        return;
    }

    int mid = (l + r) >> 1;
    build (l, mid, Lc (i));
    build (mid + 1, r, Rc (i));
    mergeup (i);
}

void update (int x, int i) {
    if (Lr (i) == x && Rr (i) == x) {
        tree [i].sum = tree [i].sum? 0 : 1;
        return;
    }
    if (Lr (i) > x || Rr (i) < x) return;

    update (x, Lc (i));
    update (x, Rc (i));
    mergeup (i);
}

int query (int x, int y, int i) {
    if (Lr (i) >= x && Rr (i) <= y) {
        return tree [i].sum;
    }
    if (Lr (i) > y || Rr (i) < x) return 0;

    int p = query (x, y, Lc (i));
    int q = query (x, y, Rc (i));
    return p + q;
}

bool comp (queries a, queries b) {
    if (a.l == b.l) return a.r < b.r;
    return a.l < b.l;
}

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        mset (lat, -1);
        mset (pos, -1);

        scanf ("%d %d", &n, &q);
        build (1, n, 1);
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &arr [i]);
            if (lat [arr [i]] == -1) {
                update (i, 1);
                lat [arr [i]] = i;
            }else {
                pos [lat [arr [i]]] = i;
                lat [arr [i]] = i;
            }
        }

        for (int i = 1; i <= q; i++) {
            scanf ("%d %d", &qr [i].l, &qr [i].r);
            qr [i].pos = i;
        }
        int in = 1;
        sort (qr + 1, qr + 1 + q, comp);
        for (int i = 1; i <= q; i++) {
            while (in != qr [i].l) {
                if (pos [in] != -1) update (pos [in], 1);
                in++;
            }
            ans [qr [i].pos] = query (qr [i].l, qr [i].r, 1);
        }

        printf ("Case %d:\n", kase);
        for (int i = 1; i <= q; i++) {
            printf ("%d\n", ans [i]);
        }
    }
    return 0;
}
