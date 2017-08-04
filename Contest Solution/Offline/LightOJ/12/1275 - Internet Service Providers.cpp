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

const int MAX = 1e7;

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        ll n, c;
        cin >> n >> c;
        ll val1, val2, tot;
        if (!n) {
            tot = 0;
            val1 = val2 = 0;
        }
        else {
            tot = c / (2 * n);
            val1 = tot * (c - tot * n);
            val2 = (tot + 1) * (c - (tot + 1) * n);
        }

        printf ("Case %d: %d\n", kase, val1 >= val2 ? tot : tot + 1);
    }

    return 0;
}
