#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = (int) 1e5 + 20;
typedef long long ll;

vector <ll> primes;
bool check [MAX + 7];

void sieve () {
    check [0] = check [1] = true;
    primes.push_back (2);

    for (ll i = 3; i <= MAX; i += 2) {
        if (check [i]) continue;
        primes.push_back (i);

        for (ll j = i * i; j <= MAX; j += 2 * i)
            check [j] = true;
    }
}

int main () {
    sieve ();
    #ifdef TECHBOY
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int l, r;
        cin >> l >> r;

        while (l < r) {
            l++;
            if (l == r) break;
            if (l == 2 || (l % 2 && !check [l])) {
                r++;
            } else r--;
        }
        cout << l << endl;
    }

    return 0;
}

