#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5 + 7;
char str [MAX];
int cache [2][3][MAX];
bool visit [2][3][MAX];

int dp (int state, int curr, int pos) {
    if (!str [pos]) {
        if (curr != 2) return -INF;
        return 0;
    }
    int &ret = cache [state][curr][pos];
    if (visit [state][curr][pos]) return ret;
    visit [state][curr][pos] = true;

    ret = 0;
    if (!state) {
        if (str [pos] == 'I') ret = dp (1, 0, pos + 1) + 1;
        else ret = dp (0, 0, pos + 1);
    } else {
        if (!curr) {
            if (str [pos] == 'I') ret = dp (1, 0, pos + 1) + 1;
            else if (str [pos] == 'E') {
                ret = dp (1, 0, pos + 1);
                ret = max (ret, dp (1, 1, pos + 1) + 1);
            } else ret = dp (1, 0, pos + 1);
        } else if (curr == 1) {
            if (str [pos] == 'E') ret = dp (1, 1, pos + 1) + 1;
            else if (str [pos] == 'M') {
                ret = dp (1, 1, pos + 1);
                ret = max (ret, dp (1, 2, pos + 1) + 1);
            } else ret = dp (1, 1, pos + 1);
        } else {
            if (str [pos] == 'M') ret = dp (1, 2, pos + 1) + 1;
            else ret = dp (1, 2, pos + 1);
        }
    }

    return ret;
}

int main () {
    #ifdef TECHBOY
        freopen("input.txt", "r", stdin);
    #endif

    while (cin >> str) {
        memset (visit, false, sizeof visit);
        int ans = dp (0, 0, 0);
        if (ans < 0) ans = 0;
        cout << ans << endl;
    }

    return 0;
}

