#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define FOREACH(i,s) for(__typeof((s).end()) i = (s).begin(); i != (s).end(); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e7;
vector <ll> primes;
bool visit [MAX + 30];

void sieve () {
    primes.push_back (2);
    for (ll i = 3; i <= MAX + 20; i += 2) {
        if (visit [i]) continue;
        primes.push_back (i);
        for (ll j = i * i; j <= MAX + 20; j += 2 * i) {
            visit [j] = true;
        }
    }
}

int main () {
    sieve ();
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        ll n;
        cin >> n;
        while (!(n & 1)) n >>= 1;
        ll cnt = 1;
        for (int i = 0;  primes [i] * primes [i] <= n; i++) {
            ll p = 0;
            while (n % primes [i] == 0) {
                n /= primes [i];
                p++;
            }
            cnt *= (p + 1);
        }
        if (n > 1) cnt <<= 1;
        printf ("Case %d: %lld\n", kase, cnt - 1);
    }
    return 0;
}
