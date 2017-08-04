#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-12
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

int a;
int n;

double distance (double x, double y, double cx, double cy) {
    return (cx - x) * (cx - x) + (cy - y) * (cy - y);
}

bool insideArea (double x, double y) {
    if (distance (x, y, 0, 0) > a * a) return false;
    if (distance (x, y, 0, a) > a * a) return false;
    if (distance (x, y, a, 0) > a * a) return false;
    if (distance (x, y, a, a) > a * a) return false;
    return true;
}

int main () {
    while (cin >> n >> a && n) {
        int m = 0;
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            if (insideArea (x, y)) m++;
        }
        printf ("%.5lf\n", (m * 1.0 * a * a / n));
    }
    return 0;
}
