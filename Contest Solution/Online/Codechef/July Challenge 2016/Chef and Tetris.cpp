#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e4 + 7;

int n;
ll a [MAX];
ll b [MAX];
ll tot;

void tetris (int i, ll lft) {
    if (i && b [i - 1] == lft) {
        b [i - 1] = 0;
        a [i] = tot;
    } else if (i && b [i - 1] + b [i] == lft) {
        b [i - 1] = b [i] = 0;
        a [i] = tot;
    } else if (i > 0 && i < n - 1 && b [i - 1] + b [i + 1] == lft) {
        b [i - 1] = b [i + 1] = 0;
        a [i] = tot;
    } else if (b [i] == lft) {
        b [i] = 0;
        a [i] = tot;
    } else if (i != n - 1 && b [i] + b [i + 1] == lft) {
        b [i] = b [i + 1] = 0;
        a [i] = tot;
    } else if (i != n - 1 && b [i + 1] == lft) {
        b [i + 1] = 0;
        a [i] = tot;
    }  else if (i > 0 && i < n - 1 && b [i - 1] + b [i] + b [i + 1] == lft) {
        b [i - 1] = b [i] = b [i + 1] = 0;
        a [i] = tot;
    }
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        tot = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> b [i];
            tot += b [i];
        }
        for (int i = 0; i < n; i++) {
            cin >> a [i];
            tot += a [i];
        }

        if (tot % n) cout << -1 << endl;
        else {
            tot /= n;
            for (int i = 0; i < n; i++) {
                ll lft = tot - a [i];
                if (lft <= 0) continue;
                tetris (i, lft);
            }
            bool possible = true;
            for (int i = 0; i < n; i++) {
                if (b [i] || a [i] != tot) {
                    possible = false;
                    break;
                }
            }
            if (!possible) cout << -1 << endl;
            else cout << tot << endl;
        }
    }

    return 0;
}
