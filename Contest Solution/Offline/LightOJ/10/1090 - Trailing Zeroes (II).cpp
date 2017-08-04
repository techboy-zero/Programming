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

int n, r, p, q;

int main() {
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n>>r>>p>>q;
        int two = 0, five = 0;

        while (p % 2 == 0) { two++;  p >>= 1; }
        while (p % 5 == 0) { five++; p /= 5; }
        two *= q;
        five *= q;

        int t1 = n, t2 = n - r, t3 = r;
        while (t1 /= 2) two += t1;
        while (t2 /= 2) two -= t2;
        while (t3 /= 2) two -= t3;

        t1 = n; t2 = n - r; t3 = r;
        while (t1 /= 5) five += t1;
        while (t2 /= 5) five -= t2;
        while (t3 /= 5) five -= t3;

        printf ("Case %d: %d\n", kase, min (two, five));
    }

    return 0;
}
