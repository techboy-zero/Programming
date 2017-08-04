#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e5 + 7;

char village [MAX];
int dist [MAX];

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;
        cin >> village;
        for (int i = 0; i < n; i++) {
            cin >> dist [i];
        }
        int prev = -1;
        int ans = dist [n - 1] - dist [0];
        int mx = -1;
        for (int i = 0; i < n; i++) {
            if (i) mx = max (mx, dist [i] - dist [i - 1]);
            if (village [i] == '1') {
                if (prev != -1) {
                    ans -= mx;
                }
                prev = i;
                mx = -1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
