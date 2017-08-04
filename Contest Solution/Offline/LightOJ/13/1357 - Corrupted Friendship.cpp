#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e5 + 7;
vector <int> edges [MAX];
int frend [MAX];

int dfs (int u, int p) {
    frend [u] = 0;
    int sz = edges [u].size ();
    for (int i = 0; i < sz; i++) {
        int v = edges [u][i];
        if (v != p) frend [u] += dfs (v, u);
    }
    if (u != 1) return frend [u] + 1;
    return frend [u];
}

int main () {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int test;
    scanf ("%d", &test);

    for (int kase = 1; kase <= test; kase++) {
        int node;
        scanf ("%d", &node);
        for (int i = 1; i <= node; i++) edges [i].clear ();
        for (int i = 1; i < node; i++) {
            int n1, n2;
            scanf ("%d %d", &n1, &n2);
            edges [n1].push_back (n2);
            edges [n2].push_back (n1);
        }
        frend [1] = dfs (1, 1);
        ll res = (ll) node * node - node;
        for (int i = 1; i <= node; i++) {
            res -= 2 * frend [i];
        }
        printf ("Case %d: %d %lld\n", kase, node - 1, res / 2);
    }
    return 0;
}
