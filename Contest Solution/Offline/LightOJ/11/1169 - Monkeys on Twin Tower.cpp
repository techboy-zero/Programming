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

int n, fruits [2][1010], jumps [2][1010];
bool visit [2][1010];
int cache [2][1010];

int dp (bool build, int pos) {
    if (pos == n + 1) return 0;
    int &ret = cache [build][pos];
    if (visit [build][pos]) return ret;
    visit [build][pos] = true;

    ret = 0;
    if (!pos) ret = min (dp (0, 1) , dp (1, 1));
    else if (pos != n) {
        ret = min (dp (build, pos + 1), dp (!build, pos + 1) + jumps [build][pos]) + fruits [build][pos];
    }else
        ret = dp (build, pos + 1) + fruits [build][pos];

    return ret;
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n;
        for (int i = 1; i <= n; i++) cin>> fruits [0][i];
        for (int i = 1; i <= n; i++) cin>> fruits [1][i];

        for (int i = 1; i < n; i++) cin>> jumps [0][i];
        for (int i = 1; i < n; i++) cin>> jumps [1][i];

        mset(visit, false);
        int solve = dp (0, 0);
        printf("Case %d: %d\n", kase, solve);
    }

    return 0;
}
