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

int a [300010];
int tree [1000010];
int n;

int min_value (int i, int j) {
    if (a [i] < a [j]) return i;
    return j;
}

void init_tree (int node, int l, int r) {
    if (l == r) {
        tree [node] = l;
        return;
    }

    int mid = (l + r) / 2;
    int lft = 2 * node;
    int rght = lft + 1;

    init_tree (lft, l, mid);
    init_tree (rght, mid + 1, r);

    tree [node] = min_value (tree [lft], tree [rght]);
    return;
}

int find_min (int node, int l, int r, int i, int j) {
    if (i > r || j < l) return n;
    if (i >= l && j <= r) return tree [node];

    int lft = 2 * node;
    int rght = lft + 1;
    int mid = (i + j) / 2;

    return min_value (find_min (lft, l, r, i, mid), find_min (rght, l, r, mid + 1, j));
}

int get_max_area (int l, int r) {
    if (l > r) return -INF;
    if (l == r) return a [l];

    int m = find_min (1, l, r, 0, n - 1);

    return max (a [m] * (r - l + 1), max (get_max_area (l, m - 1), get_max_area (m + 1, r)));
}

int main(){
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) scanf ("%d", &a [i]);
        a [n] = INF;
        init_tree (1, 0, n - 1);

        printf ("Case %d: %d\n", kase, get_max_area (0, n - 1));
    }

    return 0;
}
