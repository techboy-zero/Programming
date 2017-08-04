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

int rad [510][510], uran [510][510], cache [510][510];
int r, c;
bool visit [510][510];

void sum () {
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            rad [i][j] += rad [i - 1][j];

    for (int j = 1; j <= c; j++)
        for (int i = 1; i <= r; i++)
            uran [i][j] += uran [i][j - 1];
}

int dp (int i, int j) {
    if (!i || !j) return 0;
    int &ret = cache [i][j];
    if (visit [i][j]) return ret;
    visit [i][j] = true;

    ret = 0;
    ret = max (ret, dp (i, j - 1) + rad [i][j]);
    ret = max (ret, dp (i - 1, j) + uran [i][j]);

    return ret;
}

int main(){
    int t;
    scanf ("%d",&t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d %d",&r, &c);

        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                scanf ("%d",&uran [i][j]);

        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                scanf ("%d",&rad [i][j]);

        sum ();

        mset (visit, false);
        int solve = dp (r, c);
        printf ("Case %d: %d\n", kase, solve);
    }

    return 0;
}
