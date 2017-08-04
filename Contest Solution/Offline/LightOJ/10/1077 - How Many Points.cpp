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

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        ll x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        ll x = abs (x1 - x2);
        ll y = abs (y1 - y2);

        printf ("Case %d: ",kase);

        if (!x) cout<<(y + 1)<<endl;
        else if (!y) cout<<(x + 1)<<endl;
        else {
            ll g = __gcd (x, y);
            x /= g; y /= g;
            cout<< (abs (x1 - x2) / x + 1) <<endl;
        }
    }

    return 0;
}
