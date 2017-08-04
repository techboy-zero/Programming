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

/*STL Iterator*/
#define FOREACH(i,s) for (__typeof ((s).end()) i = (s).begin (); i != (s).end (); i++)

/*Segment Tree*/
#define Lc(i) (2 * i)
#define Rc(i) (2 * i + 1)
#define Lr(i) (tree [i].l)
#define Rr(i) (tree [i].r)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e6;
int n, q, qr [MAX + 7];
map <int, int> co;

struct segment {
    int l, r, prop;
} tree [3 * MAX + 7];

struct line {
    int x, y;
} ar [MAX + 7];

void mergeup (int i) {
    Lr (i) = Lr (Lc (i));
    Rr (i) = Rr (Rc (i));
}

void split (int i) {
    tree [Lc (i)].prop += tree [i].prop;
    tree [Rc (i)].prop += tree [i].prop;
    tree [i].prop = 0;
}

void build (int l, int r, int i) {
    if (l == r) {
        Lr (i) = Rr (i) = l;
        tree [i].prop = 0;
        return;
    }

    split (i);
    int mid = (l + r) >> 1;
    build (l, mid, Lc (i));
    build (mid + 1, r, Rc (i));
    mergeup (i);
}

void update (int x, int y, int i) {
    if (x > y) return;
    if (Lr (i) > y || Rr (i) < x) return;
    if (Lr (i) >= x && Rr (i) <= y) {
        tree [i].prop++;
        return;
    }

    split (i);
    update (x, y, Lc (i));
    update (x, y, Rc (i));
}

int query (int x, int i) {
    if (Lr (i) > x || Rr (i) < x) return 0;
    if (Lr (i) == x && Rr (i) == x) return tree [i].prop;

    split (i);
    int p = query (x, Lc (i));
    int q = query (x, Rc (i));

    return (p + q);
}

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d %d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf ("%d %d", &ar [i].x, &ar [i].y);
            co [ar [i].x]; co [ar [i].y];
        }
        for (int i = 1; i <= q; i++) {
            scanf ("%d", &qr [i]);
            co [qr [i]];
        }
        int in = 0;
        FOREACH (curr, co) {
            curr -> second = ++in;
        }
        build (1, in, 1);
        for (int i = 1; i <= n; i++) {
            update (co [ar [i].x],co [ar [i].y], 1);
        }
        printf ("Case %d:\n", kase);
        for (int i = 1; i <= q; i++) {
            printf ("%d\n", query (co [qr [i]], 1));
        }
        co.clear ();
    }
    return 0;
}
