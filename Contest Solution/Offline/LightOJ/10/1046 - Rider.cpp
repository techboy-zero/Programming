#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define FOREACH(i,s) for(__typeof((s).end()) i = (s).begin(); i != (s).end(); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 12;
int n, m;
int cost [MAX][MAX], chess [MAX][MAX];
char grid [MAX][MAX];
bool visit [MAX][MAX];

int dr [] = {1, 1, -1, -1, 2, 2, -2, -2};
int dc [] = {-2, 2, -2, 2, 1, -1, 1, -1};

queue <pair <int, pair <int, int> > > q;

bool is_valid (int x, int y) {
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= m) return false;
    return !visit [x][y];
}

void bfs (int sx, int sy, int k) {
    memset (visit, false, sizeof (visit));
    q.push (make_pair (0, make_pair (sx, sy)));
    visit [sx][sy] = true;
    chess [sx][sy]++;

    while (!q.empty ()) {
        int curr = q.front ().first + 1, x = q.front ().second.first, y = q.front ().second.second;
        q.pop ();

        for (int i = 0; i < 8; i++) {
            int tx = x + dr [i], ty = y + dc [i];
            if (is_valid (tx, ty)) {
                q.push (make_pair (curr, make_pair (tx, ty)));
                visit [tx][ty] = true;
                cost [tx][ty] += curr / k + (curr % k > 0);
                chess [tx][ty]++;
            }
        }
    }
}

int main () {
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif // LOCAL

    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        memset (cost, 0, sizeof (cost));
        memset (chess, 0, sizeof (chess));
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> grid [i];

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid [i][j] >= '1' && grid [i][j] <= '9') {
                    ++cnt;
                    bfs (i, j, grid [i][j] - '0');
                }
            }
        }
        int mn = INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (chess [i][j] == cnt) {
                    mn = min (mn, cost [i][j]);
                }
            }
        }

        printf ("Case %d: ", kase);
        if (mn == INF) cout << -1 << endl;
        else cout << mn << endl;
    }

    return 0;
}
