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

//{{{ ************[  Floating points     ]************
#define ABS(x)          (((x) < 0) ? - (x) : (x))
#define ZERO(x)         (ABS (x) < EPS)
#define EQUAL(x, y)     (ZERO ((x) - (y)))

#define sqr(x)        (x*x)
#define cube(x)        (x*x*x)
#define INF            (int)1e9
#define EPS            1e-9

#define mset(a,v)    memset(a, v, sizeof(a))

using namespace std;

long long MOD = (long long) (1e9 + 7);
long long ncr [1010][1010], fact [1010];
bool check [1010][1010];

long long nCr (long long n, long long r) {
    if (n == r) return 1;
    if (r == 1) return n % MOD;

    long long &ret = ncr [n][r];
    if (check [n][r]) return ncr [n][r];
    check [n][r] = true;

    return ret = (nCr (n - 1, r - 1) % MOD + nCr (n - 1, r) % MOD) % MOD;
}

void pregen () {
    for (long long i = 1; i <= 1000; i++) {
        for (long long j = 1; j <= i; j++)
            ncr [i][j] = nCr(i, j);
    }
    fact [0] = 1;
    for (long long i = 1; i <= 1000; i++)
        fact [i] = (fact [i - 1] * i) % MOD;
}

int main(){
    pregen();

    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        long long n, m, k;
        cin>>n>>m>>k;
        long long part1 = ncr [m][k];
        long long part2 = fact [n - k];

        bool mins = true;

        for (long long i = 1; i <= m - k; i++) {
            long long temp = fact [n - k - i];
            temp *= ncr [m - k][i];
            temp %= MOD;
            if (mins) part2 -= temp;
            else      part2 += temp;
            part2 = (part2 + MOD) % MOD;
            mins = !mins;
        }

        printf("Case %d: %lld\n", kase, (part1 * part2) % MOD);
    }
    return 0;
}
