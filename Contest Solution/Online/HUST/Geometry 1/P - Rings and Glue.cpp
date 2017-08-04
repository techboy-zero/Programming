#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-12
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e2 + 7;

struct circle {
    double cx;
    double cy;
    double rad;
} ar [MAX];

bool visit [MAX];
int cnt;
vector <int> edges [MAX];

bool isOverlapped (int i, int j) {
    double distance = (ar [i].cx - ar [j].cx) * (ar [i].cx - ar [j].cx) + (ar [i].cy - ar [j].cy) * (ar [i].cy - ar [j].cy);
    double r = min (ar [i].rad, ar [j].rad);
    double R = max (ar [i].rad, ar [j].rad);

    distance = sqrt (distance);
    if (r + R <= distance) return false;
    if (distance + r <= R) return false;
    return true;
}

void dfs (int u) {
    visit [u] = true;
    cnt++;
    int sz = edges [u].size ();
    for (int i = 0; i < sz; i++) {
        int v = edges [u][i];
        if (!visit [v]) dfs (v);
    }
}

int main () {
    int n;
    while (cin >> n && n != -1) {
        for (int i = 1; i <= n; i++) {
            cin >> ar [i].cx >> ar [i].cy >> ar [i].rad;
            edges [i].clear ();
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (isOverlapped (i, j)) {
                    edges [i].push_back (j);
                    edges [j].push_back (i);
                }
            }
        }
        memset (visit, false, sizeof visit);
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            cnt = 0;
            if (!visit [i]) dfs (i);
            mx = max (mx, cnt);
        }
        if (mx == 1) printf ("The largest component contains %d ring.\n", mx);
        else printf ("The largest component contains %d rings.\n", mx);
    }
    return 0;
}
