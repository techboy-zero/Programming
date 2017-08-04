#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5 + 7;
int n, n1, n2;
int arr [MAX];

int main () {
    while (cin >> n >> n1 >> n2) {
        for (int i = 0; i < n; i++) {
            cin >> arr [i];
        }
        sort (arr, arr + n);
        reverse (arr, arr + n);
        double mean = 0;
        double mean1 = 0, mean2 = 0;
        if (n1 > n2) swap (n1, n2);
        for (int i = 0; i < n1; i++) {
            mean1 += arr [i];
        }
        mean1 /= n1;
        for (int i = n1; i < n1 + n2; i++) {
            mean2 += arr [i];
        }
        mean2 /= n2;
        mean = mean1 + mean2;
        printf ("%.8lf\n", mean);
    }
    return 0;
}
