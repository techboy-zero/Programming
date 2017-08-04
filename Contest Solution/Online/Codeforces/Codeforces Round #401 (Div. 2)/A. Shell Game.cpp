#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main () {
    int n;
    while (cin >> n) {
        int currpos;
        cin >> currpos;
        int pos0, pos1;
        int temp = n;
        temp %= 6;
        if (!temp || temp == 5) pos0 = 0;
        else if (temp == 1 || temp == 4) pos0 = 1;
        else if (temp == 2 || temp == 3) pos0 = 2;

        temp = n;
        temp %= 6;
        if (!temp || temp == 3) pos1 = 1;
        else if (temp == 1 || temp == 2) pos1 = 0;
        else if (temp == 4 || temp == 5) pos1 = 2;

        if (pos0 == currpos) cout << 0 << endl;
        else if (pos1 == currpos) cout << 1 << endl;
        else cout << 2 << endl;
    }
    return 0;
}
