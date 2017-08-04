#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define FOREACH(i,s) for(__typeof((s).end()) i = (s).begin(); i != (s).end(); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main () {
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif // LOCAL

    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n, ans = 0, cnt = 0;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            if (num == 1) cnt++;
            ans ^= num;
        }

        if (cnt == n) {
            if (!ans) printf ("Case %d: Alice\n", kase);
            else printf ("Case %d: Bob\n", kase);
        } else {
            if (ans) printf ("Case %d: Alice\n", kase);
            else printf ("Case %d: Bob\n", kase);
        }
    }
    return 0;
}
