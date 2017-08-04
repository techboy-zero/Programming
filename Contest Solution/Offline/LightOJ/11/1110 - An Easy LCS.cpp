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
string cache [110][110];

void LCS (int n, int m) {

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){

            if(!i || !j) cache [i][j] = "";
            else if(str1 [i - 1] == str2 [j - 1]) cache [i][j] = cache[i - 1][j - 1] + str1 [i - 1];
            else if(cache [i - 1][j].size() > cache [i][j - 1].size()) cache[i][j] = cache[i - 1][j];
            else if(cache [i - 1][j].size() < cache [i][j - 1].size()) cache[i][j] = cache[i][j - 1];
            else if(cache [i - 1][j] < cache [i][j - 1]) cache [i][j] = cache[i - 1][j];
            else cache[i][j] = cache[i][j - 1];

        }
    }
    if(!cache [n][m].size()) cout<<":("<< endl ;
    else cout<<cache [n][m]<<endl ;
}

int main(){
    int t;
    scanf("%d",&t);

    for (int kase = 1; kase <= t; kase++) {
        scanf("%s %s",&str1, &str2);

        int len1 = strlen(str1);
        int len2 = strlen(str2);

        printf("Case %d: ",kase);
        LCS(len1, len2);
    }

    return 0;
}
