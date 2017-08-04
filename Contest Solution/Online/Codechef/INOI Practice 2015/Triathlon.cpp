#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 2e5 + 7;

pair <int, int> competitor [MAX];

bool comp (pair <int, int> a, pair <int, int> b) {
    int max1 = max (a.first, b.first + a.second);
    int max2 = max (a.first + b.second, b.first);
    return max1 < max2;
}

int main () {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    while (cin >> n) {
        int prog, pole, dough;
        for (int i = 0; i < n; i++) {
            cin >> prog >> pole >> dough;
            int sum = prog + pole + dough;
            competitor [i].first = sum;
            competitor [i].second = prog;
        }
        sort (competitor, competitor + n, comp);
        int mx = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            mx = max (mx, curr + competitor [i].first);
            curr += competitor [i].second;
        }
        cout << mx << endl;
    }
    return 0;
}
