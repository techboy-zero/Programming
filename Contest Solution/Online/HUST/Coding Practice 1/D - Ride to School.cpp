#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main () {
    int n;
    while (cin >> n && n) {
        int vi, ti;
        double temp;
        int mn = INF;
        for (int i = 1; i <= n; i++) {
            cin >> vi >> ti;
            if (ti < 0) continue;
            temp = (4.5 / vi) * 3600;
            temp += ti;
            temp = ceil (temp);
            mn = min (mn, (int) temp);
            //cout << mn << endl;
        }
        cout << mn << endl;
    }
    return 0;
}

