#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        ll n;
        cin >> n;
        ll ans;
        if (n % 2) {
            ans = ((n + 3) * (n + 3)) / 48;
            ll m = ((n + 3) * (n + 3)) % 48;
            if (m >= 24) ans++;
        } else {
            ans = (n * n) / 48;
            ll m = (n * n) % 48;
            if (m >= 24) ans++;
            ans += (n / 4);
        }
        printf ("%lld\n", ans);
    }
    return 0;
}


