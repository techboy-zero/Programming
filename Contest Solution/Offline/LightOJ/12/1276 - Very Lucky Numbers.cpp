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
#define FOREACH(i,s) for(__typeof((s).end()) i = (s).begin(); i != (s).end(); i++)

#define sqr(x)        (x*x)
#define cube(x)        (x*x*x)
#define INF            (int)1e9
#define EPS            1e-9

#define mset(a,v)    memset(a, v, sizeof(a))

using namespace std;
typedef long long ll;
const ll MAX = (ll) 1e12;

ll lucky [8200], vlucky [346380];
map <ll, bool> visit;
int sz, in1, in2;

void luckyGen (ll n) {
    if (n > MAX) return;
    if (n) lucky [in1++] = n;

    luckyGen (n * 10 + 4);
    luckyGen (n * 10 + 7);
}

void veryLuckyGen (int i, ll n) {
    if (visit.find (n) == visit.end ()) vlucky [in2++] = n;
    visit [n] = true;

    if (i == in1) return;
    ll curr = n;
    ll div = MAX / curr;
    if (div < lucky [i]) return;

    veryLuckyGen (i + 1, n);
    while (div >= lucky [i]) {
        curr *= lucky [i];
        veryLuckyGen (i + 1, curr);
        div = MAX / curr;
    }
}

void pregen () {
    visit [0] = visit [1] = true;
    luckyGen (0);
    sort (lucky, lucky + in1);
    veryLuckyGen (0, 1);
    sort (vlucky, vlucky + in2);
}

int main () {
    pregen ();
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        ll l, r;
        cin >> l >> r;
        int res = (upper_bound (vlucky, vlucky + in2, r) - lower_bound (vlucky, vlucky + in2, l));
        printf ("Case %d: %d\n", kase, res);
    }
    return 0;
}
