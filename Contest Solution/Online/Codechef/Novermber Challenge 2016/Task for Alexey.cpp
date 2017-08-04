#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e18
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll arr [510];

int main () {
    #ifdef TECHBOY
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> arr [i];
        }

        ll mn = INF;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mn = min (mn, (arr [i] * arr [j]) / __gcd (arr [i], arr [j]));
            }
        }
        cout << mn << endl;
    }
    return 0;
}

