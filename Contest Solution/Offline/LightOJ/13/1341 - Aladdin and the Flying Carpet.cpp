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
typedef long long ll;

const int MAX = (int) 1e6 + 20;

struct divisor {
    ll p, cnt;
}arr [80010];

vector <ll> primes;
bool check [MAX + 7];
bool visit [MAX];
int in;
ll a, b;

void sieve () {

    check [0] = check [1] = true;
    primes.push_back (2);

    for (ll i = 3; i <= MAX; i += 2) {
        if (check [i]) continue;
        primes.push_back (i);
        for (long long j = i * i; j <= MAX; j += 2 * i)
            check [j] = true;
    }
}

int counter (int pos, ll total) {
    if (pos < 0) return 1;

    int ret = 0, cnt = 0;
    for (ll i = 1; cnt <= arr [pos].cnt && i * total < b; i *= arr [pos].p, cnt++)
        ret += counter (pos - 1, i * total);
    return ret;
}

int main(){
    sieve ();
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>a>>b;

        if (b * b >= a) {
            printf ("Case %d: 0\n", kase);
            continue;
        }

        int cnt = 1;
        in = 0;

        for (int i = 0; primes [i] * primes [i] <= a; i++) {
            int p = 0;
            while (a % primes [i] == 0) {
                a /= primes [i];
                p++;
            }
            if (p) {
                arr [in].p = primes [i];
                arr [in++].cnt = p;
                cnt *= (p + 1);
            }
        }

        if (a > 1) {
            arr [in].p = a;
            arr [in++].cnt = 1;
            cnt *= 2;
        }

        cnt /= 2;
        cnt -= counter (in - 1, 1);
        printf ("Case %d: %d\n", kase, cnt);
    }

    return 0;
}
