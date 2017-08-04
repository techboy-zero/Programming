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

int n, len, q, a [510][510], b [510][30];

void decompose () {
    len = sqrt (n);
    mset (b, 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b [i][j / len] = max (b [i][j / len], a [i][j]);
}

int getmax (int l, int r, int u, int d) {
    int mx = 0;
    int s = (l / len), e = (r / len);

    for (int i = u; i <= d; i++) {
        if (s == e) {
            for (int j = l; j <= r; j++)
                mx = max (mx, a [i][j]);
        }else {
            for (int j = s + 1; j < e; j++)
                mx = max (mx, b [i][j]);

            for (int j = l; j < (s + 1) * len; j++)
                mx = max (mx, a [i][j]);
            for (int j = e * len; j <= r; j++)
                mx = max (mx, a [i][j]);
        }
    }

    return mx;
}

int main(){
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d %d", &n, &q);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf ("%d", &a [i][j]);
        decompose ();

        printf ("Case %d:\n", kase);
        for (int i = 1; i <= q; i++) {
            int u, v, s;
            scanf ("%d %d %d", &u, &v, &s);
            printf ("%d\n", getmax (v - 1, v + s - 2, u - 1, u + s - 2));
        }
    }

    return 0;
}
