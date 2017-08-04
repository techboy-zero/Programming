#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int prnt [500];

int main () {
    #ifdef TECHBOY
        freopen("input.txt", "r", stdin);
    #endif
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;
        for (int i = n; i >= 1; i--) {
            prnt [n - i + 1] = i;
        }
        for (int i = 1; i <= n; i++) {
            int curr = 1 - i + 1;

            for (int j = 1; j <= n; j++) {
                if (curr < 1) curr += n;
                else if (curr > n) curr -= n;
                cout << prnt [curr];
                if (j == n) cout << endl;
                else cout << " ";
                curr++;
            }
        }
    }

    return 0;
}

