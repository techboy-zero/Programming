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

int n, life [20];
char damage [20][20];

int cache [20][40000];
bool visit [20][40000];

int bit_dp (int pos,int curr) {
    if (pos == n) return 0;
    int &ret = cache [pos][curr];
    if (visit [pos][curr]) return ret;
    visit [pos][curr] = true;

    char d [n + 1];
    for (int i = 0; i < n; i++) d [i] = '1';
    for (int i = 0; i < n; i++)
        if ( (1 << i) & curr) {
            for (int j = 0; j < n; j++)
                d [j] = max (d [j], damage [i][j]);
        }

    ret = INF;
    for (int i = 0; i < n; i++)
        if (!((1 << i) & curr)) {
            int tempd = d [i] - '0';
            int shot = (life [i] / tempd) + ((life [i] % tempd) == 0? 0 : 1);
            ret = min (ret, bit_dp(pos + 1, curr | (1 << i) ) + shot);
        }
    return ret;
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n;
        mset (visit, false);
        for (int i = 0; i < n; i++)
            cin>>life [i];
        for (int i = 0; i < n; i++)
            cin>>damage [i];

        int solve = bit_dp (0, 0);
        printf("Case %d: %d\n", kase, solve);
    }

    return 0;
}
