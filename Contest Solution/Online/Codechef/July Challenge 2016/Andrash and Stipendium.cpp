#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        int tot = 0;
        bool fail = false;
        bool full = false;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int marks;
            cin >> marks;
            tot += marks;
            if (marks <= 2) fail = true;
            if (marks == 5) full = true;
        }
        tot /= n;
        if (tot < 4 || fail || !full) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
