#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>

#define m 5000010

using namespace std;

unsigned long long co_prime[m];

void sievephi(void)
{
    long long i,j;

    co_prime[1]=1;

    for (i=2; i<m; i++)
    {
        if (co_prime[i]==0)
        {
            co_prime[i]=i-1;

            for (j=2*i; j<m; j+=i)
            {
                if (co_prime[j]==0)
                    co_prime[j]=j;

                co_prime[j]=co_prime[j]/i*(i-1);
            }
        }
    }
}

void sum_score(void)
{
    co_prime[1]=1;

    for (int i=2; i<m; i++)
        co_prime[i]=co_prime[i-1]+co_prime[i]*co_prime[i];
}

int main()
{
    sievephi();
    sum_score();

    int t,i,a,b;

    scanf("%d",&t);

    for (i=1; i<=t; i++)
    {
        scanf("%d %d",&a,&b);

        unsigned long long sum=co_prime[b]-co_prime[a-1];

        printf("Case %d: %llu\n",i,sum);
    }

    return 0;
}
