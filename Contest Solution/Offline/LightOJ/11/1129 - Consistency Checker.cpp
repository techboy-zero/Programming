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

//{{{ ************[  Floating points     ]************
#define ABS(x)          (((x) < 0) ? - (x) : (x))
#define ZERO(x)         (ABS (x) < EPS)
#define EQUAL(x, y)     (ZERO ((x) - (y)))

#define sqr(x)        (x*x)
#define cube(x)        (x*x*x)
#define INF            (int)1e9
#define EPS            1e-9
#define MAX 12
#define MAX_N 110010

#define mset(a,v)    memset(a, v, sizeof(a))

using namespace std;

char words [10010][12];

struct node {
    bool endmark;
    int next [MAX];
    node () {
        endmark = false;
        for (int i = 0; i < MAX; i++) next [i] = -1;
    }
} trie[ MAX_N ];

int ttl;
void init () { ttl = 0; trie[ttl++] = node(); }

void trie_add (char str []) {
    int len = strlen(str);
    int cur = 0;
    for(int i = 0; i < len; i++) {
        int ch = str [i] - '0';
        if(trie [cur].next [ch] == -1) {
            trie [ttl] = node();
            trie [cur].next [ch] = ttl++;
        }
        cur = trie [cur].next [ch];
    }
    trie [cur].endmark = true;
}

bool prefix_search(char str []) {
    int len = strlen(str);
    int cur = 0;
    for(int i = 0; i < len; i++) {
        int ch = str [i] - '0'; // for using as index
        if (trie [cur].endmark) return true;
        cur = trie [cur].next [ch];
    }
    return false;
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin>>n;

        init();
        for (int i = 0; i < n; i++) {
            cin>>words [i];
            trie_add (words [i]);
        }

        bool prefix = false;
        for (int i = 0; i < n; i++) {
            if (prefix_search (words [i]))
                prefix = true;
            if (prefix) break;
        }

        printf("Case %d: ", kase);
        if (!prefix) cout<<"YES"<<endl;
        else         cout<<"NO"<<endl;
    }

    return 0;
}
