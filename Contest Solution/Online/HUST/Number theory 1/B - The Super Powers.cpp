#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e5 + 7;
const ull MAXL = 18446744073709551615;

vector <ull> superPowers;
bool primes [70];
bool check [MAX];

int getPower (int num) {
    return (int) (floor (log10(MAXL) / log10(num)));
}

void primesgen() {
    for (int i = 2; i <= 64; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                primes [i] = true;
                break;
            }
        }
    }
}

ull power (int n, int p) {
    ull ans = 1;
    for (int i = 1; i <= p; i++) {
        ans *= n;
    }
    return ans;
}

void superPowerGen () {
    primesgen();
    superPowers.push_back (1);
    for (int i = 2; i <= MAX - 7; i++) {
        if (check [i]) continue;
        int limit = getPower (i);
        for (int j = 0; j <= limit; j++) {
            ull temp = power (i, j);
            if (temp <= MAX - 7) check [temp] = true;
            if (primes [j]) superPowers.push_back (temp);
        }
    }
    sort (superPowers.begin(), superPowers.end());
}

int main () {
    superPowerGen();
    int sz = superPowers.size();
    for (int i = 1; i < sz; i++) {
        cout << superPowers [i] << endl;
    }
    return 0;
}
