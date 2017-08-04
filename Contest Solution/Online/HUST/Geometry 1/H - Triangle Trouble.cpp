#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e4 + 7;

double sides [MAX];

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> sides [i];
        sort (sides, sides + n);
        double mx = 0;
        for (int i = n - 3; i >= 0; i--) {
            if (sides [i] + sides [i + 1] > sides [i + 2]) {
                if (sides [i + 1] + sides [i + 2] > sides [i]) {
                    if (sides [i] + sides [i + 2] > sides [i + 1]) {
                        double s = (sides [i] + sides [i + 1] + sides [i + 2]) / 2;
                        double area = sqrt (fabs(s * (s - sides [i]) * (s - sides [i + 1]) * (s - sides [i + 2])));
                        mx = max (mx, area);
                    }
                }
            }
        }
        printf ("%.2lf\n", mx);
    }

    return 0;
}
