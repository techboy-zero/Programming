#define MAXSIEVE 10000000
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 5000

char check [MAXSIEVE / 16 + 2];

inline bool isprime (int n) {
    int temp = n;
    n >>= 1;
    n &= 7;
    return a [temp >> 4] & (1 << n);
}

void sieve () {
    int i, j;
    memset (check, 255, sizeof check);
    a [0] = 0xFE;
    for(i = 1; i < MAXSQRT; i++) {
        if (a [i >> 3] & (1 << (i & 7))) { // >> 3 == /16 && (i & 7) == %16
            for(j = i + i + i + 1; j < MAXSIEVEHALF; j += i + i + 1) { //* takes more time than +
                check [j >> 3] &= ~(1 << (j & 7));
            }
        }
    }
}
