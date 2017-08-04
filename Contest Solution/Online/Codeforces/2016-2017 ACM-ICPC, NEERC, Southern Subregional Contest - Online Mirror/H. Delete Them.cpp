#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e2 + 7;
char pattern [MAXN][MAXN];
int del [MAXN], len [MAXN];
char ans [MAXN];

int main () {
    //freopen ("input.txt", "r", stdin);

    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            cin >> pattern [i];
            len [i] = strlen (pattern [i]);
        }
        bool possible = true;
        for (int i = 1; i <= m; i++) {
            cin >> del [i];
            if (i > 1 && len [del [i]] != len [del [i - 1]]) possible = false;
        }
        if (!possible) {
            cout << "No" << endl;
            continue;
        }
        for (int i = 1; i <= m; i++) {
            if (i == 1) strcpy (ans, pattern [del [i]]);
            else {
                for (int j = 0; ans [j]; j++) {
                    if (ans [j] != '?' && pattern [del [i]][j] != ans [j]) {
                        ans [j] = '?';
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (len [i] != len [del [1]]) continue;
            bool deleted = true;
            for (int j = 0; ans [j]; j++) {
                if (ans [j] != '?' && pattern [i][j] != ans [j]) {
                    deleted = false;
                    break;
                }
            }
            if (deleted) cnt++;
        }

        if (cnt > m) possible = false;
        if (!possible) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            cout << ans << endl;
        }
    }
    return 0;
}

