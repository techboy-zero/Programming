#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define FOREACH(i,s) for(__typeof((s).end()) i = (s).begin(); i != (s).end(); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1000 + 7;
int cache [MAX][MAX];
bool visit [MAX][MAX];

int dr [] = {-3, -2, -2, -1, -1,  1};
int dc [] = {-1, -1,  1, -3, -2, -2};

bool isValid (int i, int j) {
    if (i < 0 || j < 0) return false;
    return true;
}

int grundy (int i, int j) {
    int &ret = cache [i][j];
    if (visit [i][j]) return ret;
    visit [i][j] = true;

    set <int> s;
    ret = 0;
    for (int k = 0; k < 6; k++) {
        if (!isValid (i + dr [k], j + dc [k])) continue;
        s.insert (grundy (i + dr [k], j + dc [k]));
    }
    while (s.find (ret) != s.end ()) ret++;
    return ret;
}

int main () {
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif // LOCAL
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            res ^= grundy (x, y);
        }

        if (!res) printf ("Case %d: Bob\n", kase);
        else printf ("Case %d: Alice\n", kase);
    }

    return 0;
}
