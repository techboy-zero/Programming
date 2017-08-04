/* C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/* C++ STL */
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>

/*STL Iterator*/
#define FOREACH(i,s) for (__typeof ((s).end()) i = (s).begin (); i != (s).end (); i++)

/* Macros */
#define EPS 1e-9
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5, MOD = 1e9 + 7;

map <ll, int> seq;
int n, in;
ll arr [MAX + 7], tree [MAX + 7];

void build () {
    for (int i = 1; i <= in; i++) {
        tree [i] = 0;
    }
}

ll query (int i) {
    ll res = 0;
    while (i > 0) {
        res += tree [i];
        if (res >= MOD) res %= MOD;
        i -= (i & -i);
    }
    return res;
}

void add (int i, ll v) {
    while (i <= in) {
        tree [i] += v;
        if (tree [i] >= MOD) tree [i] %= MOD;
        i += (i & -i);
    }
}

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf ("%lld", &arr [i]);
            seq [arr [i]];
        }
        in = 0;
        FOREACH (curr, seq) {
            curr -> second = ++in;
        }
        build ();
        for (int i = 1; i <= n; i++) {
            ll sum = query (seq [arr [i]] - 1);
            add (seq [arr [i]], sum + 1);
        }

        printf ("Case %d: %lld\n", kase, query (in));
        seq.clear ();
    }

    return 0;
}
