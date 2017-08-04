#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e3 + 7;
char num1 [MAX], num2 [MAX];
int counter1 [12], counter2 [12];

int main () {
    int n;
    while (cin >> n) {
        cin >> num1 >> num2;
        sort (num1, num1 + n);
        sort (num2, num2 + n);

        memset (counter1, 0, sizeof counter1);
        memset (counter2, 0, sizeof counter2);
        for (int i = 0; i < n; i++) {
            counter1 [num1 [i] - '0']++;
            counter2 [num2 [i] - '0']++;
        }
        reverse (num1, num1 + n);
        reverse (num2, num2 + n);

        int indx = 0;
        int flip1 = 0, flip2 = 0;
        for (int i = 0; i < n; i++) {
            if (num2 [indx] > num1 [i]) {
                indx++;
                flip2++;
            }
        }

        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= i; j++) {
                if (counter2 [i] >= counter1 [j]) {
                    counter2 [i] -= counter1 [j];
                    counter1 [j] = 0;
                } else {
                    counter1 [j] -= counter2 [i];
                    counter2 [i] = 0;
                }
            }
        }

        for (int i = 0; i <= 9; i++) {
            flip1 += counter2 [i];
        }

        cout << flip1 << endl;
        cout << flip2 << endl;
    }

    return 0;
}
