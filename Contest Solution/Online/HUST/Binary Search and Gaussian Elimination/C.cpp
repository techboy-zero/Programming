#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e3 + 7;
int n, k;
int d [MAXN];

bool isPossible (int days) {
    int camp = 0;
    int curr = 0;
    for (int i = 0; i <= n; i++) {
        if (curr + d [i] <= days) {
            curr += d [i];
        } else {
            curr = d [i];
            camp++;
        }
    }

    return camp <= k;
}

int binarySearch (int lo, int hi) {
    int ans = hi;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (isPossible (mid)) {
            ans = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }
    return ans;
}

void solution (int ans) {
    int tot = d [0], indx = 0;

    for (int i = 1; i <= n; i++) {
        if (k - indx == (n - i + 1)) {
            indx++;
            printf ("%d\n", tot);
            tot = d [i];
        } else if (tot + d [i] > ans) {
            indx++;
            printf ("%d\n", tot);
            tot = d [i];
        } else {
            tot += d [i];
        }
    }
    printf ("%d\n", tot);
}

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d %d", &n, &k);
        int lo = 0, hi = 0;
        for (int i = 0; i <= n; i++) {
            scanf ("%d", &d [i]);
            lo = max (lo, d [i]);
            hi += d [i];
        }

        int res = binarySearch (lo, hi);
        printf ("Case %d: %d\n", kase, res);
        solution (res);
    }

    return 0;
}
