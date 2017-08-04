#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

int city [110];

int main () {
    int a, n;
    while (cin >> n >> a) {
        for (int i = 1; i <= n; i++) {
            cin >> city [i];
        }
        int i = a - 1, j = a + 1, cnt = city [a];
        while (i > 0 && j <= n) {
            if (city [i] == city [j]) cnt += 2 * city [i];
            i--;
            j++;
        }
        if (i > 0) {
            for (int k = i; k > 0; k--) {
                cnt += city [k];
            }
        }
        if (j <= n) {
            for (int k = j; k <= n; k++) {
                cnt += city [k];
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
