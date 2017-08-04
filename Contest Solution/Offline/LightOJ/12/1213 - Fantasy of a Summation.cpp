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

ll Binary_Expo (ll n, ll p, ll m) {
    if (!p) return 1;
    if (p == 1) return n;

    if (p % 2) return ((Binary_Expo (n, p - 1, m) % m) * n) % m;
    ll temp = Binary_Expo (n, p >> 1, m) % m;
    return (temp * temp) % m;
}

int main(){
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        ll n, k, mod;
        cin >> n >> k >> mod;
        ll a [n + 1];
        for (int i = 0; i < n; i++) cin >> a [i];
        ll multi = Binary_Expo (n, k - 1, mod);
        multi = (multi * k) % mod;
        ll total = 0;
        for (int i = 0; i < n; i++)
            total += (a [i] * multi) % mod;
        total %= mod;
        printf ("Case %d: %lld\n", kase, total);
    }

    return 0;
}
