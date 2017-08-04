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

int n, w, hf, a1 [20], a2 [20];
vector <int> v1, v2;

void Sum1 (int i,long long total) {
    if (i == -1) {
        v1.push_back(total);
        return;
    }

    if (total + a1 [i] <= w) Sum1(i - 1, total + a1 [i]);
    Sum1(i - 1, total);
}

void Sum2 (int i,long long total) {
    if (i == -1) {
        v2.push_back(total);
        return;
    }

    if (total + a2 [i] <= w) Sum2(i - 1, total + a2 [i]);
    Sum2(i - 1, total);
}

int main() {
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n>>w;
        hf = n / 2;

        for (int i = 0; i < hf; i++)
            cin>>a1 [i];
        for (int i = 0; i < n - hf; i++)
            cin>>a2 [i];

        Sum1(hf - 1, 0); Sum2(n - hf - 1, 0);
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        int sz = v1.size();
        long long cnt = 0;
        for (int i = 0; i < sz; i++) {
            int lft = w - v1[i];
            int p = upper_bound(v2.begin(), v2.end(), lft) - v2.begin();
            cnt += p;
        }

        printf("Case %d: %lld\n", kase, cnt);
        v1.clear(); v2.clear();
    }

    return 0;
}
