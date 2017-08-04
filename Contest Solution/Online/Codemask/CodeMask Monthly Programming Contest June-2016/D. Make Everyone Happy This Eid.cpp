#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e2 + 7;

int ar [MAX];

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        int tot = 0;
        int part = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ar [i];
            tot += ar [i];
        }
        printf ("Case %d: ", kase);
        if (tot % 3) cout << ":(" << endl;
        else {
            bool possible = true;
            sort (ar, ar + n);
            reverse (ar, ar + n);
            for (int i = 0; i < 3; i++) {
                part = tot / 3;
                for (int j = 0; j < n; j++) {
                    if (ar [j] <= part) {
                        part -= ar [j];
                        ar [j] = INF;
                    }
                }
                if (part) possible = false;
                if (!possible) break;
            }
            if (possible) cout << "Eid Makes Happy Everyone" << endl;
            else cout << ":(" << endl;
        }
    }
    return 0;
}
