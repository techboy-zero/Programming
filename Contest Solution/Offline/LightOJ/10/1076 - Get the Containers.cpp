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
#define MOD 100000007

using namespace std;

int n, m, a [1010];

int Binary_Search (int lo, int hi) {
    int mn = INF;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int t = 0,k = 1;
        for (int i = 0; i < n; i++) {
            if (t + a [i] <= mid) t += a [i];
            else {
                t = a [i];
                k++;
            }
        }
        if (k <= m) {
            hi = mid - 1;
            mn = min (mn, mid);
        } else lo = mid + 1;
    }

    return mn;
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n>>m;

        int lo = 0, hi = 0;
        for (int i = 0; i < n; i++) {
            cin>>a [i];
            hi += a [i];
            lo = max(lo, a [i]);
        }

        printf("Case %d: %d\n",kase,Binary_Search(lo, hi));
    }

    return 0;
}
