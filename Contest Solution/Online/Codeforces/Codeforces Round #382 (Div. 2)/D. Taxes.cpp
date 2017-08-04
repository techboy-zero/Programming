#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main () {
    ll n;
    while (cin >> n) {
        bool prime = true;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) prime = false;
        }
        if (prime) cout << 1 << endl;
        else {
            if (n % 2 == 0) cout << 2 << endl;
            else {
                n -= 2;
                bool prime = true;
                for (ll i = 2; i * i <= n; i++) {
                    if (n % i == 0) prime = false;
                }
                if (prime) cout << 2 << endl;
                else cout << 3 << endl;
            }
        }
    }
    return 0;
}

