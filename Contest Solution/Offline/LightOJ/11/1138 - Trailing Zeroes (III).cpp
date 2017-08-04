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
#define MOD 100000007

using namespace std;

int MAX = 10e9 - 1;

int counter (int n) {
    int cnt = 0;
    while (n /= 5)
        cnt += n;
    return cnt;
}

int Binary_Search (int lo, int hi, int key) {
    int mn = MAX;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int in = counter (mid);

        if (in >= key) {
            hi = mid - 1;
            if (in == key) mn = min(mn, mid);
        }
        else lo = mid + 1;
    }

    return mn == MAX ? -1 : mn;
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        int q;
        cin>>q;
        printf ("Case %d: ",kase);
        int check = Binary_Search(1, 1000000000, q);
        if (check == -1) cout<<"impossible"<<endl;
        else             cout<<check<<endl;
    }

    return 0;
}
