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

#define NONE 0
#define RED 1
#define GREEN 2
#define BLUE 3
#define min(a,b) (a<b)?a:b

using namespace std;

int t,n;
int costs[21][4];
int memo[21][4],total;
bool check[21][4];

int dp_solve(int house,int color)
{
    if (house>=n) return costs[house][color];

    if (check[house][color]) return memo[house][color];

    int ret=999999999;

    if (color!=RED)   ret=min(ret,dp_solve(house+1,RED));
    if (color!=GREEN) ret=min(ret,dp_solve(house+1,GREEN));
    if (color!=BLUE)  ret=min(ret,dp_solve(house+1,BLUE));

    check[house][color]=true;

    return memo[house][color]=costs[house][color]+ret;
}

int main()
{
    cin>>t;

    for (int i=1; i<=t; i++)
    {
        cin>>n;
        memset(check,false,sizeof(check));

        for (int j=1; j<=n; j++)
            cin>>costs[j][RED]>>costs[j][GREEN]>>costs[j][BLUE];

        total=dp_solve(0,0);

        cout<<"Case "<<i<<": "<<total<<endl;
    }

    return 0;
}
