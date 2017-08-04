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

const int MAX = 5e4;

struct people {
    int x, y, p;
} ar [MAX + 7];

int totx [MAX + 7], toty [MAX + 7];

int main () {
    int t;
    scanf ("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        memset (totx, 0, sizeof (totx));
        memset (toty, 0, sizeof (toty));

        int m, n, q;
        scanf ("%d %d %d", &m, &n, &q);

        int tot = 0, avgx, avgy;
        for (int i = 1; i <= q; i++) {
            scanf ("%d %d %d", &ar [i].x, &ar [i].y, &ar [i].p);
            totx [ar [i].x] += ar [i].p;
            toty [ar [i].y] += ar [i].p;
            tot += ar [i].p;
        }

        tot = ++tot / 2;
        int sum = 0;
        for (avgx = 1; avgx <= m; avgx++) {
            sum += totx [avgx];
            if (sum >= tot) break;
        }
        sum = 0;
        for (avgy = 1; avgy <= n; avgy++) {
            sum += toty [avgy];
            if (sum >= tot) break;
        }

        printf ("Case %d: %d %d\n", kase, avgx, avgy);
    }
    return 0;
}
