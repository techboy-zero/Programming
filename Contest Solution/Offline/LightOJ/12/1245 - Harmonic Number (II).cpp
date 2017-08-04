#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define FOREACH(i,s) for(__typeof((s).end()) i = (s).begin(); i != (s).end(); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5;
ll ar [MAX + 7];

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        ll n, sz = 0;
        scanf ("%lld", &n);
        for (ll i = 1; i * i <= n; i++) {
            ar [sz++] = i;
        }
        for (int i = sz - 1; i >= 0; i--) {
            ar [sz++] = n / ar [i];
        }

        ll total = n;
        for (int i = 1; i < sz; i++) {
            ll d1 = n / ar [i - 1], d2 = n / ar [i];
            total += (d1 - d2) * ar [i - 1];
        }
        printf ("Case %d: %lld\n", kase, total);
    }

    return 0;
}
