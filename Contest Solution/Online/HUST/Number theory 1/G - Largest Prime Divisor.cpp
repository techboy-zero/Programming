#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e7 + 20;

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
    sieve ();
    ll n;
    while (scanf ("%lld", &n) != EOF) {
        if (!n) break;
        if (n < 0) n *= -1;
        int cnt = 0;
        ll mx = -1;
        for (int i = 0; (ll) primes [i] * primes [i] <= n; i++) {
            if (n % primes [i] == 0) {
                cnt++;
                while (n % primes [i] == 0) {
                    n /= primes [i];
                    mx = primes [i];
                }
            }
        }
        if (n > 1) {
            cnt++;
            mx = n;
        }
        if (cnt <= 1) puts ("-1");
        else printf ("%lld\n", mx);
    }
    return 0;
}
