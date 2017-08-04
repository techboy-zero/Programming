#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e6 + 7;
int turns [MAXN];

int main () {
    int n, q;
    while (scanf ("%d %d", &n, &q) != EOF) {
        for (int i = 1; i <= n; i++) {
            turns [i] = 0;
            int stones;
            scanf ("%d", &stones);
            while (stones) {
                stones /= 2;
                turns [i]++;
            }
            turns [i] += turns [i - 1];
        }

        for (int i = 1; i <= q; i++) {
            int l, r;
            scanf ("%d %d", &l, &r);
            int ans = turns [r] - turns [l - 1];
            if (ans % 2) puts ("Mishki");
            else puts ("Hacker");
        }
    }
    return 0;
}

