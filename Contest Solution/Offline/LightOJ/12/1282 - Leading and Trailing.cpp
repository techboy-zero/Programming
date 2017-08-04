#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i!=s.end(); i++)

using namespace std;
typedef long long ll;

const int MAX = 1e6;

ll last3Digit (ll n, ll p, ll m) {
    if (!p) return 1;
    if (p == 1) return n % m;

    ll temp = last3Digit (n , p >> 1, m);
    temp = (temp * temp) % m;
    if (p % 2) temp = (temp * n) % m;
    return temp;
}

double get3Digit (double num) {
    while (num >= 1000) num /= 10;
    return num;
}

double first3Digit (ll n, ll p) {
    if (!p) return 1;
    if (p == 1) return get3Digit (n);

    double temp = first3Digit (n, p >> 1);
    temp = temp * temp;
    if (p % 2) temp *= n;
    temp = get3Digit (temp);
    return temp;
}

int main () {
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        ll n, k;
        cin >> n >> k;
        ll last3 = last3Digit (n, k, 1000);
        ll first3 = first3Digit (n, k);
        printf ("Case %d: %03lld %03lld\n", kase, first3, last3);
    }

    return 0;
}
