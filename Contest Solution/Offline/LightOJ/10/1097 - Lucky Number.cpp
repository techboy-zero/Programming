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

const int MAX = 1e6 + 5e5, MAXQ = 1e5;
int n, qr [MAX + 7], in;

struct segment {
    int l, r, sum;
} tree [3 * MAX + 7];

void mergeup (int i) {
    tree [i].sum = tree [Lc (i)].sum + tree [Rc (i)].sum;
    Lr (i) = Lr (Lc (i));
    Rr (i) = Rr (Rc (i));
}

void build (int l, int r, int i) {
    if (l == r) {
        Lr (i) = Rr (i) = l;
        tree [i].sum = l % 2;
        return;
    }

    int mid = (l + r) >> 1;
    build (l, mid, Lc (i));
    build (mid + 1, r, Rc (i));
    mergeup (i);
}

void update (int x, int i) {
    if (Lr (i) == Rr (i) && Lr (i) == x) {
        tree [i].sum = 0;
        return;
    }
    if (Lr (i) > x || Rr (i) < x) return;

    update (x, Lc (i));
    update (x, Rc (i));
    mergeup (i);
}

int query (int x) {
    int curr = 0, i = 1;
    if (x > tree [1].sum) return -1;
    while (Lr (i) != Rr (i)) {
        if (curr + tree [Lc (i)].sum < x) {
            curr += tree [Lc (i)].sum;
            i = Rc (i);
        }else i = Lc (i);
    }
    return Lr (i);
}

void precalc () {
    build (1, MAX, 1);

    for (int i = 2; i <= MAXQ; i++) {
        int curr = query (i);
        in = 0;

        if (curr == -1) break;
        for (int j = curr; j <= MAX; j += curr) {
            int temp = query (j);
            if (temp == -1) break;
            qr [in++] = temp;
        }

        for (int j = 0; j < in; j++) {
            update (qr [j], 1);
        }
    }
}

int main () {
    precalc ();
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d", &n);
        printf ("Case %d: %d\n", kase, query (n));
    }

    return 0;
}
