#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main () {
    int n;
    while (cin >> n) {
        double res;
        int hi = 0, lo = INF;
        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            hi = max (hi, num);
            lo = min (lo, num);

            printf ("Case %d: %.2lf\n", i, (double) hi / lo);
        }
    }
    return 0;
}

