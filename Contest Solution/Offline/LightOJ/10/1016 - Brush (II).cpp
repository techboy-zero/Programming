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
#define EPS             DBL_EPSILON
#define ABS(x)          (((x) < 0) ? - (x) : (x))
#define ZERO(x)         (ABS (x) < EPS)
#define EQUAL(x, y)     (ZERO ((x) - (y)))

#define sqr(x) (x*x)
#define cube(x) (x*x*x)
#define INF 999999999
#define MOD 100000007

using namespace std;

struct points {
    int x, y;
}a [50010];

bool comp (points a, points b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

int main(){
    int t;
    scanf("%d",&t);

    for (int kase = 1; kase <= t; kase++) {
        int n, w, cnt = 1;
        scanf("%d %d",&n, &w);

        for (int i = 0; i < n; i++)
            scanf("%d %d",&a [i].x, &a [i].y);
        sort(a, a + n, comp);

        int prev = a [0].y;
        for (int i = 0; i < n; i++) {
            if (a [i].y - prev > w) {
                cnt++;
                prev = a [i].y;
            }
        }

        printf("Case %d: %d\n",kase,cnt);
    }

    return 0;
}
