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

bool check[1501];
int memo[1010],primes[1000],s,d,in;

queue <int> q;

void sieve(){
    check[0]=check[1]=true;
    primes[in++]=2;

    for (int i=3; i<=1500; i+=2) {
        if (check[i]) continue;

        primes[in++]=i;
        for (int j=i*i; j<=1500; j+=2*i)
            check[j]=true;
    }
}

bool is_valid(int u,int v){
    if (v>d) return false;
    return memo[v]>(memo[u]+1);
}

void BFS(int s) {
    memo[s]=0;
    q.push(s);

    while(!q.empty()) {
        int u=q.front(),limit=u/2;
        q.pop();

        for (int i=0; primes[i]<=limit; i++)
            if (u%primes[i]==0) {
                int v=primes[i]+u;
                if (is_valid(u,v)){
                    memo[v]=memo[u]+1;
                    q.push(v);
                }
            }
    }
}

int main(){
    sieve();
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    for (int kase=1; kase<=t; kase++) {
        cin>>s>>d;

        printf("Case %d: ",kase);
        if (s==d) cout<<0<<endl;
        else if (s>d) cout<<-1<<endl;
        else{
            fill(memo,memo+d+1,INF);
            BFS(s);
            if (memo[d]!=INF) cout<<memo[d]<<endl;
            else              cout<<-1<<endl;
        }
    }

    return 0;
}
