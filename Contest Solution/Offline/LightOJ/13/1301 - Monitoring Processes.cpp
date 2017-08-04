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

struct interval {
    int value;
    bool mark;
}timelist[100010];

bool comp(interval a,interval b) {
    if (a.value==b.value) return a.mark<b.mark;

    return a.value<b.value;
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    for (int kase=1; kase<=t; kase++) {
        int n,k=0,s,e;
        cin>>n;

        for (int i=1; i<=n; i++) {
            cin>>s>>e;
            timelist[k].value=s;
            timelist[k++].mark=0;
            timelist[k].value=e;
            timelist[k++].mark=1;
        }

        sort(timelist,timelist+k,comp);
        int cnt=0,curr=0;
        for (int i=0; i<k; i++) {
            curr+=(timelist[i].mark)?-1:1;
            cnt=max(cnt,curr);
        }

        printf("Case %d: %d\n",kase,cnt);
    }

    return 0;
}
