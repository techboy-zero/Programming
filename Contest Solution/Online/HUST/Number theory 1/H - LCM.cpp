#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 100;

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
    int n;
    while (cin >> n && n) {
        int two = 0, five = 0;
        ll ans = 1;
        for (int i = 0; primes [i] <= n; i++) {
            if (primes [i] == 2) {
                ll temp = 1;
                while (temp * 2 <= n) {
                    temp *= 2;
                    two++;
                }
            } else if (primes [i] == 5) {
                ll temp = 1;
                while (temp * 5 <= n) {
                    temp *= 5;
                    five++;
                }
            } else {
                ll temp = 1;
                while (temp * primes [i] <= n) {
                    temp *= primes [i];
                    ans *= primes [i];
                    ans %= 10;
                }
            }
        }

        two -= five;
        for (int i = 1; i <= two; i++) {
            ans *= 2;
            ans %= 10;
        }
        cout << ans << endl;
    }
    return 0;
}
