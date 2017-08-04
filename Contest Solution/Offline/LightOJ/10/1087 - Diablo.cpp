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

/*Segment Tree*/
#define Lc(i) (2 * i)
#define Rc(i) (2 * i + 1)
#define Lr(i) (tree [i].l)
#define Rr(i) (tree [i].r)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e5 + 5e4;

struct segment {
    int l, r, cnt;
    ll prop, sum;
} tree [4 * MAX + 7];

ll n, q, arr [MAX + 7];

void mergeup (int i) {
    Lr (i) = Lr (Lc (i));
    Rr (i) = Rr (Rc (i));
    tree [i].sum = tree [Lc (i)].sum + tree [Rc (i)].sum;
    tree [i].cnt = tree [Lc (i)].cnt + tree [Rc (i)].cnt;
}

void split (int i) {
    tree [Lc (i)].prop += tree [i].prop;
    tree [Rc (i)].prop += tree [i].prop;
    tree [Lc (i)].sum += tree [Lc (i)].cnt * tree [i].prop;
    tree [Rc (i)].sum += tree [Rc (i)].cnt * tree [i].prop;
    tree [i].prop = 0;
}

void build (int l, int r, int i) {
    if (l == r) {
        Lr (i) = Rr (i) = l;
        tree [i].sum = l;
        tree [i].prop = 0;
        tree [i].cnt = 1;
        return;
    }

    split (i);
    int mid = (l + r) >> 1;
    build (l, mid, Lc (i));
    build (mid + 1, r, Rc (i));
    mergeup (i);
}

void update (int x, int y, int i, int v) {
    if (x > y) return;
    if (Lr (i) > y || Rr (i) < x) return;
    if (Lr (i) == x && Rr (i) == x && x == y) {
        tree [i].prop = tree [i].sum = tree [i].cnt = 0;
        return;
    }
    if (Lr (i) >= x && Rr (i) <= y) {
        tree [i].prop += v;
        tree [i].sum += tree [i].cnt * v;
        return;
    }

    split (i);
    update (x, y, Lc (i), v);
    update (x, y, Rc (i), v);
    mergeup (i);
}

int binarySearch (ll indx) {
    if (indx > n) return n + 1;

    ll total = 0, key = indx * (indx + 1) / 2;
    int i = 1;

    while (Lr (i) != Rr (i)) {
        split (i);
        mergeup (i);

        if (tree [Lc (i)].sum + total < key) {
            total += tree [Lc (i)].sum;
            i = Rc (i);
        } else i = Lc (i);
    }

    return Lr (i);
}

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%lld %lld", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &arr [i]);
        }
        build (1, MAX, 1);
        printf ("Case %d:\n", kase);
        for (int i = 1; i <= q; i++) {
            char com;
            ll v;
            scanf (" %c %lld", &com, &v);
            if (com == 'c') {
                ll curr = binarySearch (v);
                if (curr > n) {
                    printf ("none\n");
                } else {
                    printf ("%lld\n", arr [curr]);
                    update (curr, curr, 1, -1);
                    update (curr + 1, MAX, 1, -1);
                }
            } else {
                arr [++n] = v;
            }
        }
    }

    return 0;
}
