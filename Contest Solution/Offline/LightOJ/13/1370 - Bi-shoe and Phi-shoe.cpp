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
#define MAX (int) 1e6 + 20

#define mset(a,v)    memset(a, v, sizeof(a))

using namespace std;
typedef long long ll;

vector <ll> primes;
bool check [MAX + 7];
int a [10010];

void sieve () {
    check [0] = check [1] = true;
    primes.push_back(2);

    for (ll i = 3; i <= MAX; i += 2) {
        if (check [i]) continue;
        primes.push_back (i);
        for (long long j = i * i; j <= MAX; j += 2 * i)
            check [j] = true;
    }
}

int main(){
    sieve ();
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin>>n;
        for (int i = 0; i < n; i++) cin >> a [i];
        ll total = 0;
        for (int i = 0; i < n; i++) {
            int p = (upper_bound (primes.begin(), primes.end(), a [i]) - primes.begin ());
            total += primes [p];
        }
        printf ("Case %d: %lld Xukha\n", kase, total);
    }

    return 0;
}
