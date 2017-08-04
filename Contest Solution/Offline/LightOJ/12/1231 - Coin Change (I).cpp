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

int coins[50],limit[50];
long long dp_memo[1010][50];
bool dp_check[1010][50];

long long dp_solve(int i,int total,int n){
    if (!total) return 1;
    if (i>n) return (total==0);
    if (dp_check[total][i]) return dp_memo[total][i];

    int ret1=0,ret2=0;

    for (int j=1; j<=limit[i]; j++){
        if (total-j*coins[i]>=0)
            ret2+=dp_solve(i+1,total-j*coins[i],n)%MOD;
        else break;
    }
    ret1=dp_solve(i+1,total,n)%MOD;

    dp_check[total][i]=true;

    return dp_memo[total][i]=(ret1+ret2)%MOD;
}

int main(){
    //freopen("input.txt","r",stdin);

    int t;
    cin>>t;

    for (int i=1; i<=t; i++){
        int n,amount;
        cin>>n>>amount;

        for (int j=1; j<=n; j++)
            cin>>coins[j];
        for (int j=1; j<=n; j++)
            cin>>limit[j];

        memset(dp_check,false,sizeof(dp_check));
        long long total=dp_solve(1,amount,n);

        printf("Case %d: %lld\n",i,total);
    }

    return 0;
}
