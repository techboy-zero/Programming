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

unsigned long long fact[25];
bool found;

void fact_gen(){
    fact[0]=1;

    for (int i=1; i<=20; i++)
        fact[i]=i*fact[i-1];
}

int main(){
    fact_gen();
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    for (int kase=1; kase<=t; kase++){
        unsigned long long n;
        cin>>n;
        int i=lower_bound(fact,fact+21,n)-fact;
        int check=0;

        while(n && i!=-1){
            if (fact[i]<=n){
                n-=fact[i];
                check|=(1<<i);
            }
            i--;
        }

        if (n) printf("Case %d: impossible\n",kase);
        else{
            printf("Case %d: ",kase);
            bool add=false;
            for (int i=0; i<=20; i++){
                if (check & (1<<i)){
                    if (add) cout<<"+";
                    add=true;
                    cout<<i<<"!";
                }
            }
            cout<<endl;
        }
    }

    return 0;
}
