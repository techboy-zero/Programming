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

int n,k,limit;
map <int,char> word;

void word_gen() {
    int cnt=0;
    for (int i=1; i!=(1<<30); i<<=1) {
        word[i]='A'+cnt;
        cnt++;
    }
}

void print_permutation(int check,int i,char s[]) {
    if (i==n) {
        cout<<s<<endl;
        k--;
        return;
    }

    if (!k) return;

    for (int j=1; j!=limit; j<<=1) {
        if (!(j & check)) {
            s[i]=word[j];
            s[i+1]='\0';
            print_permutation(check | j,i+1,s);
            if (!k) return;
        }
    }
}

int main(){
    word_gen();
    //freopen("input.txt","r",stdin);

    int t;
    cin>>t;

    for (int kase=1; kase<=t; kase++) {
        cin>>n>>k;
        char str[k+1];
        limit=1<<n;
        printf("Case %d:\n",kase);
        print_permutation(0,0,str);
    }

    return 0;
}
