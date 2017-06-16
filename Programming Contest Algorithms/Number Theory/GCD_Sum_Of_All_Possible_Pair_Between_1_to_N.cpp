/*Given N, we have to calculate output of the code below in an optimized way.
	G=0;
	for(i = 1 ; i < N ; i++)
		for(j = i+1 ; j <= N ; j++)
			G += gcd(i,j);
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 1e6 + 7;
int coprime [MAX];
ll tot [MAX];

void sievePhi () {
    coprime [1] = 1;

    for (int i = 2; i <= MAX - 7; i++) {
        if (coprime[i]) continue;
        coprime [i] = i - 1;

        for (int j = 2 * i; j <= MAX - 7; j += i) {
            if (!coprime [j]) coprime [j] = j;
            coprime [j] = coprime [j] / i * (i - 1);
        }
    }
}

void sieve () {
    for (int i = 1; i <= MAX - 7; i++) {
        for (int j = 2 * i; j <= MAX - 7; j += i) {
            tot [j] += ( (ll) i * coprime [j / i]);
        }
    }
}

void total () {
    for (int i = 2; i <= MAX - 7; i++) {
        tot [i] += tot [i - 1];
    }
}

int main() {
    sievePhi();
    sieve();
    total();

    int n;

    while (scanf("%d",&n) && n) {
        printf ("%lld\n", tot [n]);
    }

    return 0;
}
