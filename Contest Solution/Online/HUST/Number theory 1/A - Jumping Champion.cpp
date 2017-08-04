#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)
#define FOREACH(i,s) for(__typeof(s.end()) i = (s).begin(); i != (s).end(); i++)

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

map <int,int> diff;

int main () {
    sieve ();
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int l, r, lft, rght;
        cin >> l >> r;
        if (l <= 2) lft = 0;
        else {
            lft = (lower_bound (primes.begin (), primes.end (), l) - primes.begin ());
        }
        rght = (lower_bound (primes.begin (), primes.end (), r) - primes.begin ());
        if (primes [lft] < l) lft++;
        if (primes [rght] > r) rght--;

        if (rght - lft < 1) cout << "No jumping champion" << endl;
        else {
            diff.clear ();
            int mx = 0;
            for (int i = lft; i < rght; i++) {
                int p = primes [i + 1] - primes [i];
                diff [p]++;
                if (mx < diff [p]) mx = diff [p];
            }
            int ans = 0;
            FOREACH (i, diff) {
                if (ans != -1 && i -> second == mx) {
                    if (!ans) ans = i -> first;
                    else ans = -1;
                }
            }

            if (ans == -1) cout << "No jumping champion" << endl;
            else cout << "The jumping champion is " << ans << endl;
        }
    }

    return 0;
}
