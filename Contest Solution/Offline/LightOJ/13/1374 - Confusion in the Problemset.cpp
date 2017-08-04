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

int  a[1000010];

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        memset(a, 0, sizeof(a));

        cin>>n;
        for (int i = 0; i < n; i++) {
            int num;
            cin>>num;
            a [num]++;
        }

        bool state = true;
        for (int i = 0; i < n; i++) {
            if (a [i]) a [i]--;
            else if (a [n - 1 - i]) a [n - 1 - i]--;
            else state = false;
        }

        printf("Case %d: %s\n", kase, state? "yes" : "no");
    }

    return 0;
}
