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

int m, n;
int cache [20][20];
bool visit [20][20];

int digits [20];

int dp (int pos, int prev) {
    if (pos == n) return 1;
    int &ret = cache [pos][prev];
    if (visit [pos][prev]) return ret;
    visit [pos][prev] = true;

    ret = 0;
    if (!pos) {
        for (int i = 0; i < m; i++)
            ret += dp (pos + 1, i);
    }else {
        for (int i = 0; i < m; i++)
            if (abs(digits [prev] - digits [i]) <= 2)
                ret += dp (pos + 1, i);
    }

    return ret;
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>m>>n;
        for (int i = 0; i < m; i++)
            cin>>digits [i];
        mset(visit, false);
        int solve = dp(0, 0);
        printf("Case %d: %d\n",kase, solve);
    }

    return 0;
}
