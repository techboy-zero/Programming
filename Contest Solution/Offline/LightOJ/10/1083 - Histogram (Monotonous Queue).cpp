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
stack <int> s;

int max_area (int n) {
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (s.empty () || a [s.top ()] <= a [i]) s.push (i);
        else {
            while (!s.empty() && a [s.top ()] > a [i] ) {
                int to = s.top ();
                s.pop ();
                int curr = a [to] * (s.empty ()? i : i - s.top () - 1);
                mx = max (mx, curr);
            }
            s.push (i);
        }
    }

    while (!s.empty ()) {
        int to = s.top ();
        s.pop ();
        int curr = a [to] * (s.empty ()? n : n - s.top () - 1);
        mx = max (mx, curr);
    }

    return mx;
}

int main() {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int n;
        scanf ("%d", &n);

        for (int i = 0; i < n; i++)
            scanf ("%d", &a [i]);

        printf ("Case %d: %d\n", kase, max_area (n));
    }

    return 0;
}
