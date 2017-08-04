#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7, MAXD = 20 + 7;

char num [MAX];

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> num;
        int div, d [MAXD], rem [MAXD];
        cin >> div;

        for (int i = 0; i < div; i++) {
            cin >> d [i];
            rem [i] = 0;
        }
        bool possible = true;
        for (int i = 0; num [i]; i++) {
            for (int j = 0;  j < div; j++) {
                rem [j] = rem [j] * 10 + num [i] - '0';
                rem [j] %= d [j];
            }
        }

        for (int i = 0; i < div; i++) {
            if (rem [i]) possible = false;
        }
        if (possible) cout << num << " - Wonderful." << endl;
        else cout << num << " - Simple." << endl;
    }

    return 0;
}
