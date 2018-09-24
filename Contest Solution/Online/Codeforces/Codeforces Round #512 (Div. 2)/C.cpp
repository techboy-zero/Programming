#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int n;
    while (cin >> n) {
        string s;
        cin >> s;

        int num = 0;
        bool isPossible = false;
        for (int i = 0; i < n - 1; i++) {
            num += s[i] - '0';

            int temp = 0;
            for (int j = i + 1; j < n; j++) {
                int curr = s [j] - '0';
                temp += curr;

                if (temp > num) {
                    if (temp == num + curr) {
                        temp = curr;
                    } else {
                        break;
                    }
                }
            }

            if (temp == num) {
                isPossible = true;
                break;
            }
        }

        if (isPossible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
