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

int a [110], sum [110];
int n;

bool visit [110][110];
int cache [110][110];

int dp (int start, int finish) {
    if (start > finish) return 0;
    int &ret = cache [start][finish];
    if (visit [start][finish]) return ret;
    visit [start][finish] = true;

    ret = -INF;
    for (int i = start; i <= finish; i++) {
        ret = max (ret, sum [i] - sum [start - 1] - dp (i + 1, finish));
    }

    for (int i = finish; i >= start; i--) {
        ret = max (ret, sum [finish] - sum [i - 1] - dp (start, i - 1));
    }

    return ret;
}

int main() {
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n;

        mset(visit, false);
        for (int i = 1; i <= n; i++) {
            cin>>a [i];
            sum [i] = sum [i - 1] + a [i];
        }

        int solve = dp (1, n);

        printf("Case %d: %d\n", kase, solve);
    }

    return 0;
}
