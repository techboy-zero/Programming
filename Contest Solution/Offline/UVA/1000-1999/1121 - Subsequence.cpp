#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;

int n, s;
int ar [MAX];

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

int main () {
    while (cin >> n >> s) {
        for (int i = 0; i < n; i++) cin >> ar [i];
        int ans = solve2 ();
        cout << ans << endl;
    }

    return 0;
}
