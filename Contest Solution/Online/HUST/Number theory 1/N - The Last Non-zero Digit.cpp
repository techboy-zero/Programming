#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 2e7 + 7;

int main () {
    ll n, m;
    while (cin >> n >> m) {
        ll nm = n - m;
        ll two = 0;
        ll five = 0;
        ll lastdigit = 1;
        for (int i = n; i > nm; i--) {
            int temp = i;
            while (temp % 2 == 0) {
                temp /= 2;
                two++;
            }
            while (temp % 5 == 0) {
                temp /= 5;
                five++;
            }
            if (temp >= 10) temp %= 10;
            lastdigit *= temp;
            if (lastdigit >= 10) lastdigit %= 10;
        }
        if (two > five) {
            two -= five;
            for (int i = 1; i <= two; i++) {
                lastdigit *= 2;
                if (lastdigit >= 10) lastdigit %= 10;
            }
        } else {
            five -= two;
            for (int i = 1; i <= five; i++) {
                lastdigit *= 5;
                if (lastdigit >= 10) lastdigit %= 10;
            }
        }

        cout << lastdigit << endl;
    }
    return 0;
}
