#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 2e4 + 7;

int counter [MAX];

int main () {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, d;
    while (cin >> n >> d) {
        memset (counter, 0, sizeof counter);
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            counter [num]++;
        }
        ll triplets = 0;
        for (int i = 0; i <= MAX - 7 - 2 * d; i++) {
            triplets += (ll) counter [i] * counter [i + d] * counter [i + 2 * d];
        }
        cout << triplets << endl;
    }
    return 0;
}
