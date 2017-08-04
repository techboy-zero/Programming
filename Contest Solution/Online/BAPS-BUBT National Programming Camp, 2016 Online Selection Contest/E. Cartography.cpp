#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 7, MOD = 1e9 + 7;

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        ll m, k;
        scanf ("%lld %lld", &m, &k);
        if (k < 2) puts ("0");
        else {
            ll ans = k * (k - 1);
            ll multi = 1;
            ll n = k - 2;
            multi += (n * (n + 1));
            for (int i = 1; i < m; i++) {
                ans *= multi;
                if (ans >= MOD) ans %= MOD;
            }
            printf ("%lld\n", ans);
        }
    }
    return 0;
}

