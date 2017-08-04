#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

int main () {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    while (cin >> n) {
        ll sum = 0;
        ll incr = 3;
        for (int i = 1; i <= n; i++) {
            cout << i << " " << (1 + sum) << endl;
            sum += incr;
            incr++;
        }
    }
    return 0;
}
