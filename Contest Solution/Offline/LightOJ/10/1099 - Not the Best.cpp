/* C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/* C++ STL */
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <queue>

/* Macros */
#define EPS 1e-9
#define PI acos(-1)
#define INF 1e9
#define FOREACH(i,s) for(__typeof((s).end()) i = (s).begin (); i != (s).end (); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 5e3, K = 5;

int n, r, cost [MAX + 7][K];
set <pair <int, int> > edge [MAX + 7];
priority_queue < pair <int, pair <int, int> > > pq;

void kThBestShortestPath (int k) {
    cost [1][1] = 0;
    pq.push (make_pair (0, make_pair (1, 1)));

    while (!pq.empty ()) {
        int u = pq.top ().second.first, value = -pq.top ().first, curr = pq.top ().second.second;
        int temp;
//        cout << endl;
//        cout << u << " " << value << " " << curr << endl;
        pq.pop ();
        FOREACH (i, edge [u]) {
            int c = (*i).second + value, v = (*i).first;
            for (temp = curr ; temp <= k; temp++) {
                if (c >= INF || c == cost [v][1]) break;
                if (cost [v][temp] > c) {
                    swap (c, cost [v][temp]);
//                    cout << v << " " << cost [v][temp] << " " << temp << endl;
                    pq.push (make_pair (-cost [v][temp], make_pair (v, temp)));
                    break;
                }
            }

            for (temp++; temp <= k; temp++) {
                if (c >= INF || c == cost [v][1]) break;
                if (cost [v][temp] > c) {
                    swap (c, cost [v][temp]);
//                    cout << v << " " << cost [v][temp] << " " << temp << endl;
                }
            }
        }
    }
}

void Init (int k) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cost [i][j] = INF;
        }
        edge [i].clear ();
    }
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> n >> r;
        Init (2);
        for (int i = 1; i <= r; i++) {
            int x, y, c;
            cin >> x >> y >> c;
            edge [x].insert (make_pair (y, c));
            edge [y].insert (make_pair (x, c));
        }
        kThBestShortestPath (2);
        printf ("Case %d: %d\n", kase, cost [n][2]);
    }

    return 0;
}
