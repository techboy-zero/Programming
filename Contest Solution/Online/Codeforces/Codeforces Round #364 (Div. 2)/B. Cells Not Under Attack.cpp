#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e5 + 7;

int ar [MAX], ac [MAX];
bool rcheck [MAX], ccheck [MAX];

int main () {
    int n, m;

    while (cin >> n >> m) {
        memset (rcheck, false, sizeof rcheck);
        memset (ccheck, false, sizeof ccheck);
        for (int i = 1; i <= n; i++) {
            ar [i] = n;
            ac [i] = n;
        }
        int row = 0, col = 0;
        ll tot = (ll) n * n;
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            ll temp = (ar [x] - row) > 0? (ar [x] - row) : 0;
            temp += (ac [y] - col) > 0? (ac [y] - col) : 0;
            tot -= temp;
            if (!ccheck [y] && !rcheck [x]) tot++;
            if (!ccheck [y]) row++;
            if (!rcheck [x]) col++;
            ccheck [y] = rcheck [x] = true;
            ar [x] = ac [y] = 0;
            cout << tot;
            if (i != m) cout << " ";
            else cout << endl;
        }
    }

    return 0;
}
