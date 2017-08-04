#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

ll trailing (ll n, ll p, int mod) {
    if (!p) return 1;
    if (p == 1) return (n % mod);

    ll temp = trailing (n, p >> 1, mod);
    temp = (temp * temp) % mod;
    if (p & 1) temp = (temp * n) % mod;
    return temp;
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        ll n, k;
        cin >> n >> k;

        double res = k * log10 (n);
        res = res - floor (res);
        res = pow (10, res) * 100;

        cout << (int) res << "...";
        int trail = trailing (n, k, 1000);
        if (trail <= 9) cout << "00" << trail << endl;
        else if (trail < 100) cout << "0" << trail << endl;
        else cout << trail << endl;
    }
    return 0;
}
