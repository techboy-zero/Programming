#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, k;
char str [110];

int main () {
    while (cin >> n >> k) {
        cin >> str;
        int pos;
        for (int i = 0; str [i]; i++) {
            if (str [i] == 'G') pos = i;
        }
        bool possible = false;
        for (int i = pos; i < n; i += k) {
            if (str [i] == '#') break;
            if (str [i] == 'T') possible = true;
        }
        for (int i = pos; i >= 0; i -= k) {
            if (str [i] == '#') break;
            if (str [i] == 'T') possible = true;
        }
        if (possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

