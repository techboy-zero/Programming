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

using namespace std;
typedef long long ll;

template <class A, class B> inline B mod (A a, B m) { return (a %= m) >= 0 ? a : (a + m); }
template <class A> inline A modInv (long long x, A m) { return x < 2 ? x :  mod ((1 - 1LL * m * modInv (m % x, x)) / x, m); }

long long fact[1000001];

void fact_gen(void)
{
    fact[0]=1;

    for (int i=1; i<=1000000; i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=1000003;
    }
}

long long big_mod(long long n,long long p)
{
    if (p==0)   return 1;
    if (p==1)   return n;

    if (p%2)    return ((n%1000003)*big_mod(n,p-1))%1000003;
    else        return sqr(big_mod(n,p/2))%1000003;
}

ll inv(ll a, ll m) {
 return a < 2 ? a : ((1 - m * 1ll * inv(m % a, a)) / a % m + m) % m;
}

int main()
{
    fact_gen();

    int t;

    cin>>t;

    for (int i=1; i<=t; i++)
    {
        int n,r,nr;

        cin>>n>>r;

        nr=n-r;

        long long res=1;

        res *= fact[n];
        res *= inv (fact [r], 1000003); res %= 1000003;
        res *= inv (fact [nr], 1000003); res %= 1000003;
        //res*=big_mod(fact[r],1000001);      res%=1000003;
        //res*=big_mod(fact[nr],1000001);     res%=1000003;

        cout<<"Case "<<i<<": "<<res<<endl;
    }

    return 0;
}
