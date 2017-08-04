#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 5e4 + 7;

int pat [MAX], sequence [MAX], diff [MAX];
int pi [MAX];
int n, k;

void failure () {
    int shift = 0;
    for (int i = 2; i <= k; i++) {
        while (shift > 0 && pat [shift] != pat [i - 1]) shift = pi [shift];
        if (pat [shift] == pat [i - 1]) shift++;
        pi [i] = shift;
    }
}

int KMP () {
    failure ();
    int shift = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        while (shift > 0 && pat [shift] != diff [i]) shift = pi [shift];
        if (pat [shift] == diff [i]) shift++;
        if (shift == k) {
            cnt++;
            shift = pi [shift];
        }
    }
    return cnt;
}

int main () {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> sequence [i];
            diff [i] = sequence [i];
        }
        for (int i = 1; i < n; i++) diff [i] -= sequence [i - 1];
        for (int i = 0; i < k; i++) cin >> pat [i];
        cout << KMP () << endl;
    }

    return 0;
}
