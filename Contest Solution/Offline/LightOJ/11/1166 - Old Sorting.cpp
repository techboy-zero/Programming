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
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        int n, a [110];
        cin>>n;

        for (int i = 0; i < n; i++)
            cin>>a [i];

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            while ( (i + 1) != a [i]) {
                int p = a [i];
                swap(a [i], a [p - 1]);
                cnt++;
            }
        }

        printf("Case %d: %d\n",kase,cnt);
    }

    return 0;
}
