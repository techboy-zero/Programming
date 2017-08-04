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

#define mset(a,v)    memset(a, v, sizeof(a))

using namespace std;

struct node {
    int endmark;
    int next [4];
    node () {
        endmark = 0;
        for (int i = 0; i < 4; i++) next [i] = -1;
    }
} trie [3000010];

map <char, int> w;
int ttl, mx = 0;
void Init () {
    ttl = 0;
    trie [ttl++] = node ();
}

void insertion (char str []) {
    int curr = 0;
    for (int i = 0; str [i]; i++) {
        int in = w [str [i]];
        if (trie [curr].next [in] == -1) {
            trie [curr].next [in] = ttl;
            trie [ttl++] = node ();
        }
        curr = trie [curr].next [in];
    }
    trie [curr].endmark++;
}

int find_match (int i, int curr) {
    int ret = 0;
    ret += trie [curr].endmark;
    for (int k = 0; k < 4; k++) {
        if (trie [curr].next [k] == -1) continue;
        ret += find_match (i + 1, trie [curr].next [k]);
    }
    mx = max (mx, ret * i);
    return ret;
}

int main() {
    w ['A'] = 0;
    w ['G'] = 1;
    w ['T'] = 2;
    w ['C'] = 3;

    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int n;
        char str [60];
        Init ();
        scanf ("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf ("%s",&str);
            insertion (str);
        }
        mx = 0;
        int temp = find_match (0, 0);
        printf ("Case %d: %d\n", kase, mx);
    }

    return 0;
}
