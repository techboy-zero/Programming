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
#define EPS             DBL_EPSILON
#define ABS(x)          (((x) < 0) ? - (x) : (x))
#define ZERO(x)         (ABS (x) < EPS)
#define EQUAL(x, y)     (ZERO ((x) - (y)))

#define sqr(x) (x*x)
#define cube(x) (x*x*x)
#define INF 999999999

using namespace std;

long long k, c, n, a [100010], s [100010], m = (long long) 1e6 + 7;

long long GetDiffSum () {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += labs((n - i - 1) * a [i] - s[n - 1] + s [i]);
    }
    return sum;
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>k>>c>>n>>a [0];
        k %= m; c %= m; s [0] = a [0];

        for (int i = 1; i < n; i++)
            a [i] = (((k * a [i - 1]) % m) + c) % m;

        sort (a, a + n);

        for (int i = 1; i < n; i++)
            s [i] = s [i - 1] + a [i];

        printf("Case %d: %lld\n", kase, GetDiffSum());
    }

    return 0;
}
