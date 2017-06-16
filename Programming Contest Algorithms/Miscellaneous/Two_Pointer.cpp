
const int MAX = 1e5 + 7;
int ar [MAX], br [MAX];
int n, m, s;

/*find number of ways to form m by adding two values from two different arrays*/

void solve1 () {
    int ans = 0;
    int low = 0, high = n - 1;
    while(low < n) {
        while (ar [low] + br [high] > m && high > 0) high--;
        if (ar [low] + br [high] == m) ans++;
        low++;
    }
    return ans;
}

/*find minimum length of consecutive subsequence that have sum >= s*/

int solve2 () {
    int ans = n + 2;
    int low = 0, high = 0;
    ll sum = ar [0];
    while(high < n) {
        if(sum >= s) {
            ans = min (ans, high - low + 1);
        }
        if(sum >= s && low < high) {
            sum -= ar [low];
            low++;
        } else {
            ++high;
            if (high < n) sum += ar [high];
        }

    }
    if(ans ==  n + 2) ans = 0;
    return ans;
}
