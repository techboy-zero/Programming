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

vector <long long> sol;

int main() {
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        long long p, l;
        cin>>p>>l;
        p -= l;
        sol.clear ();
        for (long long i = 1; i * i <= p; i++) {
            if (p % i == 0) {
                if (i > l) sol.push_back (i);
                if (i * i != p && (p / i) > l) sol.push_back (p / i);
            }
        }
        printf ("Case %d:", kase);

        int sz = sol.size ();

        if (!sz) cout<<" impossible";
        else {
            sort (sol.begin (), sol.end ());
            for (int i = 0; i < sz; i++) {
                cout<<" "<<sol [i];
            }
        }
        cout<<endl;
    }

    return 0;
}
