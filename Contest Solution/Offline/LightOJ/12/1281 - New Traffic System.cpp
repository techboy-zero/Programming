#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i!=s.end(); i++)

using namespace std;
typedef long long ll;

const int MAXN = 1e4 + 7, MAXD = 20;

int n, m, k, d, cost [MAXN][MAXD];
vector <pair <int, pair <int, bool> > > edges [MAXN + 7];
priority_queue <pair <int, pair <int, int> > > pq;

void Init () {
    for (int i = 0; i <= d; i++) {
        for (int j = 0; j <= n; j++) {
            if (!j) cost [j][i] = 0;
            else cost [j][i] = INF;
        }
    }
    pq.push (make_pair (0, make_pair (0, 0)));
}

int Dijkstra (int start) {
    Init ();
    while (!pq.empty ()) {
        int u = pq.top ().second.first, ucost = -pq.top ().first, ud = pq.top ().second.second;
        pq.pop ();

        if (ucost > cost [u][ud]) continue;
        FOREACH (i, edges [u]) {
            int v = i -> first, value = i -> second.first, dvalue = i -> second.second;
            if (dvalue + ud <= d && cost [v][dvalue + ud] > cost [u][ud] + value) {
                cost [v][dvalue + ud] = cost [u][ud] + value;
                pq.push (make_pair (-cost [v][dvalue + ud], make_pair (v, dvalue + ud)));
            }
        }
    }

    int mn = INF;
    for (int i = 0; i <= d; i++) mn = min (mn, cost [n - 1][i]);
    return mn;
}

void Clear () {
    for (int i = 0; i <= n; i++) edges [i].clear ();
}

int main () {
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d %d %d %d", &n, &m, &k, &d);
        for (int i = 0; i < m; i++) {
            int n1, n2, c;
            scanf ("%d %d %d", &n1, &n2, &c);
            edges [n1].push_back (make_pair (n2, make_pair (c, false)));
        }
        for (int i = 0; i < k; i++) {
            int n1, n2, c;
            scanf ("%d %d %d", &n1, &n2, &c);
            edges [n1].push_back (make_pair (n2, make_pair (c, true)));
        }
        int tot = Dijkstra (0);
        if (tot == INF) printf ("Case %d: Impossible\n", kase);
        else printf ("Case %d: %d\n", kase, tot);
        Clear ();
    }
    return 0;
}
