#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e3 + 7;

struct segment {
    int dx, dy;
} s [MAX * MAX];

int px [MAX], py [MAX];

bool comp (segment a, segment b) {
    if (a.dx == b.dx) return a.dy < b.dy;
    return a.dx < b.dx;
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n;
        int len = 0;
        cin >> n;
        ll parallel = 0;
        for (int i = 0; i < n; i++) {
            cin >> px [i] >> py [i];
            for (int j = i - 1; j >= 0; j--) {
                s [len].dx = px [i] + px [j];
                s [len++].dy = py [i] + py [j];
            }
        }
        sort (s, s + len, comp);
        ll cnt = 1;
        for (int i = 1; i < len; i++) {
            if (s [i].dx == s [i - 1].dx && s [i].dy == s [i - 1].dy) {
                cnt++;
            } else {
                parallel += (cnt * (cnt - 1) / 2);
                cnt = 1;
            }
        }
        parallel += (cnt * (cnt - 1) / 2);
        printf ("Case %d: %lld\n", kase, parallel);
    }
    return 0;
}
