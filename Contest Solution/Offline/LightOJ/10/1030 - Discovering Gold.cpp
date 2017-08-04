#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i!=s.end(); i++)

using namespace std;
typedef long long ll;

const int MAX = 1e2 + 7;

double cache [MAX];
int arr [MAX];
bool visit [MAX];

int n;

double dpSum (int pos) {
    if (pos == n - 1) return arr [pos];
    double &ret = cache [pos];
    if (visit [pos]) return ret;
    visit [pos] = true;

    ret = arr [pos];
    int limit = min (6, n - 1 - pos);
    double prob = 1.0 / limit;
    for (int i = 1; i <= limit; i++) {
        ret += (prob * dpSum (pos + i));
    }
    return ret;
}

int main () {
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr [i];
        memset (visit, false, sizeof visit);
        double tot = dpSum (0);

        printf ("Case %d: %lf\n", kase, tot);
    }

    return 0;
}
