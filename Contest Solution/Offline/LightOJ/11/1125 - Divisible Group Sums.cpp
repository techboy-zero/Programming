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

long long n, q, a [210], d, m;

long long cache [210][20][25][15];
bool visit [210][20][25][15];

long long dp (int pos, long long dsum, long long mod, int lft) {
    if (pos == n) {
        if (lft == 0 && dsum == 0) return 1;
        else                       return 0;
    }
    long long &ret = cache [pos][dsum][mod][lft];
    if (visit [pos][dsum][mod][lft]) return ret;
    visit [pos][dsum][mod][lft] = true;

    ret = 0;
    long long tempsum = ((dsum + a [pos]) % mod + mod) % mod;
    if (lft) ret = dp (pos + 1, tempsum, mod, lft - 1);
    ret += dp (pos + 1, dsum, mod, lft);

    return ret;
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n>>q;

        for (int i = 0; i < n; i++)
            cin>>a [i];

        mset(visit, false);

        printf("Case %d:\n", kase);
        for (int i = 0; i < q; i++) {
            cin>>d>>m;
            long long solve = dp (0, 0, d, m);
            printf("%lld\n",solve);
        }
    }

    return 0;
}
