#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;
const int MOD = 33554431;

ll ans [30 + 7];

void gen () {
    ans [0] = 1;
    ll p = 2;
    for (int i = 1; i < 30; i++) {
        ans [i] = ans [i - 1] + p;
        if (ans [i] >= MOD) ans [i] %= MOD;
        p *= 2;
    }
}

int main () {
    gen();
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int n;
        scanf ("%d", &n);
        if (n >= 25) n %= 25;
        printf ("Case %d: %lld\n", kase, ans [n]);
    }

    return 0;
}
