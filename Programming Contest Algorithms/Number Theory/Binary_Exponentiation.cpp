typedef long long ll;

ll binaryExpo (ll n, ll p, int mod) {
    if (!p) return 1;
    if (p == 1) return (n % mod);

    ll temp = binaryExpo (n, p >> 1, mod);
    temp = (temp * temp) % mod;
    if (p & 1) temp = (temp * n) % mod;
    return temp;
}

/* Binary Exponentiation Algorithm can be used to find inverse modulus
    of a number. In that case the modulus must be a prime number
    and the power must be equal to (that prime - 2).*/
