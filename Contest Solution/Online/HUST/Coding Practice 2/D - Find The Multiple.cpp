#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main () {
    for (int i = 7; i <= 200; i++) {
        bool flag = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }

        if (flag) {
            int rem = 1;
            cout << i << "\t1";
            while (rem) {
                cout << 1;
                rem = rem * 10 + 1;
                rem %= i;
            }
            cout << endl;
        }
    }
    return 0;
}

