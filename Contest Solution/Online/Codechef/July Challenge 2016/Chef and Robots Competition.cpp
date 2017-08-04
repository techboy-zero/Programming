#include <bits/stdc++.h>

#define INF 1e7
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e2 + 7;

int row;
int col;
int cost [2][MAX][MAX];
bool grid [MAX][MAX];
bool visit [2][MAX][MAX];

queue <pair <int, int> > nextpos;

void Init (int indx, int startx, int starty) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cost [indx][i][j] = INF;
            visit [indx][i][j] = false;
        }
    }
    cost [indx][startx][starty] = 0;
    visit [indx][startx][starty] = true;
}

bool isValid (int indx, int u, int v) {
    if (u < 0 || u >= row) return false;
    if (v < 0 || v >= col) return false;
    if (grid [u][v]) return false;
    return !visit [indx][u][v];
}

void competition (int startx, int starty, int indx, int jump) {
    Init (indx, startx, starty);
    nextpos.push (make_pair (startx, starty));

    while (!nextpos.empty()) {
        int x = nextpos.front ().first;
        int y = nextpos.front ().second;
        nextpos.pop ();

        for (int k = -jump; k <= jump; k++) {
            int limit = jump - abs (k);
            for (int l = -limit; l <= limit; l++) {
                int u = x + k;
                int v = y + l;
                if (isValid (indx, u, v)) {
                    cost [indx][u][v] = cost [indx][x][y] + 1;
                    nextpos.push (make_pair (u, v));
                    visit [indx][u][v] = true;
                }
            }
        }
    }
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int k1;
        int k2;
        cin >> row >> col >> k1 >> k2;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> grid [i][j];
            }
        }

        competition (0, 0, 0, k1);
        competition (0, col - 1, 1, k2);

        int mn = INF;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int mx = max (cost [0][i][j] , cost [1][i][j]);
                if (mx < mn) {
                    mn = mx;
                }
            }
        }

        if (mn >= INF) cout << -1 << endl;
        else cout << mn << endl;
    }

    return 0;
}
