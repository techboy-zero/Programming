#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5 + 7;
char str [MAX];

int main () {
    while (cin >> str) {
        int mx = 0, pos = -1;
        int len = strlen (str);
        for (int i = 0; str [i]; i++) {
            if (str [i] == 'A' || str [i] == 'E' || str [i] == 'I' || str [i] == 'O' || str [i] == 'U' || str [i] == 'Y') {
                mx = max (mx, i - pos);
                pos = i;
            }
        }
        mx = max (mx, len - pos);
        cout << mx << endl;
    }

    return 0;
}

