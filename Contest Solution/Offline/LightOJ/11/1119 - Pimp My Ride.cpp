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
typedef long long ll;

ll cache [15][16400], cost [15][15];
bool visit [15][16400];
int n;

ll cost_gen (int mask, int curr) {
    ll total = 0;
    for (int i = 0; i < n; i++)
        if (mask & (1 << i))
            total += cost [curr][i];
    return total;
}

ll bit_dp (int pos, int mask) {
    if (pos == n) return 0;
    ll &ret = cache [pos][mask];
    if (visit [pos][mask]) return ret;
    visit [pos][mask] = true;

    ret = INF;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            ret = min (ret, bit_dp (pos + 1, mask | (1 << i)) + cost_gen (mask | (1 << i), i) );
        }
    }

    return ret;
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin>>cost [i][j];

        mset (visit, false);
        ll solve = bit_dp (0, 0);
        printf ("Case %d: %lld\n", kase, solve);
    }

    return 0;
}
