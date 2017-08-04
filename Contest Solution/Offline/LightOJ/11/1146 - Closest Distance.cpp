#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

double ax, ay, bx, by, cx, cy, dx, dy;
double vector0x, vector0y, vector1x, vector1y;

double distance (double x0, double y0, double x1, double y1) {
    return sqrt ((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
}

double func (double scaler) {
    double point0x = ax + vector0x * scaler;
    double point0y = ay + vector0y * scaler;
    double point1x = cx + vector1x * scaler;
    double point1y = cy + vector1y * scaler;

    return distance (point0x, point0y, point1x, point1y);
}

double ternarySearch () {
    double lo = 0, hi = 1, ans = INF;
    while (lo + EPS <= hi) {
        double leftthird = lo + (hi - lo) / 3;
        double rightthird = hi - (hi - lo) / 3;
        double leftvalue = func (leftthird);
        double rightvalue = func (rightthird);

        if (leftvalue <= rightvalue) {
            hi = rightthird;
            ans = min (ans, leftvalue);
        } else if (leftvalue > rightvalue) {
            lo = leftthird;
            ans = min (ans, rightvalue);
        }
    }

    return ans;
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
       cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
       vector0x = bx - ax;
       vector0y = by - ay;
       vector1x = dx - cx;
       vector1y = dy - cy;

       printf ("Case %d: %.10lf\n", kase, ternarySearch ());
    }
    return 0;
}
