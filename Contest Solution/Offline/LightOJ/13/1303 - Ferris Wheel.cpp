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

int a [21][21];

int solution (int i, int j) {
    bool taken [i + 1][j + 1];
    int seats [j + 1], counter [i + 1], ride = 0;
    int curr = 1, cnt = i * j, total = 0;
    deque <int> q, t;

    for (int k = 1; k <= i; k++) q.push_back (k);
    mset (taken, false);
    mset (seats, 0);
    mset (counter, 0);

    while (cnt || ride) {
        total += 5;
        if (seats [curr]) {
            int temp = seats [curr];
            ride--;
            if (counter [temp] != j) q.push_back (temp);
            seats [curr] = 0;
        }

        while (!q.empty () && taken [q.front ()][curr]) {
            t.push_back (q.front());
            q.pop_front ();
        }

        if (!q.empty ()) {
            int temp = q.front ();
            taken [temp][curr] = true;
            cnt--;
            ride++;
            seats [curr] = temp;
            counter [temp]++;
            q.pop_front ();
        }

        while (!t.empty ()) {
            q.push_front (t.back ());
            t.pop_back ();
        }
        curr++;
        if (curr > j) curr = 1;
    }

    return total;
}

void pregen () {
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            a [i][j] = solution (i, j);
        }
    }
}

int main(){
    pregen ();
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        int n, m;
        cin>>n>>m;

        printf ("Case %d: %d\n", kase, a [n][m]);
    }
    return 0;
}
