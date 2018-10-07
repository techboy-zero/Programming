#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        ll a, b;
        cin >> a >> b;

        if (a - b != 1) {
            cout << "NO" << endl;
        } else {
            ll tot = a + b;
            bool isPossible = true;
            for (ll i = 2; i * i <= tot; i++) {
                if (tot % i == 0) {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}

