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

int base, divi, num [22], len, cost [22];
long long cache [22][70000];
bool check [22][70000];
char str [22];

long long bitmask_dp (int mask, int total) {
    int curr = __builtin_popcount(mask);
    if (curr == len) return total? 0 : 1;
    if (check [total][mask]) return cache [total][mask];

    long long &ret = cache [total][mask];
    ret = 0;

    for (int i = 0; i < len; i++) {
        if (!(mask & (1<<i)))
            ret += bitmask_dp(mask | (1<<i), (total + (cost [curr] * num [i]) ) % divi);
    }

    check [total][mask] = true;
    return ret;
}

void value_gen () {
    cost [0] = 1;
    for (int i = 1; i < len; i++) {
        cost [i] = cost [i - 1] * base;
        cost [i] %= divi;
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>base>>divi;
        cin>>str;
        len = strlen(str);
        for (int i = 0; i < len; i++) {
            num [i] = (str [i] > '9')? str [i] - 55: str [i] - '0';
            num [i] %= divi;
        }
        value_gen();
        mset(check, false);
        long long total = bitmask_dp(0, 0);

        printf("Case %d: %lld\n",kase, total);
    }
    return 0;
}
