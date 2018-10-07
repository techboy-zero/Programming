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
        int ax, ay, bx, by, cx, cy;
        cin >> ax >> ay;
        cin >> bx >> by;
        cin >> cx >> cy;

        bool isPossible = true;
        if (bx <= cx && ax >= bx && ax <= cx) {
            isPossible = false;
        } else if (ax >= cx && ax <= bx) {
            isPossible = false;
        }

        if (by <= cy && ay >= by && ay <= cy) {
            isPossible = false;
        } else if (ay >= cy && ay <= by) {
            isPossible = false;
        }

        if (isPossible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

