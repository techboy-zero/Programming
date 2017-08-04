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
#define INF 9999999999999
#define MOD 100000007

using namespace std;

long long a [2010], n;

long long Upper_Bound (int lo, int hi, int key) {
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (a [mid] == key || key < a [mid]) hi = mid - 1;
        else {
            if (key > a [mid + 1]) lo = mid + 1;
            else if (key <= a [mid + 1]) return mid;
        }
    }
    return n;
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n;

        for (int i = 0; i < n; i++)
            cin>>a [i];
        a [n] = INF;
        sort(a, a + n);

        long long cnt = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                long long key = a [i] + a[j];
                long long p = Upper_Bound(j, n - 1, key);
                cnt += (p - j);
            }
        }
        printf("Case %d: %lld\n",kase, cnt);
    }
    return 0;
}
