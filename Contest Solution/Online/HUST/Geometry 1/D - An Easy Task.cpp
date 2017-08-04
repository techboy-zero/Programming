#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

bool parallel (int a0, int b0, int a1, int b1) {
    int g = __gcd (a0, b0);
    a0 /= g;
    b0 /= g;
    g = __gcd (a1, b1);
    a1 /= g;
    b1 /= g;

    return (a0 == a1 && b0 == b1);
}

int main () {
    int a0, b0, c0;
    int a1, b1, c1;

    while (cin >> a0 >> b0 >> c0) {
        cin >> a1 >> b1 >> c1;
        if (!(a0 + b0 + c0 + a1 + b1 + c1)) break;
        if (parallel (a0, b0, a1, b1)) {
            cout << "No fixed point exists." << endl;
        } else {
            double x = (c0 * b1 - b0 * c1) * 1.0 / (a0 * b1 - a1 * b0);
            double y = (c1 - a1 * x) / b1;
            printf ("The fixed point is at %.2lf %.2lf.\n", x + EPS, y + EPS);
        }
    }
    return 0;
}
