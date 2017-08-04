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
char str [100010], com [3];

void add (int i, int v) {
    while (i <= n) {
        a [i] += v;
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

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%s",&str);
        n = strlen (str);
        mset (a, 0);

        printf ("Case %d:\n", kase);

        scanf ("%d",&q);
        for (int i = 1;  i <= q; i++) {
            scanf ("%s",&com);
            if (com [0] == 'I') {
                int s, e;
                scanf ("%d %d",&s, &e);
                add (s, 1);
                add (e + 1, -1);
            }else {
                int indx;
                scanf ("%d",&indx);
                ll s = sum (indx);
                if (s % 2 == 0) printf("%c\n",str [indx - 1]);
                else {
                    if (str [indx - 1] == '1') printf("0\n");
                    else                        printf("1\n");
                }
            }
        }
    }
    return 0;
}
