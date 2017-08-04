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
#define MOD 1000000007
#define MAX 70000

using namespace std;

vector <long long> primes;
bool check[ MAX + 7];

void sieve() {
    check[0] = check[1] = true;
    primes.push_back(2);
    for (long long i = 3; i <= MAX; i += 2) {
        if (check[i]) continue;
        primes.push_back(i);
        for (long long j = i * i; j <= MAX; j += 2 * i)
            check[j]=true;
    }
}

unsigned long long Binary_Expo (unsigned long long n,unsigned long long p) {
    if (!p) return 1;
    if (p == 1) return n;

    if (p % 2) return ((Binary_Expo (n,p - 1) % MOD) * n % MOD);
    unsigned long long ret = Binary_Expo(n,p >> 1) % MOD;
    return (ret * ret) % MOD;
}

unsigned long long Series(unsigned long long n,unsigned long long p) {
    unsigned long long temp;
    temp = (Binary_Expo(n, p) - 1); temp %= MOD;
    temp *= n; temp %= MOD;
    temp *= Binary_Expo(n - 1,MOD - 2); temp %= MOD;
    temp++; temp %= MOD;
    return temp;
}

unsigned long long Pseudo (unsigned long long n,unsigned long long m) {
    unsigned long long total = 1;

    for (int i = 0; primes[i] * primes[i] <= n; i++) {
        long long p = 0;
        if (n % primes[i] == 0) {
            while (n % primes[i] == 0) {
                n /= primes[i];
                p++;
            }
            p *= m;
            total *= Series(primes[i], p); total %= MOD;
        }
    }
    if (n > 1) total *= Series(n, m);
    total %= MOD;

    return total;
}

int main() {
    //freopen("input.txt","r",stdin);
    sieve();

    int t;
    unsigned long long n,m;

    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n>>m;
        printf("Case %d: %llu\n",kase,Pseudo(n,m));
    }

    return 0;
}
