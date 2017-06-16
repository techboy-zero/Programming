const int MAX = 1e5 + 7;

bool flag [MAX];
vector <int> primes;

void linearSieve () {
    int sz = 1;
    primes.push_back (2);
    for (int i = 3; i <= MAX - 7; i += 2) {
        if (!flag [i]) {
            primes.push_back (i);
            sz++;
        }
        for (int j = 1; j < sz && i * primes [j] <= MAX - 7; ++j) {
            flag [i * primes [j]] = true;
        }
    }
}
