#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 3e2 + 7;
int cost [MAX][MAX];

void floydWarshall (int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cost [i][j] = min(cost [i][j], cost [i][k] + cost [k][j]);
            }
        }
    }
}

void Init (int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cost [i][j] = 0;
            else cost [i][j] = INF;
        }
    }
}

int main () {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int n, e;
    while (cin >> n >> e) {
        Init (n);
        for (int i = 0; i < e; i++) {
            int n1, n2, c;
            cin >> n1 >> n2 >> c;
            cost [n1][n2] = cost [n2][n1] = c;
        }
        floydWarshall(n);
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                mx = max (mx, cost [i][j]);
            }
        }
        cout << mx << endl;
    }
    return 0;
}
