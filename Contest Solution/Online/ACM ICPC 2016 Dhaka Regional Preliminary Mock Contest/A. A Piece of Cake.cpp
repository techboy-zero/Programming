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

    for (int kase =1 ; kase <= t; kase++) {
        ll n;
        cin >> n;

        if (n >= 0) {
            for (ll i = 0; i <= n; i++) {
                cout << i;
                if (i != n) cout << " ";
                else cout << endl;
            }
        } else {
            for (ll i = n; i <= 0; i++) {
                cout << i;
                if (i) cout << " ";
                else cout << endl;
            }
        }
    }

    return 0;
}

