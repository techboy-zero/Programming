typedef long long ll;

const int MAX = 1000;
ll cache [MAX + 5][MAX + 5];
bool visit [MAX + 5][MAX + 5];

ll sterlingSecond (int n, int k) {
    if (k == 1 || n == k) return 1;
    ll &ret = cache [n][k];
    if (visit [n][k]) return ret;
    visit [n][k] = true;

    ret = sterlingSecond (n - 1, k - 1);
    ret += sterlingSecond (n - 1, k) * k;

    return ret;
}
