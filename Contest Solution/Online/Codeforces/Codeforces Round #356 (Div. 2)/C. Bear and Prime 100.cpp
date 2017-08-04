#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

int primes [] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main () {
    int cnt = 0, p;
    char str [10];
    for (int i = 0; i < 15; i++) {
        cout << primes [i] << endl;
        fflush (stdout);
        cin >> str;
        if (str [0] == 'y') {
            p = primes [i];
            cnt++;
        }
    }
    if (!cnt) cout << "prime" << endl;
    else if (cnt > 1) cout << "composite" << endl;
    else {
        int num = p * p;
        while (num <= 100) {
            cout << num << endl;
            fflush (stdout);
            cin >> str;

            if (str [0] == 'y') {
                cout << "composite" << endl;
                break;
            }
            num *= p;
        }
        if (num > 100) cout << "prime" << endl;
    }
    return 0;
}
