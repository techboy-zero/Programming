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

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);

    for (int kase = 1; kase <= t; kase++) {
        int n, q, p1, p2;
        scanf("%d %d",&n, &q);
        vector <int> v;

        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d",&num);
            v.push_back(num);
        }
        printf("Case %d:\n",kase);
        for (int i = 0; i < q; i++) {
            int r1, r2;
            scanf("%d %d",&r1, &r2);
            p1 = lower_bound(v.begin(), v.end(), r1) - v.begin();
            p2 = lower_bound(v.begin(), v.end(), r2) - v.begin();

            if (p2 < n && v [p2] == r2) p2++;

            printf("%d\n",p2 - p1);
        }
        v.clear();
    }

    return 0;
}
