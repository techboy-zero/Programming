#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define FOREACH(i,s) for(__typeof((s).end()) i = (s).begin(); i != (s).end(); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 5e3, K = 12;

int n, r, cost [MAX + 7][K];
set <pair <int, int> > edge [MAX + 7];
priority_queue < pair <int, pair <int, int> > > pq;

void Init (int k) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cost [i][j] = INF;
        }
        edge [i].clear ();
    }
}

void kThBestShortestPath (int k) {
    cost [1][1] = 0;
    pq.push (make_pair (0, make_pair (1, 1)));

    while (!pq.empty ()) {
        int u = pq.top ().second.first, value = -pq.top ().first, curr = pq.top ().second.second;
        int temp;
        pq.pop ();
        FOREACH (i, edge [u]) {
            int c = (*i).second + value, v = (*i).first;
            for (temp = curr ; temp <= k; temp++) {
                if (c >= INF || c == cost [v][1]) break;
                if (cost [v][temp] > c) {
                    swap (c, cost [v][temp]);
                    pq.push (make_pair (-cost [v][temp], make_pair (v, temp)));
                    break;
                }
            }

            for (temp++; temp <= k; temp++) {
                if (c >= INF || c == cost [v][1]) break;
                if (cost [v][temp] > c) {
                    swap (c, cost [v][temp]);
                }
            }
        }
    }
}
