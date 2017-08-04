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
        ll gcd, lcm;
        cin >> gcd >> lcm;
        if (lcm % gcd == 0) cout << gcd << " " << lcm << endl;
        else cout << -1 << endl;
    }

    return 0;
}
