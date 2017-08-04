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

long long cache [12][110][110][2];
int power [] = {1,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9};
bool check [12][110][110][2];
int a, b, k, compar;

long long digit_sum (int pos, int total, int dsum, bool presmall) {
    if (!pos) return (!dsum && !total);

    long long &ret = cache [pos][total][dsum][presmall];

    if (check [pos][total][dsum][presmall]) return ret;
    ret = 0;
    int limit = (compar / power [pos - 1]) % 10;
    if (!presmall) {
        for (int i = 0; i <= limit; i++)
            ret += digit_sum (pos - 1, (total * 10 + i) % k, (dsum + i) % k, (i < limit));
    } else {
        for (int i = 0; i <= 9; i++)
            ret += digit_sum (pos - 1, (total * 10 + i) % k, (dsum + i) % k, true);
    }

    check [pos][total][dsum][presmall] = true;
    return ret;
}

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>a>>b>>k;
        printf("Case %d: ",kase);
        if (k > 100) cout<<0<<endl;
        else {
            int p1 = (a - 1) ? floor(log10(a - 1)) + 1 : 1;
            int p2 = floor(log10(b)) + 1;

            compar = b;
            mset(check,false);
            long long solve = digit_sum(p2, 0, 0, false);

            compar = a - 1;
            mset(check,false);
            solve -= digit_sum(p1, 0, 0, false);
            cout<<solve<<endl;
        }
    }
    return 0;
}
