#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e4 + 7;

ll x [MAX], y [MAX];

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int n;
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf ("%lld %lld", &x [i], &y [i]);
        }
        x [n] = x [0];
        y [n] = y [0];
        ll area = 0;
        ll latice = n;
        for (int i = 0; i < n; i++) {
            area += (x [i] * y [i + 1] - y [i] * x [i + 1]);
            latice += llabs (__gcd (x [i + 1] - x [i], y [i + 1] - y [i])) - 1;
        }
        area = llabs (area);
        ll tree = (area - latice + 2) / 2;
        printf ("Case %d: %lld\n", kase, tree);
    }
    return 0;
}
