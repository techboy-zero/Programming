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

int counter [100010], s [100010], repeat [100010];

int main(){
    int t;
    scanf ("%d",&t);

    for (int kase = 1; kase <= t; kase++) {
        int n, m;
        scanf ("%d %d", &n, &m);
        mset (counter, 0);
        for (int i = 1; i <= n; i++) {
            scanf ("%d",&s [i]);
            s [i] += s [i - 1];
            s [i] %= m;
        }

        for (int i = n; i >= 1; i--) {
            counter [s [i]]++;
            repeat [i] = counter [s [i]];
            if (s [i]) repeat [i]--;
        }

        long long total = 0;
        for (int i = 1; i <= n; i++)
            total += repeat [i];

        printf ("Case %d: %lld\n",kase, total);
    }

    return 0;
}
