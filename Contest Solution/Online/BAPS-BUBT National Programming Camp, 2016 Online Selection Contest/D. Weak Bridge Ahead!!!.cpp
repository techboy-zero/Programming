#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 7;
ll lft [MAXN], rght [MAXN];

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        ll n, m;
        ll wait = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> lft [i];
            wait += lft [i];
        }
        for (int i = 0; i < m; i++) {
            cin >> rght [i];
            wait += rght [i];
        }
        wait -= max (rght [m - 1], lft [n - 1]);
        printf ("Case %d: %lld\n", kase, wait);
    }

    return 0;
}

