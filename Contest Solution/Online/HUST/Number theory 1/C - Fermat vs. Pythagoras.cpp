#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

bool mark [MAX];

int main () {
    ll n;
    while (cin >> n) {
        int pcnt = 0;
        int triplet = n;
        memset (mark, false, sizeof mark);
        for (ll i = 1; i <= n; i++) {
            for (ll j = i + 1; j <= n && (i * i + j * j <= n); j++) {
                ll frst = j * j - i * i;
                ll scnd = 2 * i * j;
                ll thrd = i * i + j * j;

                if (__gcd (frst,scnd) == 1 && __gcd (scnd, thrd) == 1) {
                    pcnt++;
                    for (ll k = 1; thrd * k <= n; k++) {
                        if (!mark [frst * k]) triplet--;
                        if (!mark [scnd * k]) triplet--;
                        if (!mark [thrd * k]) triplet--;
                        mark [frst * k] = mark [scnd * k] = mark [thrd * k] = true;
                    }
                }
            }
        }
        cout << pcnt << " " << triplet << endl;
    }
    return 0;
}
