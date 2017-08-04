#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

vector <int> primes;
bool check [MAX + 7];

void sieve () {
    primes.push_back (2);
    for (int i = 3; i <= MAX; i += 2) {
        if (check [i]) continue;
        primes.push_back (i);
        for (ll j = (ll) i * i; j <= MAX; j += 2 * i) {
            check [j] = true;
        }
    }
}

int main () {
    sieve();
    ll m, n, p;
    int kase = 0;
    while (cin >> m >> n >> p && (m + n + p)) {
        ll res = n * p * p * m;
        if (res < 0) res = - res;
        ll ans = 1;
        for (int i = 0; (ll) primes [i] * primes [i] <= res; i++) {
            int p = 0;
            while (res % primes [i] == 0) {
                res /= primes [i];
                p++;
            }
            ans *= (p + 1);
        }
        if (res > 1) ans *= 2;
        ans *= 2;
        printf ("Case %d: ", ++kase);
        cout << (ans - 1) << endl;
    }
    return 0;
}
