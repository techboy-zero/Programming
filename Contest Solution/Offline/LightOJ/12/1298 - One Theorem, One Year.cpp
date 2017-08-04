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

bool visit [510][510];
ll cache [510][510], mod = 1000000007, s [510], power [510][510];
int k, p, primes [510];

void power_gen (int indx, int n) {
    power [indx][0] = 1;
    for (int i = 1; i <= 500; i++) {
        power [indx][i] = power [indx][i - 1] * n;
        power [indx][i] %= mod;
    }
}

void pregen () {
    int cnt = 0, num = 1;
    s [0] = 1;
    while (cnt != 500) {
        num++;
        bool prime = true;
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0) {
                prime = false;
                continue;
            }
        if (!prime) continue;
        primes [++cnt] = num;
        s [cnt] = ((num - 1) * s [cnt - 1]) % mod;
        power_gen (cnt, num);
    }
}

ll dp (int pos, int curr) {
    if (!pos) return 1;
    ll &ret = cache [pos][curr];
    if (visit [pos][curr]) return ret;
    visit [pos][curr] = true;

    ret = 0;
    if (curr == 1) {
        ret = (dp (0, 0) * power [1][pos - 1]) % mod;
    } else {
        for (int i = 1; i <= (pos - curr + 1); i++) {
            ret += (dp (pos - i, curr - 1) * power [curr][i - 1]) % mod;
            ret %= mod;
        }
    }

    return ret % mod;
}

int main() {
    pregen ();
    mset (visit, false);
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>k>>p;
        ll base = s [p];
        printf ("Case %d: %lld\n", kase, (dp (k, p) * base) % mod);
    }
    return 0;
}
