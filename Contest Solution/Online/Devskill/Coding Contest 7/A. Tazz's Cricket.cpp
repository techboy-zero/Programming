#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int n;
        scanf ("%d", &n);
        int tot = 0;
        while (n) {
            int num;
            scanf ("%d", &num);
            tot += num;
            if (!num) n--;
        }
        printf ("Case %d: %d\n", kase, tot);
    }
    return 0;
}
