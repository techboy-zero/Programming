#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e9
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e2 + 7;
struct soda {
    int a, b;
} bottle [MAXN];

pair <int, int> cache [MAXN][MAXN * MAXN];
bool visit [MAXN][MAXN * MAXN];
int n;

bool comp (soda x, soda y) {
    if (x.b == y.b) return x.a < y.a;
    return x.b < y.b;
}

pair <int, int> dp (int pos, int rem) {
    if (rem <= 0) return make_pair (0, 0);
    if (pos == n) return make_pair (101, 0);

    pair <int, int> &ret = cache [pos][rem];
    if (visit [pos][rem]) return ret;
    visit [pos][rem] = true;

    ret = dp (pos + 1, rem);
    pair <int, int> temp = dp (pos + 1, rem - bottle [pos].b);

    int cost;
    if (bottle [pos].a > rem) cost = - (bottle [pos].a - rem);
    else cost = min ((rem - bottle [pos].a), (bottle [pos].b - bottle [pos].a));

    temp.first++;
    temp.second += cost;

    if (temp.first < ret.first) ret = temp;
    else if (temp.first == ret.first && temp.second < ret.second) ret = temp;

    return ret;
}

int main () {
    #ifdef TECHBOY
        freopen("input.txt", "r", stdin);
    #endif

    while (cin >> n) {
        int tot = 0;
        for (int i = 0; i < n; i++) {
            cin >> bottle [i].a;
            tot += bottle [i].a;
        }
        for (int i = 0; i < n; i++) {
            cin >> bottle [i].b;
        }
        sort (bottle, bottle + n, comp);
        memset (visit, false, sizeof visit);
        pair <int, int> ans = dp (0, tot);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}

