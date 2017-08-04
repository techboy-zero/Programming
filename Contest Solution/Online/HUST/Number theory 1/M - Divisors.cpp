#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e5 + 7;

ll divi [MAX], divsum [MAX];

void preCalc () {
    for (int i = 1; i <= MAX - 7; i++) {
        for (int j = i; j <= MAX - 7; j += i) {
            divi [j]++;
            divsum [j] += i;
        }
    }
}

int main () {
    preCalc ();
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        ll a, b, k;
        cin >> a >> b >> k;
        if (a % k != 0) {
            a = ((a / k) + 1) * k;
        }
        ll sum1 = 0, sum2 = 0;
        for (ll i = a; i <= b; i += k) {
            sum1 += divi [i];
            sum2 += divsum [i];
        }
        cout << sum1 << " " << sum2 << endl;
    }

    return 0;
}
