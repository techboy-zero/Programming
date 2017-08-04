#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;
ll fact [MAX];
vector <int> edges [MAX];

ll dfs (int u, int p) {
    ll res = 1;
    FOREACH (v, edges [u]) {
        if (*v != p) res *= dfs (*v, u);
        if (res >= MOD) res %= MOD;
    }
    int sz = edges [u].size ();
    if (p == -1) return (fact [sz] * res) % MOD;
    return (res * fact [sz - 1]) % MOD;
}

void factGen () {
    fact [0] = 1;
    for (int i = 1; i <= MAX - 7; i++) {
        fact [i] = fact [i - 1] * i;
        if (fact [i] >= MOD) fact [i] %= MOD;
    }
}

int main () {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    factGen ();
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;

        for (int i = 0; i < n - 1; i++) {
            int node1, node2;
            cin >> node1 >> node2;
            edges [node1].push_back (node2);
            edges [node2].push_back (node1);
        }

        int start;
        cin >> start;
        cout << (dfs (start, -1) % MOD) << endl;
        for (int i = 1; i <= n; i++) edges [i].clear ();
    }
    return 0;
}
