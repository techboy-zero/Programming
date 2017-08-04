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
#define EPS             DBL_EPSILON
#define ABS(x)          (((x) < 0) ? - (x) : (x))
#define ZERO(x)         (ABS (x) < EPS)
#define EQUAL(x, y)     (ZERO ((x) - (y)))

#define sqr(x) (x*x)
#define cube(x) (x*x*x)
#define INF 999999999
#define MOD 100000007

using namespace std;
typedef long long ll;

const int MAX = 1e7, MAXR = 1e5;
bool check [MAX + 20];
bool flag [MAXR + 20];

vector <int> primes;

void sieve () {
    check [0] = check [1] = true;
    primes.push_back (2);

    for (int i = 4; i <= MAX; i += 2) {
        check [i] = true;
    }

    for (int i = 3; i <= MAX; i += 2) {
        if (check [i]) continue;
        primes.push_back(i);
        for (ll j = (ll) i * i; j <= MAX; j += 2 * i) {
            check [j] = true;
        }
    }
}

int segmented_sieve (ll a, ll b) {
    int cnt = (a <= 2 && 2 <= b) ? 1 : 0;
    if (b < 2) return 0;
    if (a < 3) a = 3;
    if (a % 2 == 0) a++;
    memset(flag, false, sizeof flag);

    for (int i = 0; (ll) primes [i] * primes [i] <= b; i++) {
        ll j = (ll) primes [i] * ((a + primes[i] - 1) / primes [i]);
        if (j % 2 == 0) j += primes [i];
        for (ll k = primes [i] << 1; j <= b; j += k) {
            if (j != primes[i]) {
                flag [j - a] = true;
            }
        }
    }

    for (int i = 0; i <= b - a; i += 2) {
        cnt += !flag [i];
    }

    return cnt;
}

int main () {
    sieve ();
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int a, b;
        cin >> a >> b;
        printf ("Case %d: %d\n", kase, segmented_sieve (a, b));
    }

    return 0;
}
