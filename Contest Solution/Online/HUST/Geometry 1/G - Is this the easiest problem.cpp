#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        ll a, b, c;
        cin >> a >> b >> c;
        printf ("Case %d: ", kase);
        if (a + b <= c || c + b <= a || a + c <= b) {
            cout << "Invalid" << endl;
        } else {
            if ( a == b && b == c) {
                cout << "Equilateral" << endl;
            } else if (a == b || b == c || a == c) {
                cout << "Isosceles" << endl;
            } else {
                cout << "Scalene" << endl;
            }
        }
    }
    return 0;
}
