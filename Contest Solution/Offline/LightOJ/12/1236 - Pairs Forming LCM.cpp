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
#define MAX (long long) 1e7 + 20

#define mset(a,v)    memset(a, v, sizeof(a))

using namespace std;

typedef long long ll;

vector <ll> primes;
bool check [MAX + 7];

void sieve() {
    check [0] = check [1] = true;
    primes.push_back (2);

    for (ll i = 3; i <= MAX; i += 2) {
        if (check [i]) continue;

        primes.push_back (i);

        for (ll j = i * i; j <= MAX; j += 2 * i)
            check [j] = true;
    }
}

int main() {
    sieve();

    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        ll num;
        cin>>num;

        ll total = 1;

        for (int i = 0; primes [i] * primes [i] <= num; i++) {
            int cnt = 0;
            while (num % primes [i] == 0) {
                num /= primes [i];
                cnt++;
            }

            if (cnt) {
                cnt++;
                total = 2 * total * cnt - cnt - total + 1;
            }
        }

        if (num > 1)
            total = 2 * total * 2 - 2 - total + 1;

        printf("Case %d: %lld\n", kase, total);
    }

    return 0;
}
