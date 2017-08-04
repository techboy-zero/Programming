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

int n, w, k, a [110], cache [110][110];
bool check [110][110];

int dp_solve (int i, int lft) {
    if (i == -1) return 0;
    if (check [i][lft]) return cache [i][lft];

    int ret = 0;
    if (lft) {
        int  cnt = 1;
        for (int j = i - 1; j >= -1; j--)
            if (j != -1 && a [j] >= (a [i] - w) )
                cnt++;
            else
                ret = max (ret, dp_solve(j, lft - 1) + cnt);
    }
    ret = max(ret, dp_solve(i - 1, lft));

    check [i][lft] = true;
    return cache [i][lft] = ret;
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);

    for (int kase = 1; kase <= t; kase++) {
        scanf("%d %d %d",&n, &w, &k);
        int x;
        for (int i = 0; i < n; i++)
            scanf("%d %d", &x, &a[i]);

        sort (a, a + n);
        mset(check, false);
        int solve = dp_solve(n - 1, k);

        printf("Case %d: %d\n",kase, solve);
    }

    return 0;
}
