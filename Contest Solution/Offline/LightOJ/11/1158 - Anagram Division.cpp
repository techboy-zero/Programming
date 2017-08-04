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

const int MAXN = 10, MAX = 1 << 10, MAXD = 1e3;

int cache [MAXD + 2][MAX + 2];
bool visit [MAXD + 2][MAX + 2];
int n, d;
char str [MAXN + 2];

int dp (int rem, int mask) {
    if (mask == (1 << n) - 1) return (rem == 0);
    int &ret = cache [rem][mask];
    if (visit [rem][mask]) return cache [rem][mask];
    visit [rem][mask] = true;

    ret = 0;
    bool mark [10] = {false};
    for (int i = 0; i < n; i++) {
        int val = str [i] - '0';
        if (mark [val] || ((1 << i) & mask)) continue;
        mark [val] = true;
        ret += dp (((rem * 10) + val) % d, mask | (1 << i));
    }
    return ret;
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> str >> d;
        n = strlen (str);
        memset (visit, false, sizeof (visit));
        printf ("Case %d: %d\n", kase, dp (0, 0));
    }
    return 0;
}
