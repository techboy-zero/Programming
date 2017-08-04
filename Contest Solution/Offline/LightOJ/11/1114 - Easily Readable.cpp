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
    int next [53];

    node () {
        endmark = 0;
        for (int i = 0; i < 52; i++) next [i] = -1;
    }
}trie [100010];

int ttl = 0;
long long a [10010];
map <char, int> w;
vector < pair <string, int> > v;
char str [100010], temp [100010];

void Init () { ttl = 0; trie [ttl++] = node (); }

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

int findmatch (const char str []) {
    int curr = 0;
    for (int i = 0; str [i]; i++) {
        int in = w [str [i]];
        if (trie [curr].next [in] == -1) return 0;
        curr = trie [curr].next [in];
    }
    return trie [curr].endmark;
}

bool comp (pair <string, int> a, pair <string, int> b) {
    if (!a.first.compare (b.first)) return a.second < b.second;
    return a.first.compare (b.first) < 0;
}

void offline () {
    sort (v.begin (), v.end (), comp);
    int sz = v.size ();
    if (!sz) return;
    int prev = findmatch (v [0].first.c_str ());
    a [v [0].second] = prev;

    for (int i = 1; i < sz; i++) {
        if (v [i].first.compare (v [i - 1].first)) prev = findmatch (v [i].first.c_str ());
        a [v [i].second] *= prev;
    }
    v.clear ();
}

int main () {
    for (int i = 0; i < 26; i++) {
        w ['A' + i] = i;
        w ['a' + i] = i + 26;
    }

    //freopen ("input.txt", "r", stdin);
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int n;
        scanf ("%d", &n);
        Init ();

        for (int i = 0; i < n; i++) {
            scanf ("%s", &str);
            int len = strlen (str);
            if (len > 3) sort (str + 1, str + len - 1);
            insertion (str);
        }

        int m, in = 0;
        scanf ("%d", &m);
        getchar ();
        printf ("Case %d:\n", kase);

        for (int i = 0; i < m; i++) {
            a [i] = 1;
            gets (str);
            bool state = false;
            for (int j = 0; str [j]; j++) {
                if (str [j] != ' ') {
                    state = true;
                    temp [in++] = str [j];
                }else if (str [j] == ' ' && state) {
                    state = false;
                    temp [in] = '\0';
                    if (in > 3) sort (temp + 1, temp + in - 1);
                    v.push_back (make_pair (temp, i));
                    in = 0;
                }
            }

            if (state) {
                temp [in] = '\0';
                if (in > 3) sort (temp + 1, temp + in - 1);
                v.push_back (make_pair (temp, i));
            }
            in = 0;
        }

        offline ();
        for (int i = 0; i < m; i++)
            printf ("%lld\n", a [i]);
    }

    return 0;
}
