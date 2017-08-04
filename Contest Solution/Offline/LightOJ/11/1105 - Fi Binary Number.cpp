#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i!=s.end(); i++)

using namespace std;
typedef long long ll;

const int MAXF = 50;
ll fibo [MAXF + 7];
ll sum [MAXF + 7];
int n;

queue <int> ans;

void preCalculation () {
    fibo [1] = fibo [2] = 1;
    for (int i = 3; i <= MAXF; i++) {
        fibo [i] = fibo [i - 1] + fibo [i - 2];
    }
    for (int i = 1; i <= MAXF; i++) {
        sum [i] = sum [i - 1] + fibo [i];
    }
    //cout << sum [MAXF] << endl;
}

void calculation () {
    int i = 1;
    while (sum [i] < n) i++;
    n -= sum [i - 1] + 1;

    ans.push (1);
    while (--i) {
        if (sum [i] >= n && sum [i - 1] < n) {
            n -= sum [i - 1] + 1;
            ans.push (1);
            continue;
        }
        ans.push (0);
    }
}

void output (int kase) {
    printf ("Case %d: ", kase);
    while (!ans.empty()) {
        cout << ans.front ();
        ans.pop ();
    }
    cout << endl;
}

int main () {
    preCalculation ();
#ifdef LOCAL
    freopen ("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> n;
        calculation ();
        output (kase);
    }

    return 0;
}
