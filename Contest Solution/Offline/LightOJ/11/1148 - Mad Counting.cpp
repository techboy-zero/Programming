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

int a [60];

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin>>n;

        for (int i = 0; i < n; i++)
            cin>>a [i];
        sort(a, a + n);

        long long total = 0, cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!cnt) {
                cnt = a [i];
                total += (cnt + 1);
            }else cnt--;
        }

        printf("Case %d: %lld\n", kase, total);
    }

    return 0;
}
