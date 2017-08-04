#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 7;
map <pair <int, int>, bool> path;
vector <int> edge [MAXN];
pair <int, int> edgelist [2 * MAXN];
vector <int> order;
bool visited [MAXN];
int sz;

void init (int n) {
    for (int i = 1; i <= n; i++) {
        edge [i].clear ();
    }
    path.clear ();
    order.clear ();
}

void eulerCircuit (int u) {
    if (!visited [u]) {
        visited [u] = true;
        sz--;
    }

    while (!edge [u].empty ()) {
        int v = edge [u].front ();
        path [make_pair (u, v)] = true;
        edge [u].erase (edge [u].begin ());

        FOREACH (i, edge [v]) {
            if (*i == u) {
                edge [v].erase (i);
                break;
            }
        }

        eulerCircuit (v);
    }
    order.push_back (u);
}

int main () {
    int n, e;

    while (cin >> n >> e) {
        init (n);
        for (int i = 0; i < e; i++) {
            cin >> edgelist [i].first >> edgelist [i].second;

            edge [edgelist [i].first].push_back (edgelist [i].second);
            edge [edgelist [i].second].push_back (edgelist [i].first);
        }

        sz = n;
        memset (visited, false, sizeof visited);
        eulerCircuit (1);

        if (order.front () != 1 || order.back () != 1 || sz) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int i = 0; i < e; i++) {
                int u = edgelist [i].first;
                int v = edgelist [i].second;

                if (path.find (make_pair (u, v)) == path.end ()) cout << v << " " << u << endl;
                else cout << u << " " << v << endl;
            }
        }
    }

    return 0;
}
