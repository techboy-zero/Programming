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
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> str;
        int val = 0, consecutive = 0;
        for (int i = 0; str [i]; i++) {
            if (str [i] == 'a' || str [i] == 'e' || str [i] == 'i' || str [i] == 'o' || str [i] == 'u' || str [i] == 'y') {
                val++;
                consecutive = 0;
            } else {
                val--;
                consecutive++;
            }
            if (consecutive == 3) break;
        }

        if (consecutive == 3 || val < 0) cout << "hard" << endl;
        else cout << "easy" << endl;
    }

    return 0;
}
