#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 1e5;
ll ar [MAX + 7];
bool mark [MAX + 7];

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n, d;
        ll total = 0;
        cin >> n >> d;
        for (int i = 0; i < n; i++) {
            cin >> ar [i];
            total += ar [i];
        }

        if (total % n) {
            cout << -1 << endl;
        } else {
            total /= n;
            memset (mark, false, sizeof mark);
            bool possible = true;
            ll cnt = 0;
            for (int i = 0; i < n; i++) {
                if (i + d < n) {
                    ar [i + d] -= (total - ar [i]);
                    cnt += llabs (total - ar [i]);
                    ar [i] = total;
                }
                if (ar [i] != total) {
                    possible = false;
                    break;
                }
            }

            if (!possible) cout << -1 << endl;
            else cout << cnt << endl;
        }
    }
    return 0;
}
