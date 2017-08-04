#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)
#define EQU(x,l,w) (x * (l - 2 * x) * (w - 2 * x))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        double l, w;
        cin >> l >> w;

        double x1 = (4 * (l + w) + sqrt (4 * 4 * (l + w) * (l + w) - 4 * 12 * w * l)) / (2 * 12);
        double x2 = (4 * (l + w) - sqrt (4 * 4 * (l + w) * (l + w) - 4 * 12 * w * l)) / (2 * 12);

        double ans = max (EQU (x1, l, w), EQU (x2, l, w));
        printf ("Case %d: %.10lf\n", kase, ans);
    }
    return 0;
}
