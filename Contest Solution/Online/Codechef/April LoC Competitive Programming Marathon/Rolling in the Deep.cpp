#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e5 + 7;

char str [MAX];

int main () {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    while (gets (str)) {
        int high = 0, curr = 0;
        for (int i = 0; str [i]; i++) {
            if (str [i] == '(') curr++;
            else if (str [i] == ')') curr--;
            if (curr > high) high = curr;
        }

        for (int i = 0; str [i]; i++) {
            if (str [i] == '(') {
                curr++;
                continue;
            } else if (str [i] == ')') {
                curr--;
                continue;
            }
            if (high == curr) cout << str [i];
        }
        cout << endl;
    }

    return 0;
}
