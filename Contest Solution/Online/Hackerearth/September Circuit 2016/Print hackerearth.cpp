#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXL = 1e6 + 7;
char str [MAXL];

int counter [200];

int main () {
    int n;
    while (cin >> n) {
        cin >> str;
        memset (counter, 0, sizeof counter);
        for (int i = 0; i < n; i++) {
            counter [str [i]]++;
        }

        int mx = INF;
        mx = min (counter ['a'] / 2, mx);
        mx = min (counter ['h'] / 2, mx);
        mx = min (counter ['k'], mx);
        mx = min (counter ['e'] / 2, mx);
        mx = min (counter ['r'] / 2, mx);
        mx = min (counter ['t'], mx);
        mx = min (counter ['c'], mx);

        cout << mx << endl;
    }
    return 0;
}

