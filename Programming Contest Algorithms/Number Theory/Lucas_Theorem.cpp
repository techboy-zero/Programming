
typedef long long ll;

const int mx = 1e7;
ll fact [mx + 7];

ll InverseMod (ll n, ll p, ll m) {
    if (!p) return 1;
    if (p == 1) return n;

    if (p % 2) return (InverseMod (n, p - 1, m) * n) % m;
    ll res = InverseMod (n, p >> 1, m) % m;
    return (res * res) % m;
}

void GetFactorial (ll p) {
    fact [0] = fact [1] = 1;
    for (ll i = 2; i <= p; i++) {
        fact [i] = ((fact [i - 1] % p) * (i % p)) % p;
    }
}

ll LucasTheroem (ll n, ll r, ll p) {
    GetFactorial (p);
    ll ans = 1;

    while (n || r) {
        if (n % p < r % p) return 0;
        ans *= (fact [n % p] % p * InverseMod (fact [r % p], p - 2, p) % p * InverseMod (fact [n % p - r % p], p - 2, p) % p);
        ans %= p;
        n /= p;
        r /= p;
    }

    return ans;
}

/* Lucas theorem is used when modulus p is a prime number and values of n and r
are big (like >= 10 ^ 9)*/
