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

ll cache [70][70];
bool check [70][70];
char str [70];

ll dp (int i, int j) {
    if (i == j) return 1;
    if (i > j) return 0;
    ll &ret = cache [i][j];
    if (check [i][j]) return ret;
    check [i][j] = true;

    ret = dp (i + 1, j) + dp (i, j - 1);
    if (str [i] != str [j]) ret -= dp (i + 1, j - 1);
    else ret++;

    return ret;
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>str;
        int len = strlen (str);
        mset (check, false);
        printf ("Case %d: ", kase);
        cout<<dp (0, len - 1)<<endl;
    }

    return 0;
}
