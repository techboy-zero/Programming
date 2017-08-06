#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e2;
int ar [MAX + 7];
bool mark [11];

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ar [i];
        }
        bool possible = true;
        memset (mark, false, sizeof mark);
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (i && ar [i] - ar [i - 1] > 1) {
                possible = false;
            }
            if (j < n - 1 && ar [j + 1] - ar [j] > 1) {
                possible = false;
            }
            if (ar [i] != ar [j]) {
                possible = false;
            }
            mark [ar [i]] = true;
            if (!possible) break;
        }
        for (int i = 1; i <= 7; i++) {
            if (!mark [i]) possible = false;
        }

        if (possible) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
