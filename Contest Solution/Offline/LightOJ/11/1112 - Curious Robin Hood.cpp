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
typedef long long ll;

ll a [100010];
int n, q;

void add (int i, int v) {
    while (i <= n) {
        a [i] += v;
        i += (i & -i);
    }
}

void sub (int i, int v) {
    while (i <= n) {
        a [i] -= v;
        i += (i & -i);
    }
}

ll sum (int i) {
    ll ans = 0;
    while (i > 0) {
        ans += a [i];
        i -= (i & -i);
    }
    return ans;
}

int main(){
    int t;
    scanf ("%d",&t);

    for (int kase = 1; kase <= t; kase++){
        scanf ("%d %d",&n, &q);
        mset (a, 0);

        for (int i = 1; i <= n; i++) {
            ll num;
            scanf ("%lld",&num);
            add (i, num);
        }

        printf("Case %d:\n",kase);
        for (int i = 1; i <= q; i++) {
            int query;
            scanf ("%d",&query);

            if (query == 1) {
                int indx;
                scanf ("%d",&indx);
                indx++;
                ll value = sum (indx) - sum (indx - 1);
                printf ("%lld\n", value);
                sub (indx, value);
            }else if (query == 2) {
                int indx, value;
                scanf ("%d %d",&indx, &value);
                indx++;
                add (indx, value);
            }else {
                int start, finish;
                scanf ("%d %d", &start, &finish);
                start++; finish++;
                printf ("%lld\n",sum (finish) - sum (start - 1));
            }
        }
    }

    return 0;
}
