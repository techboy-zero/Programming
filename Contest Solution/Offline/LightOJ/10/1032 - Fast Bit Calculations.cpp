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

int target;
long long cache [40][40][2][2];
bool check [40][40][2][2];

int position (int n) {
    int cnt = 0;
    while (n) {
        n /= 2;
        cnt++;
    }
    return cnt;
}

long long adjacent_bit (int pos, int ad,bool lastbit,bool presmall) {
    if (pos == -1) return ad;

    long long &ret = cache [pos][ad][lastbit][presmall];
    if (check [pos][ad][lastbit][presmall]) return ret;
    check [pos][ad][lastbit][presmall] = true;

    int limit = presmall ? 1 : (bool) ((1<<pos) & target);
    ret = adjacent_bit(pos - 1, ad, 0, (presmall || limit));
    if (limit) ret += adjacent_bit(pos - 1, ad + lastbit, 1, presmall);

    //cout<<pos<<" "<<ad<<" "<<lastbit<<" "<<presmall<<" "<<ret<<endl;

    return ret;
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>target;
        int pos = position(target);
        mset(check,false);
        printf("Case %d: %lld\n", kase, adjacent_bit(pos - 1, 0, 0, 0));
    }
    return 0;
}
