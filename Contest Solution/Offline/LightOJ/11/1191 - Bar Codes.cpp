/* C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/* C++ STL */
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>

/* Macros */
#define EPS 1e-9
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 50;

ll cache [MAX + 7][MAX + 7][MAX + 7];
bool visit [MAX + 7][MAX + 7][MAX + 7];

ll dp (int n, int k, int m) {
    if (n < 0) return 0;
    if (!n) return (k == 0);
    ll &ret = cache [n][k][m];
    if (visit [n][k][m]) return ret;
    visit [n][k][m] = true;

    ret = 0;
    for (int i = 1; i <= m; i++) {
        ret += dp (n - i, k - 1, m);
    }
    return ret;
}

void preCalc () {
    for (int i = 1; i <= MAX; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= i; k++) {
                cache [i][j][k] = dp (i, j, k);
            }
        }
    }
}

int main () {
    preCalc ();
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int n, k, m;
        scanf ("%d %d %d", &n, &k, &m);
        printf ("Case %d: %lld\n", kase, cache [n][k][m]);
    }
    return 0;
}
