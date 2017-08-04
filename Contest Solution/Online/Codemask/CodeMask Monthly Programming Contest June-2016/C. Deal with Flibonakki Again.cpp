#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e4 + 7;
const int MOD = 1e3 + 7;

ll fibo [MAX];
ll g [MAX];

void fibonacci () {
    fibo [1] = fibo [2] = 1;
    for (int i = 3; i <= 200; i++) {
        fibo [i] = (fibo [i - 1] + fibo [i - 2]) % MOD;
    }
}

void gGen () {
    g [0] = 0;
    for (int i = 1; i <= 27; i++) {
        g [i] = g [i - 1] + fibo [4 * i - 1];
        g [i] %= MOD;
    }
}

int main () {
    fibonacci();
    gGen ();
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        ll n;
        bool all = false;
        cin >> n;
        if (n / 27) all = true;
        n %= 27;
        if (all) n = 26;
        ll mx = -1;
        for (int i = 0; i <= n; i++) {
            mx = max (mx, g [i]);
        }
        cout << mx << endl;
    }
    return 0;
}
