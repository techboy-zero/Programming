#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e2 + 7;

char str [MAX];

int main () {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int n;
    while (cin >> n) {
        int cnt = 0;
        cin >> str;
        for (int i = 0; i < n - 2; i++) {
            if (str [i] == '0' && str [i + 1] == '1' && str [i + 2] == '0') {
                str [i + 2] = '1';
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
