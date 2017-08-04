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

int n;
long long k;
long long a [20];

vector <long long> series1, series2;

void backtrack1 (int pos, long long total) {
    if (pos == (n >> 1)) {
        series1.push_back(total);
        return;
    }

    for (int i = 0; i < 3; i++)
        if (total + i * a [pos] <= k)
            backtrack1 (pos + 1, total + i * a [pos]);
}

void backtrack2 (int pos, long long total) {
    if (pos == n) {
        series2.push_back(total);
        return;
    }

    for (int i = 0; i < 3; i++)
        if (total + i * a [pos] <= k)
            backtrack2 (pos + 1, total + i * a [pos]);
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n>>k;
        for (int i = 0; i < n; i++)
            cin>>a [i];

        backtrack1 (0, 0);
        backtrack2 (n / 2, 0);

        sort(series1.begin(), series1.end());
        sort(series2.begin(), series2.end());

        int sz = series1.size();
        bool found = false;

        for (int i = 0; i < sz; i++) {
            long long lft = k - series1 [i];
            if (binary_search (series2.begin(), series2.end(), lft)) {
                found = true;
                break;
            }
        }

        if (found) printf("Case %d: Yes\n",kase);
        else       printf("Case %d: No\n",kase);
        series1.clear();
        series2.clear();
    }

    return 0;
}
