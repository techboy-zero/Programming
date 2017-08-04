#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i!=s.end(); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e6;
ll dr [MAX], revdr [MAX];

int main () {
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif

    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        ll n;
        ll tot = 0;
        scanf ("%lld", &n);

        int limit = sqrt (n);
        for (int i = 1; i <= limit; i++) {
            dr [i] = i;
            revdr [i] = n / i;
            dr [2 * limit - i + 1] = n / i;
            revdr [2 * limit - i + 1] = i;
        }

        for (int i = 1; i < 2 * limit; i++) {
            ll a = revdr [i];
            ll b = revdr [i + 1];
            tot += (a * (a + 1) / 2 - b * (b + 1) / 2) * (dr [i] - 1);
        }

        printf ("Case %d: %lld\n", kase, tot);
    }

    return 0;
}
