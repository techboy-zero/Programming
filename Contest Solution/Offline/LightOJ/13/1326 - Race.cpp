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

const int mod = 10056;
int cache [1010][1010], fact [1010];
bool visit [1010][1010];

int sterlingSecond (int n, int k) {
    if (k == 1 || k == n) return 1;
    int &ret = cache [n][k];
    if (visit [n][k]) return ret;
    visit [n][k] = true;

    ret = 0;
    ret = sterlingSecond (n - 1, k - 1) + (k * sterlingSecond (n - 1, k)) % mod;
    ret %= mod;

    return ret;
}

void Init () {
    fact [0] = 1;
    for (int i = 1; i <= 1000; i++) {
        fact [i] = fact [i - 1] * i;
        fact [i] %= mod;
    }
}

int main () {
    Init ();
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int n;
        scanf ("%d", &n);
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += (sterlingSecond (n, i) * fact [i]) % mod;
            res %= mod;
        }
        printf ("Case %d: %d\n", kase, res);
    }

    return 0;
}
