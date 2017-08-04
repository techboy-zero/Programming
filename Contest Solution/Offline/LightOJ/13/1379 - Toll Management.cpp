#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i!=s.end(); i++)

using namespace std;
typedef long long ll;

const int MAX = 1e4 + 7, MAXM = 5e4 + 7;
struct edge {
    int x, y, c;
} ar [MAXM];

int n, m, s, t, p;
int cost [MAX], revcost [MAX];

priority_queue < pair <int, int> > pq;
vector < pair <int, int> > edges [MAX], revedges [MAX];

void Init () {
    for (int i = 1; i <= n; i++) {
        cost [i] = INF;
        revcost [i] = INF;
        edges [i].clear ();
        revedges [i].clear ();
    }
    cost [s] = 0;
    revcost [t] = 0;
}

void dijkstra (int start) {
    pq.push (make_pair (0, start));
    while (!pq.empty ()) {
        int u = pq.top ().second, curr = -pq.top ().first, sz = edges [u].size ();
        pq.pop();
        if (curr > cost [u]) continue;

        for (int i = 0; i < sz; i++) {
            int v = edges [u][i].first, c = edges [u][i].second;
            if (cost [v] > cost [u] + c) {
                cost [v] = cost [u] + c;
                pq.push (make_pair (-cost [v], v));
            }
        }
    }
}

void dijkstraRev (int start) {
    pq.push (make_pair (0, start));

    while (!pq.empty ()) {
        int u = pq.top ().second, curr = -pq.top ().first, sz = revedges [u].size ();
        pq.pop();
        if (curr > revcost [u]) continue;

        for (int i = 0; i < sz; i++) {
            int v = revedges [u][i].first, c = revedges [u][i].second;
//            cout << v << " " << revcost [v] << " " << revcost [u] + c << endl;
            if (revcost [v] > revcost [u] + c) {
                revcost [v] = revcost [u] + c;
                pq.push (make_pair (-revcost [v], v));
            }
        }
    }
}

bool comp (edge a, edge b) {
    if (a.c == b.c) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    }
    return a.c > b.c;
}

int main () {
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif

    int test;
    scanf ("%d", &test);

    for (int kase = 1; kase <= test; kase++) {
        scanf ("%d %d %d %d %d", &n, &m, &s, &t, &p);
        Init ();

        for (int i = 0; i < m; i++) {
            scanf ("%d %d %d", &ar [i].x, &ar [i].y, &ar [i].c);
            edges [ar [i].x].push_back (make_pair (ar [i].y, ar [i].c));
            revedges [ar [i].y].push_back (make_pair (ar [i].x, ar [i].c));
        }

        dijkstra (s);
        dijkstraRev (t);
        sort (ar, ar + m, comp);

//        for (int i = 1; i <= n; i++) {
//            cout << i << " " << cost [i] << " " << revcost [i] << endl;
//        }

        int mx = -1;
        for (int i = 0; i < m; i++) {
            if (ar [i].c + cost [ar [i].x] + revcost [ar [i].y] <= p) {
                mx = ar [i].c;
                break;
            }
        }

        printf ("Case %d: %d\n", kase, mx);
    }

    return 0;
}
