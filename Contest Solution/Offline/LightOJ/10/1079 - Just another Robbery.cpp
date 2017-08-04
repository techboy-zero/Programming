#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e2 + 7;

double p, robbery [MAX];
int n;
int bank [MAX];
bool check [MAX][MAX * MAX];
double cache [MAX][MAX * MAX];

double dp (int pos, int money) {
    if (money <= 0) return 0;
    if (pos == n) {
        if (money) return INF;
        return 0;
    }
    double &ret = cache [pos][money];
    if (check [pos][money]) return ret;
    check [pos][money] = true;

    ret = INF;
    ret = min (ret, dp (pos + 1, money));
    ret = min (ret, robbery [pos] + (1 - robbery [pos]) * dp (pos + 1, money - bank [pos]));

    return ret;
}

int binarySearch (int lo, int hi) {
    int ans = 0;
    memset (check, false, sizeof check);
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        double prob = dp (0, mid);
        if (prob < p) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main () {
    #ifdef TECHBOY
        freopen("input.txt", "r", stdin);
    #endif
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> p >> n;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            cin >> bank [i] >> robbery [i];
            tot += bank [i];
        }

        int ans = binarySearch (0, tot);
        printf ("Case %d: %d\n", kase, ans);
    }

    return 0;
}
