#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e3 + 7, MAXP = 1e5 + 7;

struct chefbook {
    int f, p;
    char s [110];
} ar [MAXN];

bool special [MAXP];

bool comp (chefbook a, chefbook b) {
    if (special [a.f] == special [b.f]) {
        return a.p > b.p;
    }
    return special [a.f];
}

int main () {
    int n, m;

    while (cin >> n >> m) {
        memset (special, false, sizeof special);
        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            special [num] = true;
        }

        for (int i = 0; i < m; i++) {
            cin >> ar [i].f >> ar [i].p >> ar [i].s;
        }

        sort (ar, ar + m, comp);

        for (int i = 0; i < m; i++) {
            cout << ar [i].s << endl;
        }
    }
    return 0;
}

