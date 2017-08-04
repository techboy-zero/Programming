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

int main(){
    int t;
    scanf("%d",&t);

    for (int kase = 1; kase <= t; kase++) {
        int n, a [100010],mx;
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
            scanf("%d",&a [i]);
        mx = a [0];
        for (int i = 1; i < n; i++)
            if (mx < a [i] - a [i - 1])
                mx = a [i] - a [i - 1];
        int temp = mx;
        bool stat = true;
        for (int i = 1; i < n; i++)
            if (temp == a [i] - a [i - 1])
                temp--;
            else if (temp < a [i] - a [i - 1]) {
                stat = false;
                break;
            }
        mx += !stat;
        printf("Case %d: %d\n",kase,mx);
    }

    return 0;
}
