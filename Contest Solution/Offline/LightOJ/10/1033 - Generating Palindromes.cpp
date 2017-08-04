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

char str1 [110],str2 [110];
int cache [110][110], len;
bool check [110][110];

int LCS (int i, int j) {
    if (i == -1 || j == -1) return 0;
    if (check [i][j]) return cache [i][j];

    int &ret = cache [i][j];
    ret = 0;
    if (str1 [i] == str2 [j]) ret = LCS (i - 1, j - 1) + 1;
    else ret = max (LCS (i - 1, j) , LCS (i, j - 1));

    check [i][j] = true;
    return ret;
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>str1;
        len = strlen(str1);

        strcpy(str2, str1);
        reverse(str2, str2 + len);
        mset(check,false);
        printf("Case %d: %d\n", kase, len - LCS (len - 1, len - 1));
    }

    return 0;
}
