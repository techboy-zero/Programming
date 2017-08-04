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

const int MAX = 2e5, MAXQ = 1e5;

struct segment {
    int l, r, sum;
} tree [3 * MAX + 7];

struct query {
    int l, r;
} qr [MAX + 7];

void mergeup (int i) {
    tree [i].sum = tree [Lc (i)].sum + tree [Rc (i)].sum;
    Lr (i) = Lr (Lc (i));
    Rr (i) = Rr (Rc (i));
}

void split (int i) {
    tree [Lc (i)].sum = Rr (Lc (i)) - Lr (Lc (i)) + 1;
    tree [Rc (i)].sum = Rr (Rc (i)) - Lr (Rc (i)) + 1;
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

bool update (int x, int y, int i) {
    int temp = Rr (i) - Lr (i) + 1;

    if (Lr (i) > y || Rr (i) < x) return false;
    if (Lr (i) >= x && Rr (i) <= y) {
        if (tree [i].sum == temp) return false;
        tree [i].sum = temp;
        return true;
    }

    if (tree [i].sum == temp) split (i);
    bool p = update (x, y, Lc (i));
    bool q = update (x, y, Rc (i));
    mergeup (i);
    return (p || q);
}

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int n;
        scanf ("%d", &n);
        build (1, 2 * n, 1);

        for (int i = n; i >= 1; i--) {
            scanf ("%d %d", &qr [i].l, &qr [i].r);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (update (qr [i].l, qr [i].r, 1)) cnt++;
        }

        printf ("Case %d: %d\n", kase, cnt);
    }

    return 0;
}
