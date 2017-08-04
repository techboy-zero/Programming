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

int main(){
    int t;
    int n, m;

    scanf("%d",&t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%d %d",&n, &m);
        printf("Case %d: ", kase);

        if (n == 1) printf("%d\n", m);
        else if (m == 1) printf("%d\n", n);
        else if (n == 2) {
            int cnt = (m / 4) * 4;

            if (m % 4 == 1) cnt += 2;
            else if (m % 4 > 1) cnt += 4;

            printf("%d\n", cnt);
        } else if (m == 2) {
            int cnt = (n / 4) * 4;

            if (n % 4 == 1) cnt += 2;
            else if (n % 4 > 1) cnt += 4;

            printf("%d\n", cnt);
        } else
            printf("%d\n", ((m * n) + 1) / 2);
    }

    return 0;
}
