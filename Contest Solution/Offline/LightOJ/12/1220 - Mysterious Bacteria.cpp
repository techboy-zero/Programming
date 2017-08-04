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

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        long long n;
        cin>>n;

        bool neg = (n < 0);
        n = llabs (n);
        int cnt = 0;

        for (long long i = 2; i * i <= n; i++) {
            int p = 0;
            while (n % i == 0) {
                p++;
                n /= i;
            }

            cnt = __gcd (p, cnt);
        }

        if (n > 1) cnt = 1;
        if (neg) {
            while (cnt % 2 == 0)
                cnt /= 2;
        }

        printf("Case %d: %d\n", kase, cnt);
    }

    return 0;
}
