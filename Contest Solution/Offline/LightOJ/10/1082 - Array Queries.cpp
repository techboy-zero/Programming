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

int len, n, q, a [100010], b [1010];

void decompose () {
    len = sqrt (n);
    fill (b, b + 1001, INF);

    for (int i = 0; i < n; i++)
        b [i / len] = min (b [i / len], a [i]);
}

int getmin (int l, int r) {
    int mn = INF;
    int s = l / len, e = r / len;

    for (int i = s + 1; i < e; i++)
        mn = min (mn, b [i]);

    if (s == e) {
        for (int i = l; i <= r; i++)
            mn = min (mn, a [i]);
    }else {
        for (int i = l; i < (s + 1) * len; i++)
            mn = min (mn, a [i]);
        for (int i = e * len; i <= r; i++)
            mn = min (mn, a [i]);
    }

    return mn;
}

int main(){
    //freopen ("input.txt", "r", stdin);
    int t;
    scanf ("%d",&t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d %d",&n, &q);
        for (int i = 0; i < n; i++) scanf ("%d", &a [i]);

        decompose ();
        printf ("Case %d:\n", kase);

        for (int i = 1; i <= q; i++) {
            int l, r;
            scanf ("%d %d",&l, &r);
            printf ("%d\n",getmin (l - 1, r - 1));
        }
    }

    return 0;
}
