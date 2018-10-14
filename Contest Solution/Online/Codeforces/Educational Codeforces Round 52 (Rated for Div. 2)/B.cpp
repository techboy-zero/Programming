#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main () {
    ll n, m;
    while (cin >> n >> m) {
        if (n == 1) {
            cout << "1 1" << endl;
        } else if (m == 0) {
            cout << n << " " << n << endl;
        } else {
            ll mn, mx;
            if (m * 2 < n) {
                mn = n - m * 2;
            } else {
                mn = 0;
            }

            for (ll i = 1; i <= n; i++) {
                ll tot = (i * (i - 1) / 2);
                if (tot > m) {
                    break;
                } else if (tot == m) {
                    mx = n - i;
                } else {
                    mx = n - i - 1;
                }
            }

            cout << mn << " " << mx << endl;
        }
    }
    return 0;
}

