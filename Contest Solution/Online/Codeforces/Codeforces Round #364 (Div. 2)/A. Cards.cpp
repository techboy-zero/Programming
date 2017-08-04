#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

int main () {
    ll n, ar [110];

    while (cin >> n) {
        ll avg = 0;
        for (int i = 0; i < n; i++) {
            cin >> ar [i];
            avg += ar [i];
        }
        avg *= 2;
        avg /= n;
        for (int i = 1; i <= n / 2; i++) {
            int curr = 0;
            bool second = false;
            for (int j = 0; j < n; j++) {
                if (!second && curr + ar [j] <= avg) {
                    cout << (j + 1) << " ";
                    curr += ar [j];
                    ar [j] = INF;
                    second = true;
                } else if (second && curr + ar [j] == avg) {
                    cout << (j + 1) << endl;
                    curr += avg;
                    ar [j] = INF;
                }
            }
        }
    }
    return 0;
}
