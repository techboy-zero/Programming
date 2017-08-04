#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i!=s.end(); i++)

using namespace std;
typedef long long ll;

const int MAX = 1e5 + 7;

double cache [MAX];
bool visit [MAX];

vector <int> divisors [MAX];

double dp (int n) {
    if (n == 1) return 0;
    double &ret = cache [n];
    if (visit [n]) return ret;
    visit [n] = true;

    int d = divisors [n].size ();
    double prob = 1.0 / d;
    ret = prob;
    for (int i = 1; i < d; i++) {
        ret += (dp (n / divisors [n][i]) + 1) * prob;
    }
    ret *= (d * 1.0) / (d - 1);

    return ret;
}

void pregen () {
    for (int i = 1; i <= MAX - 7; i++) {
        for (int j = 1; (ll) j * j <= i; j++) {
            if (i % j) continue;
            divisors [i].push_back (j);
            if ((ll) j * j == i) continue;
            divisors [i].push_back (i / j);
        }
    }
}

int main () {
    pregen ();
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;

        memset (visit, false, sizeof visit);
        double res = dp (n);
        printf ("Case %d: %lf\n", kase, res);
    }

    return 0;
}
