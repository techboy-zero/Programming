#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

int main () {
    int a [5];
    while (cin >> a [0]) {
        int tot = a [0];
        for (int i = 1; i <= 4; i++) {
            cin >> a [i];
            tot += a [i];
        }
        sort (a, a + 5);
        int hi = 0, curr = -1, cnt = 1;
        for (int i = 0; i < 5; i++) {
            if (a [i] == curr) {
                if (cnt < 3) cnt++;
            } else {
                curr = a [i];
                cnt = 1;
            }
            if (cnt > 1) hi = max (hi, cnt * a [i]);
        }
        cout << tot - hi << endl;
    }
    return 0;
}
