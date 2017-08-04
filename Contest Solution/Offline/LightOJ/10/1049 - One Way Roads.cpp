#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define FOREACH(i,s) for(__typeof((s).end()) i = (s).begin(); i != (s).end(); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 100 + 7;
int n, mn;
vector <pair <int, int> > edge [MAX];

void dfs (int u, int par, int cost, int cnt) {
    if (!cnt) {
         mn = min (mn, cost);
         return;
    }

    FOREACH (v, edge [u]) {
        int node = v -> first;
        if (node != par) {
            dfs (node, u, cost + v -> second, cnt - 1);
        }
    }
}

void init () {
    for (int i = 1; i <= n; i++) edge [i].clear ();
}

int main () {
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif // LOCAL

    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> n;
        init ();
        for (int i = 1; i <= n; i++) {
            int n1, n2, c;
            cin >> n1 >> n2 >> c;
            edge [n1].push_back (make_pair (n2, 0));
            edge [n2].push_back (make_pair (n1, c));
        }

        mn = INF;
        dfs (1, 0, 0, n);

        printf ("Case %d: %d\n", kase, mn);
    }

    return 0;
}
