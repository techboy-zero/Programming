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
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        char name [10];
        cin>>n>>name;

        if (!strcmp(name, "Alice")) {
            if (n % 3 == 1) printf("Case %d: Bob\n", kase);
            else            printf("Case %d: Alice\n", kase);
        }else {
            if (n % 3 == 0) printf("Case %d: Alice\n", kase);
            else            printf("Case %d: Bob\n", kase);
        }
    }

    return 0;
}
