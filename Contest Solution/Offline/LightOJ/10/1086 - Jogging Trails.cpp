#include <bits/stdc++.h>

#define INF 1e18
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = (1 << 15) + 7,MAXN = 20;

int n, m;
int degree [MAXN];
ll cost [MAXN][MAXN];
ll cache [MAX];
bool check [MAX];

void Init () {
    memset (check, false, sizeof check);
    memset (degree, 0, sizeof degree);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cost [i][j] = cost [j][i] = INF;
            if (i == j) cost [i][j] = 0;
        }
    }
}

void floydWarshall () {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cost [i][j] = min(cost [i][j], cost [i][k] + cost [k][j]);
            }
        }
    }
}

ll dp (int mask) {
    if (mask == (1 << n) - 1) return 0;
    ll &ret = cache [mask];
    if (check [mask]) return cache [mask];

    ret = INF;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) continue;
        for (int j = i + 1; j < n; j++) {
            if (mask & (1 << j)) continue;
            int currcost = cost [i][j];
            ret = min (ret, currcost + dp (mask | (1 << i) | (1 << j)));
        }
    }
    return ret;
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> n >> m;
        Init ();
        ll eulercost = 0;
        for (int i = 1; i <= m; i++) {
            int node1, node2;
            ll value;
            cin >> node1 >> node2 >> value;
            cost [node1 - 1][node2 - 1] = min (cost [node1 - 1][node2 - 1], value);
            cost [node2 - 1][node1 - 1] = cost [node1 - 1][node2 - 1];
            degree [node1 - 1]++;
            degree [node2 - 1]++;
            eulercost += value;
        }
        floydWarshall();
        int mask = 0;
        for (int i = 0; i < n; i++) {
            if (degree [i] % 2 == 0) {
                mask |= (1 << i);
            }
        }

        printf ("Case %d: %lld\n", kase, eulercost + dp (mask));
    }

    return 0;
}
