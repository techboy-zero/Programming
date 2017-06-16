
const int MAX = 1e7 + 7;
const int MAXN = 1e3 + 7;
int minprime [MAX];

void setMinPrime(){
    memset (minprime, -1, sizeof minprime);
    for (int i = 2; i <= MAX; i++) {
        if(minprime [i] != -1) continue;
        for (int j = i; j <= MAX - 7 ; j += i) {
            if (minprime [j] == -1) minprime [j] = i;
        }
    }
}

int primefactor [MAXN];
int lenp;

void genPrimeFactors (int n) { //N > 1
    lenp = 0;
    while (minprime [n] != n){
        primefactor [lenp++] = minprime [n];
        n /= minprime [n];
    }
    primefactor [lenp++] = N;
}

int divisors [MAX], lend;

void findDivisors (int n) { //without 1
    genPrimeFactors (n);
    lend = 0;
    int previous = 0;

    for (int i = 0; i < lenp; i++) {
        int cnt = 0;
        if(!i || (primefactor [i] != primefactor [i - 1])){
            previous = 0;
            divisors [lend + cnt] = primefactor [i];
            ++cnt;
        }
        for (int j = previous; j < lend; j++) {
            divisors [lend + cnt] = divisors [j] * primefactor [i];
            ++cnt;
        }
        previous = lend;
        lend = lend + cnt;
    }
}
