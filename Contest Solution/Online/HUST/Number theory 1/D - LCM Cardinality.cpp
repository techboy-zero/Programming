#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

vector <int> v;

int main () {
    ll n;
    while (cin >> n && n) {
        int cnt = 0;
        for (int i = 1; (ll) i * i <= n; i++) {
            if (n % i == 0) {
                v.push_back (i);
                if ((ll) i * i != n) v.push_back (n / i);
            }
        }
        sort (v.begin (), v.end ());
        int sz = v.size ();
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j <= i; j++) {
                ll res = (ll) v [i] * v [j];
                res /= __gcd (v [i], v [j]);
                if (res == n) cnt++;
            }
        }
        cout << n << " " << cnt << endl;
        v.clear ();
    }

    return 0;
}
