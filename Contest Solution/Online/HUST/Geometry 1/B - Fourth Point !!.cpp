#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

double x [5], y [5];

int main () {
    while (cin >> x [0] >> y [0]) {
        for (int i = 1; i <= 3; i++) cin >> x [i] >> y [i];

        if (x [0] == x [2] && y [0] == y [2]) {
            printf ("%.3lf %.3lf\n", (x [1] + x [3] - x [0]), (y [1] + y [3] - y [0]));
        } else if (x [0] == x [3] && y [0] == y [3]) {
            printf ("%.3lf %.3lf\n", (x [1] + x [2] - x [0]), (y [1] + y [2] - y [0]));
        } else if (x [1] == x [2] && y [1] == y [2]) {
            printf ("%.3lf %.3lf\n", (x [0] + x [3] - x [1]), (y [0] + y [3] - y [1]));
        } else if (x [1] == x [3] && y [1] == y [3]) {
            printf ("%.3lf %.3lf\n", (x [0] + x [2] - x [1]), (y [0] + y [2] - y [1]));
        }
    }
    return 0;
}
