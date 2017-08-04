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

struct karate {
    int x, y, p;
}a [2510];

int own [60], opp [60];

bool comp (int a,int b) { return a > b; }
bool comp1 (karate a, karate b) {
    if (a.p == b.p) {
        if (a.y == b.y) return a.x > b.x;
        return a.y < b.y;
    }

    return a.p > b.p;
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        int n, in = 0;
        cin>>n;

        for (int i = 0; i < n; i++) cin>>own [i];
        for (int i = 0; i < n; i++) cin>>opp [i];

        sort(own, own + n, comp);
        sort(opp, opp + n, comp);

        for (int i = 0;  i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (own [i] >= opp [j]) {
                    a [in].x = i;
                    a [in].y = j;
                    a [in++].p = own [i] > opp [j]? 2 : 1;
                }
            }
        }

        sort(a, a + in, comp1);

        int p = 0;
        bool chk1 [60], chk2 [60];
        memset(chk1, false, sizeof(chk1));
        memset(chk2, false, sizeof(chk2));

        for (int i = 0; i < in; i++) {
            int u = a [i].x, v = a [i].y, value = a [i].p;
            if (!chk1 [u] && !chk2 [v]) {
                chk1 [u] = chk2 [v] = true;
                p += value;
            }
        }

        printf("Case %d: %d\n", kase, p);
    }

    return 0;
}
