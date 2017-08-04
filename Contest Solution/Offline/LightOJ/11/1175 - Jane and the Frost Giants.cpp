#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define FOREACH(i,s) for(__typeof((s).end()) i = (s).begin(); i != (s).end(); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 200 + 7;
char grid [MAX][MAX];
bool visit [MAX][MAX];
int n, m, ans, cost [MAX][MAX], danger [MAX][MAX];

int dr [] = {1, -1, 0, 0};
int dc [] = {0, 0, 1, -1};

queue <pair <int, int> > q;

void init () {
    memset (visit, false, sizeof (visit));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            danger [i][j] = INF;
        }
    }
}

bool firecheck (int tx, int ty, int c) {
    if (tx < 0 || tx >= n) return false;
    if (ty < 0 || ty >= m) return false;
    if (grid [tx][ty] == '#') return false;
    if (danger [tx][ty] <= c) return false;

    return true;
}

bool check (int tx, int ty, int c) {
    if (tx < 0 || tx >= n) return false;
    if (ty < 0 || ty >= m) return false;
    if (grid [tx][ty] == '#') return false;
    if (visit [tx][ty]) return false;
    if (danger [tx][ty] <= c) return false;

    return true;
}

void fire (int i, int j) {
    q.push (make_pair (i, j));
    danger [i][j] = 0;

    while (!q.empty ()) {
        int x = q.front ().first, y = q.front ().second;
        q.pop ();

        for (int k = 0; k < 4; k++) {
            int tx = x + dr [k], ty = y + dc [k];

            if (firecheck (tx, ty, danger [x][y] + 1)) {
                q.push (make_pair (tx, ty));
                danger [tx][ty] = danger [x][y] + 1;
            }
        }
    }
}

void escape (int i, int j) {
    q.push (make_pair (i, j));
    cost [i][j] = 0;

    while (!q.empty ()) {
        int x = q.front ().first, y = q.front ().second;
        if (x == 0 || x == n - 1) ans = min (ans, cost [x][y] + 1);
        if (y == 0 || y == m - 1) ans = min (ans, cost [x][y] + 1);
        q.pop ();

        for (int k = 0; k < 4; k++) {
            int tx = x + dr [k], ty = y + dc [k];

            if (check (tx, ty, cost [x][y] + 1)) {
                q.push (make_pair (tx, ty));
                cost [tx][ty] = cost [x][y] + 1;
                visit [tx][ty] = true;
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
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> grid [i];
        init ();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid [i][j] == 'F') {
                    fire (i, j);
                }
            }
        }

        ans = INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid [i][j] == 'J') {
                    escape (i, j);
                }
            }
        }

        printf ("Case %d: ", kase);
        if (ans == INF) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }

    return 0;
}
