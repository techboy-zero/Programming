#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 2e3 + 9;
int ar [MAXN];

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> ar [i];
        }

        for (int i = 0; i < n; i++) {
            ll tot = ar [i];
            for (int j = i + 1; j < n; j++) {
                tot += ar [j];
            }
        }
    }

    return 0;
}
