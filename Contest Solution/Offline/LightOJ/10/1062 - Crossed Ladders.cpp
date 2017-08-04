#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)
#define EQU(x,y) (fabs(x-y)<=EPS)
#define GREATER(x,y) (y+EPS<=x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

double x;
double y;
double c;

double leftValue (double w) {
    double A = sqrt (x*x - w*w);
    double B = sqrt (y*y - w*w);
    return (1.0 / A + 1.0 / B);
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> x >> y >> c;

        double lo = 0;
        double hi = min (x, y);
        double rght = (1.0 / c);
        double ans;
        int cnt = 60;

        while (lo <= hi && cnt) {
            double mid = (lo + hi) / 2;
            if (EQU (leftValue(mid), rght)) {
                ans = mid;
                break;
            } else if (GREATER (leftValue(mid), rght)) {
                hi = mid;
            } else {
                lo = mid;
            }
            cnt--;
        }

        printf ("Case %d: %lf\n", kase, ans + EPS);
    }

    return 0;
}
