#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        bool easy = true;
        int response = 0;
        for (int i = 0; i < n; i++) {
            cin >> response;
            if (response == 1) {
                easy = false;
            }
        }

        if (easy) cout << "EASY" << endl;
        else cout << "HARD" << endl;
    }
    return 0;
}
