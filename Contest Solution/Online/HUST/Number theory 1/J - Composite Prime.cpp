#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 2e6 + 7;

vector <int> primes;
bool check [MAX + 7];
bool composite [MAX + 7];

void compositePrime () {
    for (int i = 4; i <= MAX; i++) {
        if (!composite [i]) continue;
        for (int j = 2 * i; j <= MAX; j += i) {
            composite [j] = false;
        }
    }
}

void sieve () {
    fill (composite, composite + MAX, true);
    composite [1] = composite [2] = false;

    primes.push_back (2);
    for (int i = 3; i <= MAX; i += 2) {
        if (check [i]) continue;
        composite [i] = false;
        primes.push_back (i);
        for (ll j = (ll) i * i; j <= MAX; j += 2 * i) {
            check [j] = true;
        }
    }
}

int main () {
    sieve ();
    compositePrime ();

    int n;
    while (cin >> n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            cnt += composite [num];
        }
        cout << cnt << endl;
    }
    return 0;
}
