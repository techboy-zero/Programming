#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXT = 1e3 + 7;

bool ghost [MAXT];
int counter [MAXT];

int main () {
    int m, t, r;
    while (cin >> m >> t >> r) {
        memset (ghost, false, sizeof ghost);
        memset (counter, 0, sizeof (counter));
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            ghost [num] = true;
        }

        if (t < r) cout << -1 << endl;
        else {
            int cnt = 0;
            for (int i = 1; i <= 300; i++) {
                if (ghost [i]) {
                    if (counter [i] < r) {
                        int need = r - counter [i];
                        cnt += need;
                        for (int j = 1; j <= need; j++) {
                            for (int k = i; k <= i + t - j; k++) {
                                counter [k]++;
                            }
                        }
                    }
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
