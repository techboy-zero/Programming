#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

int main () {
    int n, kase = 0;
    double area;

    while (cin >> n >> area && n >= 3) {
        double a = sqrt (4 * area / n * tan (PI / n));
        double r = 0.5 * a / tan (PI / n);
        double R = 0.5 * a / sin (PI / n);

        double area1 = PI * r * r;
        double area2 = PI * R * R;

        printf ("Case %d: %.5lf %.5lf\n", ++kase, area2 - area, area - area1);
    }
    return 0;
}
