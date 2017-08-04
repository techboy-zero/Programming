#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

int main () {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    char str1 [100], str2 [100];
    while (scanf ("%s %s", &str1, &str2) != EOF) {
        if (strcmp (str1, str2) >= 0) cout << str1 << endl;
        else cout << str2 << endl;
    }
    return 0;
}
