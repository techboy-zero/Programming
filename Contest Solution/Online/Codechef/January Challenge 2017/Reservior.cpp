#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e3 + 7;
char reservior [MAXN][MAXN];

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            cin >> reservior [i];
        }
        bool possible = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (reservior [i][j] == 'A') {
                    if (i && reservior [i - 1][j] != 'A') possible = false;
                    if (j != n - 1 && reservior [i][j + 1] == 'W') possible = false;
                    else if (j > 0 && reservior [i][j - 1] == 'W') possible = false;
                } else if (reservior [i][j] == 'W') {
                    if (!i && (!j || j == m - 1)) possible = false;
                    else if (i && reservior [i - 1][j] == 'B') possible = false;

                    if (j != n - 1 && reservior [i][j + 1] == 'A') possible = false;
                    else if (j > 0 && reservior [i][j - 1] == 'A') possible = false;
                }

                if (!possible) break;
            }
            if (!possible) break;
        }

        if (possible) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
