#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    int n;
    while (cin >> n) {
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            sum += num - 1;
            if (sum % 2 == 0) cout << 2 << endl;
            else cout << 1 << endl;
        }
    }
    return 0;
}
