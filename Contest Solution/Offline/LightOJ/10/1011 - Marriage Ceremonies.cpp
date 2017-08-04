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

int cost [20][20], cache [70000];
int n;
bool check [70000];

int bitmask_dp (int mask) {
    int curr = __builtin_popcount(mask);
    if (curr == n) return 0;
    if (check [mask]) return cache [mask];

    int &ret = cache [mask];
    for (int i = 0; i < n; i++) {
        if (!((1<<i) & mask))
            ret = max(ret, bitmask_dp( mask | (1<<i) ) + cost [curr][i]);
    }
    check [mask] = true;
    return ret;
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin>> cost [i][j];

        mset(check, false);
        mset(cache, 0);

        int total = bitmask_dp(0);
        printf("Case %d: %d\n",kase, total);
    }
    return 0;
}
