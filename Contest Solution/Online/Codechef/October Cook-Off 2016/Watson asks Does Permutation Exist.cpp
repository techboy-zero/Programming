#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 7;
int ar [MAXN];

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        bool possible = true;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> ar [i];
        sort (ar, ar + n);
        for (int i = 0; i < n - 1; i++) {
            if (ar [i + 1] - ar [i] > 1) {
                possible = false;
                break;
            }
        }

        if (possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

