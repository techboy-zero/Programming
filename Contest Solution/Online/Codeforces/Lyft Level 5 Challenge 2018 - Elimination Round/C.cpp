#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e5 + 7;

int pos[MAXN];
int val[MAXN];
bool bobWins[MAXN];

int main () {
    int n;
    while (cin >> n) {
        memset(bobWins, false, sizeof bobWins);
        for (int i = 1; i <= n; i++) {
            cin >> val [i];
            pos [val [i]] = i;
        }

        for (int value = n; value >= 1; value--) {
            int position = pos [value];
            bool willWin = true;

            for (int nxt = position + value; nxt <= n; nxt += value) {
                if (val [nxt] > value && bobWins[nxt]) {
                    willWin = false;
                    break;
                }
            }

            if (willWin) {
                for (int prv = position - value; prv >= 1; prv -= value) {
                    if (val [prv] > value && bobWins[prv]) {
                        willWin = false;
                        break;
                    }
                }
            }

            bobWins[position] = willWin;
        }

        for (int i = 1; i <= n; i++) {
            if (bobWins[i]) cout << "B";
            else cout << "A";
        }
        cout << endl;
    }
    return 0;
}

