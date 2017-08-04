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

#define sqr(x) (x*x)
#define cube(x) (x*x*x)

using namespace std;

unsigned long long memo[31][31];

inline unsigned long long nCr(unsigned long long n,unsigned long long r)
{
    if (memo[n][r]!=-1)
        return memo[n][r];

    if(n==r) return 1;
    if(r==1) return n;

    return memo[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
}

int main()
{
    unsigned long long t,i,j,n,k,total,multi;

    scanf("%llu",&t);

    memset(memo,-1,sizeof(memo));

    for (i=1; i<=t; i++)
    {
        scanf("%llu %llu",&n,&k);

        total=1;

        if (k==0)       total=1;
        else if (k>n)   total=0;
        else if (k==1)  total=(n*n);
        else
        {
            for (j=0; j<k; j++)
                total*=(n-j);

            multi=nCr(n,k);

            total*=multi;
        }


        printf("Case %llu: %llu\n",i,total);
    }

    return 0;
}
