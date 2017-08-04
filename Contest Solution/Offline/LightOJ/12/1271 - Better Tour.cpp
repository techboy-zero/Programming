#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define PI (2 * acos (0))
#define mset(s,v) memset (s, v, sizeof(s))
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); i++)

using namespace std;

const int MAXN = 5e4 + 7;
vector <int> edges [MAXN];
int cost [MAXN], par [MAXN], ar [MAXN];
int n;

queue <int> q;

void BFS (int s) {
    cost [s] = 0;
    q.push (s);

    while (!q.empty ()) {
        int u = q.front ();
        q.pop ();

        FOREACH(v, edges [u]) {
            if (cost [*v] > cost [u] + 1) {
                cost [*v] = cost [u] + 1;
                q.push (*v);
                par [*v] = u;
            } else if (cost [*v] == cost [u] + 1) {
                if (par [*v] > u) {
                    q.push (*v);
                    par [*v] = u;
                }
            }
        }
    }
}

void Init () {
    for (int i = 0; i < n; i++) {
        edges [ar [i]].clear ();
        par [ar [i]] = ar [i];
        cost [ar [i]] = INF;
    }
}

int main () {
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> n;

        for (int i = 0; i < n; i++) cin >> ar [i];

        Init ();

        for (int i = 0; i < n - 1; i++) {
            edges [ar [i]].push_back (ar [i + 1]);
            edges [ar [i + 1]].push_back (ar [i]);
        }
        BFS (ar [n - 1]);
        printf ("Case %d:\n", kase);

        int x = ar [0];
        while (par [x] != x) {
            cout << x << " ";
            x = par [x];
        }
        cout << x << endl;
    }

    return 0;
}
