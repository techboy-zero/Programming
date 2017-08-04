#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;

int n, m, k;
int ar [MAX], pos [1010];
int nextpos [MAX];
bool mark [110];

void Init () {
    ar [0] = 1;
    ar [1] = 2;
    ar [2] = 3;
}

int solve2 () {
    int cnt = 0;
    int low = 0;
    int high = -1;
    memset (mark, false, sizeof mark);

    for (int i = 0; i < n; i++ ) {
        if (ar [i] >=1 && ar [i] <= k && !mark [ar [i]] ) {
            mark [ar [i]] = true;
            cnt++;
        }
        if (cnt == k) {
            high = i;
            break;
        }
    }

    if (high == -1) return -1;
    int ans = (high - low + 1);

    while (low < high) {
        if (ar [low] > k)
            low++;
        else if (nextpos [low] == -1) break;
        else if (nextpos [low] <= high)
            low++;
        else {
            high = nextpos [low];
            low++;
        }
        ans = min (ans, high - low + 1);
    }

    return ans;
}

int main () {
    Init ();
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d %d %d", &n, &m, &k);
        memset (pos, -1, sizeof (pos));

        for ( int i = 3; i < n; i++ ) {
            ar [i] = (ar [i - 1] + ar [i - 2] + ar [i - 3]) % m + 1;
        }

        for ( int i = n - 1; i >= 0; i-- ) {
            nextpos [i] = pos [ar [i]];
            pos [ar [i]] = i;
        }

        int ans = solve2 ();
        printf ("Case %d: ", kase);
        if (ans == -1) printf ("sequence nai\n");
        else printf ("%d\n", ans);
    }
    return 0;
}
