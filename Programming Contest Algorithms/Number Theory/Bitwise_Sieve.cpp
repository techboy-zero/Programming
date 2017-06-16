typedef long long ll;
const int MAX = (int) 1e8 + 20;

vector <ll> primes;
int check [MAX / 32 + 7];

bool getBit (int n, int pos) { return (n & (1 << pos));}
int setBit (int n, int pos) { return n = (n | (1 << pos));}

void bitwise_sieve () {
    primes.push_back (2);

    for (ll i = 3; i <= MAX; i += 2) {
        if (getBit (check [i / 32], i % 32)) continue;
        primes.push_back (i);

        for (ll j = i * i; j <= MAX; j += 2 * i)
            check [j / 32] = setBit (check [j / 32], j % 32);
    }
}
