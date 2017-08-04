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
        int k, prev = -1, ans = 0;
        cin >> k;
        k <<= 1;
        for (int i = 0; i < k; i++) {
            int num;
            cin >> num;
            if (i % 2) ans ^= (num - prev - 1);
            prev = num;
        }

        if (ans) printf ("Case %d: Alice\n", kase);
        else printf ("Case %d: Bob\n", kase);
    }

    return 0;
}
