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
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    while (cin >> n) {
        int steps = 0;
        int curr = 0;
        for (int i = 0; i < n; i++) cin >> ar [i];
        while (curr < n - 1) {
            if (curr + 2 < n && ar [curr + 2] != 1) curr += 2;
            else curr++;
            steps++;
        }
        cout << steps << endl;
    }
    return 0;
}
