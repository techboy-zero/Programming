#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;

ll fact [MAX], invfact [MAX];

ll inverseMod (ll n, ll p, int mod) {
    if (!p) return 1;
    if (p == 1) return (n % mod);

    ll temp = inverseMod (n, p >> 1, mod);
    temp = (temp * temp) % mod;
    if (p & 1) temp = (temp * n) % mod;
    return temp;
}

void factGen () {
    fact [0] = invfact [0] = 1;
    for (int i = 1; i <= MAX - 7; i++) {
        invfact [i] = inverseMod (i, MOD - 2, MOD);
        invfact [i] *= invfact [i - 1];
        if (invfact [i] >= MOD) invfact [i] %= MOD;
        fact [i] = fact [i - 1] * i;
        if (fact [i] >= MOD) fact [i] %= MOD;
    }
}

ll nCr (int n, int r) {
    ll res = fact [n];
    res *= invfact [r];
    if (res >= MOD) res %= MOD;
    res *= invfact [n - r];
    if (res >= MOD) res %= MOD;

    return res;
}

int main () {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    factGen ();

    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;
        ll res = fact [n];
        for (int i = 1; i <= n; i++) {
            ll temp = fact [n - i];
            temp *= nCr (n, i);
            if (temp >= MOD) temp %= MOD;
            if (i % 2) res -= temp;
            else res += temp;
            if (res < 0) res += MOD;
            if (res >= MOD) res %= MOD;
        }
        cout << res << endl;
    }

    return 0;
}
