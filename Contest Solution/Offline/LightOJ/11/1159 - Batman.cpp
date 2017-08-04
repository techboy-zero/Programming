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

char str1 [60], str2 [60], str3 [60];
int len1, len2, len3;
bool visit [60][60][60];
int cache [60][60][60];

int lcs (int i, int j, int k) {
    if (i == len1 || j == len2 || k == len3) return 0;
    int &ret = cache [i][j][k];
    if (visit [i][j][k]) return ret;
    visit [i][j][k] = true;

    ret = 0;
    if (str1 [i] == str2 [j] && str2 [j] == str3[k]) ret = lcs (i + 1, j + 1, k + 1) + 1;
    else {
        ret = lcs (i + 1, j, k);
        ret = max (ret, lcs (i, j + 1, k));
        ret = max (ret, lcs (i, j, k + 1));
    }

    return ret;
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>str1>>str2>>str3;

        len1 = strlen(str1);
        len2 = strlen(str2);
        len3 = strlen(str3);

        mset(visit, false);
        int l = lcs (0, 0, 0);

        printf("Case %d: %d\n",kase, l);
    }

    return 0;
}
