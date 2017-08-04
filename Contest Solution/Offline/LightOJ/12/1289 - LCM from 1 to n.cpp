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
#define MAX (int) (1e8 + 7)

using namespace std;

struct precalc {
    int number;
    unsigned int multi;
}a [5800000];

unsigned int status [MAX / 32 + 7];
int in, limit;

inline bool CheckBit (unsigned int n,unsigned int pos) {
    return (bool) ((1 << pos) & n);
}
inline int SetBit (unsigned int n,unsigned int pos) {
    return n = n | (1 << pos);
}

void bitwise_sieve () {
    for (long long j = 2; j <= MAX; j *= 2) {
        a [limit].number = (int) j;
        a [limit++].multi = 2;
    }

    for (long long i = 3; i <= MAX; i += 2) {
        if (!CheckBit(status [(unsigned int) i / 32], (unsigned int) i % 32)) {
            for (long long j = i; j <= MAX; j *= i) {
                a [limit].number = (int) j;
                a [limit++].multi = (unsigned int) i;
            }

            for (long long j = i * i; j <= MAX; j += 2 * i)
                status [(unsigned int) j / 32] = SetBit(status [(unsigned int) j / 32], (unsigned int) j % 32);
        }
    }
}

bool comp (precalc a, precalc b) {
    return a.number < b.number;
}

void pregen () {
    sort (a, a + limit, comp);
    for (int i = 1; i < limit; i++) {
        a [i].multi *= a [i - 1].multi;
    }
}

unsigned int Lower_Bound (int lo, int hi, unsigned int key) {
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (a [mid].number == key) return a [mid].multi;
        else if (key > a [mid].number) lo = mid + 1;
        else hi = mid;
    }

    return a [lo - 1].multi;
}

int main() {
    bitwise_sieve();
    pregen();

    int t;
    scanf("%d",&t);

    for (int kase = 1; kase <= t; kase++) {
        unsigned int n;
        cin>>n;

        unsigned int result = Lower_Bound (0, limit - 1, n);
        printf("Case %d: %u\n", kase, result);
    }

    return 0;
}
