#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int k;
        ll meat;
        cin >> k >> meat;
        printf ("Case %d:\n", kase);
        if (!k) {
            cout << meat / 3 << endl;
            meat -= (meat / 3);
            cout << (meat * 2 / 3) << endl;
            cout << (meat / 3) << endl;
        } else {
            meat *= 9;
            meat /= 2;
            cout << meat / 3 << endl;
            cout << (meat * 4 / 9) << endl;
            cout << meat << endl;
        }
    }
    return 0;
}

