#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e3 + 7;
const int MOD = 1e9 + 7;
int d, c, n1, n2;

ll cache [3][MAX][MAX];
bool visit [3][MAX][MAX];

ll dp (int state, int i, int j) {
    if (!i) {
        if (j > n2) return 0;
        return 1;
    }
    if (!j) {
        if (i > n1) return 0;
        return 1;
    }
    ll &ret = cache [state][i][j];
    if (visit [state][i][j]) return ret;
    visit [state][i][j] = true;

    ret = 0;
    if (!state) {
        int lim1 = min (i, n1);
        int lim2 = min (j, n2);
        for (int k = 1; k <= lim1; k++) {
            ret += dp (2, i - k, j);
            if (ret >= MOD) ret %= MOD;
        }
        for (int k = 1; k <= lim2; k++) {
            ret += dp (1, i, j - k);
            if (ret >= MOD) ret %= MOD;
        }
    } else if (state == 1) {
        int lim1 = min (i, n1);
        for (int k = 1; k <= lim1; k++) {
            ret += dp (2, i - k, j);
            if (ret >= MOD) ret %= MOD;
        }
    } else {
        int lim2 = min (j, n2);
        for (int k = 1; k <= lim2; k++) {
            ret += dp (1, i, j - k);
            if (ret >= MOD) ret %= MOD;
        }
    }

    return ret;
}

int main () {
    #ifdef TECHBOY
        freopen("input.txt", "r", stdin);
    #endif
    while (cin >> d >> c >> n1 >> n2) {
        memset (visit, false, sizeof visit);
        cout << dp (0, d, c) << endl;
    }

    return 0;
}

