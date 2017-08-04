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

int cache [2][1010][1010], n;
bool visit [2][1010][1010];

int a [1010];

int dp (int pos, bool first, int taken) {
    if (pos >= n) return 0;
    int &ret = cache [first][pos][taken];
    if (visit [first][pos][taken]) return ret;
    visit [first][pos][taken] = true;

    ret = 0;
    if (!pos) {
        ret = dp (pos + 2, true, taken + 1) + a [pos];
        ret = max (ret, dp (pos + 1, false, taken));
    }else if (pos == n - 1) {
        if (!first) ret = dp (pos + 2, first, taken + 1) + a [pos];
        ret = max(ret, dp (pos + 1, first, taken));
    }else {
        ret = dp (pos + 2, first, taken + 1) + a [pos];
        ret = max (ret, dp (pos + 1, first, taken));
    }

    return ret;
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n;
        for (int i = 0; i < n; i++)
            cin>> a [i];
        mset(visit, false);
        int solve = dp (0, 0, 0);
        printf("Case %d: %d\n", kase, solve);
    }

    return 0;
}
