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

#define sqr(x) (x*x)
#define cube(x) (x*x*x)
#define INF 999999999
#define MOD 100000007

using namespace std;

char str1[40],str2[40];
bool check[40][40];
int cache[40][40], len1, len2;
long long multi [40][40];

int LCS(int i, int j){
    if (i == len1 || j == len2) return 0;
    if (check [i][j]) return cache [i][j];

    int &ret = cache [i][j];
    if (str1 [i] == str2 [j]) ret = LCS(i + 1, j + 1) + 1;
    else                      ret = max(LCS(i, j + 1), LCS(i + 1, j));

    check [i][j]=true;
    return ret;
}

long long Unique (int i, int j) {
    if (i == len1 && j == len2) return 1;

    if (i == len1) return Unique(i, j + 1);
    else if (j == len2) return Unique(i + 1, j);
    else {
        if (check [i][j]) return multi [i][j];

        long long &ret = multi [i][j];
        ret = 0;
        if (str1 [i] == str2 [j]) ret += Unique (i + 1, j + 1);
        else {
            if (cache [i + 1][j] == cache [i][j]) ret += Unique (i + 1, j);
            if (cache [i][j + 1] == cache [i][j]) ret += Unique (i, j + 1);
        }

        check [i][j] = true;
        return ret;
    }
}

int main(){

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w", stdout);

    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>str1>>str2;
        len1 = strlen(str1), len2 = strlen(str2);

        memset(check,false,sizeof(check));
        memset(cache,0,sizeof(cache));
        int lcs = LCS(0, 0);
        int mx = len1 + len2 - lcs;
        memset(check,false,sizeof(check));
        memset(multi,0,sizeof(multi));
        long long total = Unique(0, 0);

        printf("Case %d: %d %lld\n",kase, mx, total);
    }

    return 0;
}
