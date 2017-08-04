#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i!=s.end(); i++)

using namespace std;
typedef long long ll;

const int MAX = 20;

ll ar [20];
int n, m;

ll incExc (int pos, ll tot, int cnt) {
    if (pos == m) return (cnt % 2)? -(n / tot) : (n / tot);

    ll ret = incExc (pos + 1, tot, cnt);
    ll temp = (tot * ar [pos]) / __gcd (tot , ar [pos]);
    if (temp <= n) ret += incExc (pos + 1, temp, cnt + 1);
    return  ret;
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) cin >> ar [i];
        sort (ar, ar + m);
        printf ("Case %d: %lld\n", kase, incExc (0, 1, 0));
    }

    return 0;
}
