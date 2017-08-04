/*
ID: arnab111
PROG: ride
LANG: C++
*/

#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

char str [10];

int main () {
    freopen ("ride.in", "r", stdin);
    freopen ("ride.out", "w", stdout);

    cin >> str;
    int val1 = 1;
    for (int i = 0; str [i]; i++) {
        val1 *= (str [i] - 'A' + 1);
        if (val1 >= 47) val1 %= 47;
    }
    cin >> str;
    int val2 = 1;
    for (int i = 0; str [i]; i++) {
        val2 *= (str [i] - 'A' + 1);
        if (val2 >= 47) val2 %= 47;
    }
    if (val1 == val2) cout << "GO" << endl;
    else cout << "STAY" << endl;
    return 0;
}

