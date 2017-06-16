/*
if n < 2,047, it is enough to test a = 2;
if n < 1,373,653, it is enough to test a = 2 and 3;
if n < 9,080,191, it is enough to test a = 31 and 73;
if n < 25,326,001, it is enough to test a = 2, 3, and 5;
if n < 4,759,123,141, it is enough to test a = 2, 7, and 61;
if n < 1,122,004,669,633, it is enough to test a = 2, 13, 23, and 1662803;
if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11;
if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13;
if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17;
if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.
*/

typedef long long ull;

ull check [] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

ull multiMod (ull n, ull m, ull mod) {
    if (!m) return 0;
    if (m == 1) return n % mod;

    if (m % 2) return (multiMod (n, m - 1, mod) + n) % mod;
    ull temp = multiMod (n, m >> 1, mod);
    return (temp + temp) % mod;
}

ull binaryExpo (ull n, ull p, ull mod) {
    if (p == 1) return n % mod;
    if (!p) return 1;
    if (p % 2) return multiMod (binaryExpo (n, p - 1, mod), n, mod);
    ull temp = binaryExpo (n, p >> 1, mod);
    return multiMod (temp, temp, mod);
}

bool millerRabin (ull p) {
    if (p < 2) return false;
    if (!(p & 1)) return (p == 2);

    ull d = p - 1;

    while (!(d & 1)) d >>= 1;
    for (int i = 0; i < 9; i++) {
        ull a = check [i], s = d;
        ull x = binaryExpo (a, d, p);

        while (s != p - 1 && x != 1 && x != p - 1) {
            s <<= 1;
            x = multiMod (x, x, p);
        }
        if (x != p - 1 && !(s & 1)) return false;
    }
    return true;
}

//http://en.wikipedia.org/wiki/Miller–Rabin_primality_test
