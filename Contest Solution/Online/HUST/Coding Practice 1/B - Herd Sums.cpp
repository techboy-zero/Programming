#include <stdio.h>
#include <iostream>
#include <algorithm>

#define EPS 1e-8
#define PI acos(-1.0)
#define INF 1e9

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 7;

int main () {
    int n;
    while (cin >> n) {
        int first = 1, last = 1;
        ll tot = 0;
        ll cnt = 0;
        while (first <= last) {
            if (tot == n) {
                cnt++;
                tot -= first;
                first++;
            } else if (tot > n) {
                tot -= first;
                first++;
            } else {
                tot += last;
                if (last < n) last++;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}
