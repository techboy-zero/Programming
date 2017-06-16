typedef long long ll;

const int MAX = 1000;
ll cache [MAX + 5][MAX + 5];
bool visit [MAX + 5][MAX + 5];

ll stirlingFirst (int n, int k) {
    if (n == k) return 1;
    if (!k) return 0;
    ll &ret = cache [n][k];
    if (visit [n][k]) return ret;
    visit [n][k] = true;

    ret = stirlingFirst (n - 1, k - 1);
    ret += stirlingFirst (n - 1, k) * (n - 1);

    return ret;
}

