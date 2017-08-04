#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e5 + 7;

int ar [MAX];
bool seq [MAX];

int main () {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int t;

    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> ar [i];
        }
        memset (seq, false, sizeof (seq));
        for (int i = 2; i < n; i++) {
            if (ar [i] == ar [i - 1] + ar [i - 2]) {
                seq [i] = true;
            }
        }
        int prev = 0;
        int curr = 0;
        int high = 0;
        for (int i = 0; i < n; i++) {
            if (prev == seq [i]) {
                curr++;
            } else {
                prev = seq [i];
                curr = 1;
                if (prev == 1) curr += 2;
            }

            if (!prev) curr = min (2, curr);
            high = max (curr, high);
        }

        cout << high << endl;
    }

    return 0;
}
