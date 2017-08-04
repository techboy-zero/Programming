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

bool status[10000001];
vector <long long> primes;

void sieve(void)
{
    long long i,j;

    primes.push_back(2);

    for (i=4; i<=10000000; i+=2)
        status[i]=1;

    for (i=3; i<=10000000; i+=2)
    {
        if (status[i]==1)
            continue;

        primes.push_back(i);

        for (j=i*i; j<=10000000; j+=2*i)
            status[j]=1;
    }
}

int main()
{
    sieve();

    int t;

    cin>>t;

    for (int i=1; i<=t; i++)
    {
        long long n,cnt=0;

        cin>>n;

        for (int j=0; primes[j]<=(n/2); j++)
            if (!status[n-primes[j]])
                cnt++;

        cout<<"Case "<<i<<": "<<cnt<<endl;
    }

    return 0;
}
