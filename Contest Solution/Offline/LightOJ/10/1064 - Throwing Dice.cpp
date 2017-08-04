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
typedef unsigned long long ull;

bool visit [30][160];
ull cache [30][160];
int n, x;

ull dp (int pos, int total) {
    if (pos == n) return (total >= x);
    ull &ret = cache [pos][total];
    if (visit [pos][total]) return ret;
    visit [pos][total] = true;

    ret = 0;
    for (int i = 1; i <= 6; i++) ret += dp (pos + 1, total + i);

    return ret;
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        mset (visit, false);
        cin>>n>>x;
        ull solve = dp (0, 0);
        ull divi = 1;
        for (int i = 1; i <= n; i++) {
            divi *= 6;
            ull g = __gcd (solve, divi);
            solve /= g; divi /= g;
        }
        printf ("Case %d: ", kase);
        if (divi == 1) cout<<solve<<endl;
        else          cout<<solve<<"/"<<divi<<endl;
    }
    return 0;
}
