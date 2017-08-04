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

int josephus (int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + k) % i;
    }
    return res + 1;
}

int main(){

    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        int n, k;
        cin>>n>>k;
        printf ("Case %d: %d\n", kase, josephus (n, k));
    }

    return 0;
}
