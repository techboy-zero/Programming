#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 2e6 + 7;
const int MOD = 1e9 + 7;

int fact [MAX], invfact [MAX];

ll binaryExpo (ll n, ll p, int mod) {
    if (!p) return 1;
    if (p == 1) return (n % mod);

    ll temp = binaryExpo (n, p >> 1, mod);
    temp = (temp * temp) % mod;
    if (p & 1) temp = (temp * n) % mod;
    return temp;
}

void preCalc () {
    fact [0] = invfact [0] = 1;
    for (int i = 1; i <= MAX - 7; i++) {
        ll temp = fact [i - 1];
        temp *= i;
        if (temp >= MOD) temp %= MOD;
        fact [i] = temp;
    }
    for (int i = 1; i <= (MAX - 7) / 2; i++) {
        ll temp = invfact [i - 1];
        temp *= binaryExpo (i, MOD - 2, MOD);
        if (temp >= MOD) temp %= MOD;
        invfact [i] = temp;
    }
}

int main () {
    preCalc ();
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int n, k;
        scanf ("%d %d", &n, &k);

        ll ans = fact [n + k - 1];
        ans *= invfact [k - 1];
        if (ans >= MOD) ans %= MOD;
        ans *= invfact [n];
        if (ans >= MOD) ans %= MOD;

        printf ("Case %d: %lld\n", kase, ans);
    }

    return 0;
}
