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

map <string,int> drink;
int in;
int counter[20010];

vector <int> edges[20010];

void topsort(){
    queue <int> q;
    for (int i=1; i<=in; i++)
        if (!counter[i])
            q.push(i);

    while(!q.empty()) {
        int u=q.front(),sz=edges[u].size();
        q.pop();

        for (int i=0; i<sz; i++) {
            int v=edges[u][i];
            counter[v]--;
            if (!counter[v]) q.push(v);
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    for (int kase=1; kase<=t; kase++){
        int m;
        cin>>m;
        char str1[12],str2[12];

        in=0;
        drink.clear();
        for (int i=1; i<=m; i++) {
            cin>>str1>>str2;
            if (drink.find(str1)==drink.end()) {
                drink[str1]=++in;
                counter[in]=0;
                edges[in].clear();
            }
            if (drink.find(str2)==drink.end()) {
                drink[str2]=++in;
                counter[in]=0;
                edges[in].clear();
            }

            counter[drink[str2]]++;
            edges[drink[str1]].push_back(drink[str2]);
        }

        topsort();

        bool state=true;
        for (int i=1; i<=in; i++)
            if (counter[i]) {
                state=false;
                break;
            }

        printf("Case %d: %s\n",kase,state==true?"Yes":"No");
    }

    return 0;
}
