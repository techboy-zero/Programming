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
#define EPS 1e-12
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e8, MAXN = 100;
double res [MAX / MAXN + 7];

void preCalc () {
    for (int i = 1; i <= MAX; i++) {
        res [i / MAXN] += 1.0 / i;
    }
    int limit = MAX / MAXN;
    for (int i = 1; i <= limit; i++) {
        res [i] += res [i - 1];
    }
}

int main () {
    preCalc ();
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int n;
        scanf ("%d", &n);

        int div = n / MAXN;
        double tot = 0;
        for (int i = div * MAXN; i <= n; i++) {
            if (i) tot += 1.0 / i;
        }
        div--;
        if (div >= 0) tot += res [div];

        printf ("Case %d: %.10lf\n", kase, tot + EPS);
    }

    return 0;
}
