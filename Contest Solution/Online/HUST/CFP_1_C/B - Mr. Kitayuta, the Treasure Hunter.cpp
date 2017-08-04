#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 3e4 + 7, MAXD = 6e2 + 7;

int cache [MAXN][MAXD];
int gem [MAXN], island;
int offset;

int dp (int pos, int d) {
    if (pos > island) return 0;
    if (cache [pos][d - offset] != -1) return cache [pos][d - offset];
    cache [pos][d - offset] = 0;
    if (!pos) {
        cache [pos][d - offset] = dp (pos + d, d);
    } else {
        if (d > 1 && pos + d - 1 <= island) cache [pos][d - offset] = dp (pos + d - 1, d - 1);
        if (pos + d <= island) cache [pos][d - offset] = max (cache [pos][d - offset], dp (pos + d, d));
        if (pos + d + 1 <= island) cache [pos][d - offset] = max (cache [pos][d - offset], dp (pos + d + 1, d + 1));
        cache [pos][d - offset] += gem [pos];
    }
    return cache [pos][d - offset];
}

void Init () {
    memset (gem, 0, sizeof gem);
    memset (cache, -1, sizeof cache);
    island = 0;
}

int main () {
    int n, d;
    while (cin >> n >> d) {
        Init ();
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            gem [num]++;
            island = max (island, num);
        }
        offset = d - 250;
        cout << dp (0, d) << endl;
    }

    return 0;
}
