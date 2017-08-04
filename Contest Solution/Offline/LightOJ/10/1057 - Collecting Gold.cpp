#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

//{{{ ************[  Floating points     ]************
#define ABS(x)          (((x) < 0) ? - (x) : (x))
#define ZERO(x)         (ABS (x) < EPS)
#define EQUAL(x, y)     (ZERO ((x) - (y)))

#define sqr(x)        (x*x)
#define cube(x)        (x*x*x)
#define INF            (int)1e9
#define EPS            1e-9

#define mset(a,v)    memset(a, v, sizeof(a))

using namespace std;

struct points {
    int x, y;
}a [20];

int r, c, hi, starx, starty;
char grid [25][25];

bool visit [17][17][16400];
int cache [17][17][16400];

int cost (int i, int j) {
    return max (abs (a [i].x - a [j].x), abs (a [i].y - a [j].y));
}

int bit_dp (int pos, int curr, int mask) {
    if (pos == hi) return 0;
    int &ret = cache [pos][curr][mask];
    if (visit [pos][curr][mask]) return ret;
    visit [pos][curr][mask] = true;

    ret = INF;
    for (int i = 0; i < hi; i++) {
        if (!(mask & (1 << i))) {
            if (pos == hi - 1)
                ret = min (ret, bit_dp (pos + 1, i + 1, mask | (1 << i)) + cost (curr, i + 1) + cost (i + 1, 0));
            else
                ret = min (ret, bit_dp (pos + 1, i + 1, mask | (1 << i)) + cost (curr, i + 1));
        }
    }

    return ret;
}

int main(){
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            cin >> grid [i];
        hi = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid [i][j] == 'x') {
                    a [0].x = i;
                    a [0].y = j;
                } else if (grid [i][j] == 'g') {
                    a [++hi].x = i;
                    a [hi].y = j;
                }
            }
        }

        mset (visit, false);
        int solve = bit_dp (0, 0, 0);
        printf ("Case %d: %d\n", kase, solve);
    }

    return 0;
}
