#include <iostream>
#include <stdio.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int counter [30];

int main () {
    char str [80];
    for (int i = 1; i <= 4; i++) {
        gets (str);
        for (int len = 0; str [len]; len++) {
            if (str [len] >= 'A' && str [len] <= 'Z')
                counter [str [len] - 'A']++;
        }
    }

    int mx = 0;
    for (int i = 0; i < 26; i++) {
        mx = max (counter [i], mx);
    }

    for (int i = mx; i >= 1; i--) {
        int rightmost = -1;
        for (int j = 0; j < 26; j++) {
            if (counter [j] >= i) {
                rightmost = j;
            }
        }

        for (int j = 0;  j <= rightmost; j++) {
            if (counter [j] >= i) cout << "*";
            else cout << " ";
            if (j != rightmost) cout << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 26; i++) {
        cout << (char)('A' + i);
        if (i == 25) cout << endl;
        else cout << " ";
    }
    return 0;
}

