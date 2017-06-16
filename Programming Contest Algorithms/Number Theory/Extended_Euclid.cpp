typedef long long ll;

ll gcd, x0, x1, y0, y1;

void extendedEuclid (ll a, ll b) {
    x0 = 1; x1 = 0; y0 = 0; y1 =1;
    ll q, r, m, n;
    gcd = a;
    while (b) {
        q = gcd / b; r = gcd % b;
        m = x0 - q * x1; n = y0 - q * y1;
        gcd = b; b = r; x0 = x1; y0 = y1; x1 = m; y1 = n;
    }
}

//http://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
