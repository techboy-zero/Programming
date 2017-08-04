#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e5 + 7;

int ar [MAX];
map <int, bool> mark;

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        cin >> n;
        mark.clear ();
        for (int i = 0; i < n; i++) {
            cin >> ar [i];
            mark [ar [i]] = true;
        }
        sort (ar, ar + n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ar [i] % 2 == 0) {
                if (mark.find (ar [i] / 2) != mark.end ()) cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
