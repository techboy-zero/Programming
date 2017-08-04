#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e6 + 7;

char str [MAX];
int check [300];
set <char> pokemon;
int main () {
    int n;
    while (cin >> n) {
        cin >> str;
        int ans = INF;
        memset (check, -1, sizeof check);
        for (int i = 0; str [i]; i++) {
            if (check [str [i]] == -1) {
                ans = INF;
            }
            check [str [i]] = i;
            pokemon.insert (str [i]);
            int lo = INF, hi = -1;
            FOREACH (res, pokemon) {
                lo = min (lo, check [*res]);
                hi = max (hi, check [*res]);
            }
            ans = min(ans, (hi - lo + 1));
        }
        cout << ans << endl;
        pokemon.clear ();
    }
    return 0;
}
