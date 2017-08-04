#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e5 + 7;

ll n, s;
int ar [MAX];

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%lld %lld", &n, &s);
        for (int i = 0; i < n; i++) {
            scanf ("%d", &ar [i]);
            if (i) ar [i] += ar [i - 1];
        }
        int ans = n + 1;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            ll key = s;
            if (i) key += ar [i - 1];
            cnt = (lower_bound (ar + i, ar + n, key) - (ar + i) + 1);
            if (cnt <= (n - i)) ans = min (ans, cnt);
        }
        if (ans == n + 1) ans = -1;
        printf ("Case %d: %d\n", kase, ans);
    }

    return 0;
}
