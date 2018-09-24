#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll getTriangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (ll) x1 * (y2 - y3) + (ll) x2 * (y3 - y1) + (ll) x3 * (y1- y2);
}

int main() {
    int n, d;

    while (cin >> n >> d) {
        int m;
        cin >> m;
        ll rectangleArea = llabs(getTriangleArea(0, d, n, n - d, n - d, n)) + llabs(getTriangleArea(0, d, d, 0, n - d, n));

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;

            ll newRectangleArea = 0;
            newRectangleArea += llabs(getTriangleArea(x, y, 0, d, n, n - d));
            newRectangleArea += llabs(getTriangleArea(x, y, 0, d, d, 0));
            newRectangleArea += llabs(getTriangleArea(x, y, d, 0, n - d, n));
            newRectangleArea += llabs(getTriangleArea(x, y, n - d, n, n, n - d));

            if (newRectangleArea > rectangleArea) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}
