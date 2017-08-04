#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5 + 7;
int n;
int ar [MAX];

int main () {
    cin >> n;
    ll tot = (ll) n * (n - 1) / 2;
    double sum = 0;
    int mx = 0;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y >> ar [i];
        sum += ar [i];
        mx = max (mx, ar [i]);
    }
    double ans = 0;
    for (int i = 1; i < n; i++) {
        ans += (sum - ar [i]);
    }
    double rest = tot - n + 1;
    ans += rest * (sum - mx);
    printf ("%lf\n", (ans / tot));

    return 0;
}
