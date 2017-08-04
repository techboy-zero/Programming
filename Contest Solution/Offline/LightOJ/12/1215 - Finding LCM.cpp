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

bool status[1000051];
vector <long long> primes;

void sieve(void)
{
    long long i,j;

    primes.push_back(2);

    for (i=3; i<=1000050; i+=2)
    {
        if (status[i])      continue;

        primes.push_back(i);

        for (j=i*i; j<=1000050; j+=(2*i))
            status[j]=1;
    }
}

long long GCD (long long a,long long b)
{
    long long temp;

    while (b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }

    return a;
}

long long LCM (long long a,long long b,long long gcd)
{
    return (a*b)/gcd;
}

vector <long long> divisors;

int main()
{
    sieve();

    long long a,b,L;
    int t;

    cin>>t;

    for (int i=1; i<=t; i++)
    {
        long long result,gcd,lcm;

        cin>>a>>b>>L;

        gcd=GCD(a,b);           lcm=LCM(a,b,gcd);

        divisors.push_back(1);   divisors.push_back(L);

        for (long long j=0; primes[j]*primes[j]<=L; j++)
        {
            if (L%primes[j]==0)
            {
                divisors.push_back(primes[j]);      divisors.push_back(L/primes[j]);

                for (long long k=primes[j]*primes[j]; k*k<=L; k+=primes[j])
                    if (L%k==0)
                    {
                        divisors.push_back(k);      divisors.push_back(L/k);
                    }
            }
        }

        sort( divisors.begin() , divisors.end() );

        int len=divisors.size();
        bool stat=false;

        for (int j=0; j<len; j++)
            if ( LCM(lcm,divisors[j],GCD(lcm,divisors[j]))==L )
            {
                stat=true;
                result=divisors[j];
                break;
            }

        cout<<"Case "<<i<<": ";

        if (stat)   cout<<result<<endl;
        else        cout<<"impossible"<<endl;

        divisors.clear();
    }

    return 0;
}
