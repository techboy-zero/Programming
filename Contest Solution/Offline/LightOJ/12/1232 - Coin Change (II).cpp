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

int n,k,coins[110];
int dp_memo[10010];

int main(){

    //freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);

    for (int kase=1; kase<=t; kase++){
        scanf("%d %d",&n,&k);
        for (int i=0; i<n; i++)
            scanf("%d",&coins[i]);
        memset(dp_memo,0,sizeof(dp_memo));

        for (int i=0; i<n; i++){
            dp_memo[coins[i]]++;

            for (int j=coins[i]+1; j<=k; j++){
                dp_memo[j]+=dp_memo[j-coins[i]];
                dp_memo[j]%=MOD;
            }
        }

        printf("Case %d: %d\n",kase,dp_memo[k]);
    }

    return 0;
}
