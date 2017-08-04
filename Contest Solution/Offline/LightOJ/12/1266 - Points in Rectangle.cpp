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

int a [1010][1010];
bool mark [1010][1010];

void add (int i, int j) {
    while (i <= 1001) {
        int t = j;
        while (t <= 1001) {
            a [i][t]++;
            t += (t & -t);
        }
        i += (i & -i);
    }
}

int sum (int i, int j) {
    int ans = 0;
    while (i > 0) {
        int t = j;
        while (t > 0) {
            ans += a [i][t];
            t -= (t & -t);
        }
        i -= (i & -i);
    }
    return ans;
}

int main(){
    int t;
    scanf ("%d",&t);

    for (int kase = 1; kase <= t; kase++) {
        mset (mark, false);
        mset (a, 0);
        int q;
        scanf ("%d",&q);
        printf ("Case %d:\n",kase);
        for (int i = 1; i <= q; i++) {
            int choice;
            scanf ("%d",&choice);

            if (!choice) {
                int x, y;
                scanf ("%d %d",&x, &y);
                x++; y++;
                if (!mark [x][y]) add (x, y);
                mark [x][y] = true;
            }else {
                int x1, x2, y1, y2;
                scanf ("%d %d %d %d",&x1, &y1, &x2, &y2);
                x1++; y1++; x2++; y2++;

                printf ("%d\n", sum (x2, y2) - sum (x1 - 1, y2) - sum (x2, y1 - 1) + sum (x1 - 1, y1 - 1));
            }
        }
    }
    return 0;
}
