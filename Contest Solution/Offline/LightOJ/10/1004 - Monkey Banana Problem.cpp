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

int mat[300][300],dp_memo[300][300];
bool check[300][300];
int n;

bool is_valid(int i,int j){
    if (i<0 || i>=2*n-1) return false;
    if (j<0 || j>=n)     return false;
    if (i<n && j>i)      return false;
    if (i>=n && j>=(2*n-1-i)) return false;

    return true;
}

int dp_solve(int i,int j){
    if (is_valid(i,j)){
        if (check[i][j]) return dp_memo[i][j];
        int ret=0;

        ret=max(ret,dp_solve(i+1,j)+mat[i][j]);
        if (i<n-1) ret=max(ret,dp_solve(i+1,j+1)+mat[i][j]);
        else       ret=max(ret,dp_solve(i+1,j-1)+mat[i][j]);

        check[i][j]=true;
        return dp_memo[i][j]=ret;
    }
    else return 0;
}

int main(){

    //freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);

    for (int kase=1; kase<=t; kase++){
        scanf("%d",&n);
        for (int i=0; i<n; i++)
            for (int j=0; j<=i; j++)
                scanf("%d",&mat[i][j]);

        for (int i=n; i<2*n-1; i++)
            for (int j=0; j<(2*n-1-i); j++)
                scanf("%d",&mat[i][j]);

        memset(check,false,sizeof(check));
        printf("Case %d: %d\n",kase,dp_solve(0,0));
    }

    return 0;
}
