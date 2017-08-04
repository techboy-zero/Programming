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

int n,k,t,camps[1010],solution[1010];

bool check_validity(int key) {
    int cumulative_sum=0,part=0;

    for (int i=0; i<=n; i++) {
        cumulative_sum+=camps[i];

        if (cumulative_sum>key) {
            part++;
            cumulative_sum=camps[i];
        }
    }

    return part<=k;
}

void solution_generate(int ans) {
    int total=camps[0],in=0;

    for (int i=1; i<=n; i++)
        if (k-in==(n-i+1)) {
            solution[in++]=total;
            total=camps[i];
        }
        else if (total+camps[i]>ans) {
            solution[in++]=total;
            total=camps[i];
        }
        else
            total+=camps[i];

    solution[in]=total;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);

    for (int kase=1; kase<=t; kase++) {
        scanf("%d %d",&n,&k);


        int lo=-1,hi=0;

        for (int i=0; i<=n; i++) {
            scanf("%d",&camps[i]);
            if (camps[i]>lo) lo=camps[i];
            hi+=camps[i];
        }

        int possible_ans=hi;
        while(lo<=hi) {
            int mid=(lo+hi)/2;

            if (check_validity(mid)) {
                possible_ans=mid;
                hi=mid-1;
            } else lo=mid+1;
        }

        printf("Case %d: %d\n",kase,possible_ans);

        solution_generate(possible_ans);

        for (int i=0; i<=k; i++)
            printf("%d\n",solution[i]);
    }

    return 0;
}
