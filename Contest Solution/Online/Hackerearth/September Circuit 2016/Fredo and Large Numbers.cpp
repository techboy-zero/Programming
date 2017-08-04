#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e6 + 7;
map <ll, int> serial;
map <int, ll> retrieval;
int counter [MAXN];
vector <pair <int, int> > v, vx;

void reset () {
    v.clear ();
    vx.clear ();
    serial.clear ();
    retrieval.clear ();
}

int main () {
    int n;
    while (scanf ("%d", &n) != EOF) {
        int cnt = 0;
        reset ();
        for (int i = 0; i < n; i++) {
            ll num;
            scanf ("%lld", &num);
            if (serial.find (num) == serial.end ()) {
                serial [num] = ++cnt;
                retrieval [cnt] = num;
                counter [cnt] = 1;
            } else {
                counter [serial [num]]++;
            }
        }

        for (int i = 1; i <= cnt; i++) {
            v.push_back (make_pair (counter [i], i));
            vx.push_back (make_pair (counter [i], i));
        }
        sort (v.begin (), v.end ());
        sort (vx.begin (), vx.end ());

        int q, sz = v.size (), mn = INF;
        scanf ("%d", &q);

        for (int i = sz - 1; i >= 0; i--) {
            mn = min (mn, v [i].second);
            v [i].second = mn;
        }

        for (int i = 1; i <= q; i++) {
            int type;
            ll f;
            scanf ("%d %lld", &type, &f);
            if (f > MAXN - 7) {
                printf ("0\n");
                continue;
            }

            if (!type) {
                int temp1 = (lower_bound (v.begin (), v.end (), make_pair ((int) f, 0)) - v.begin ());
                ll ans = 0;
                if (temp1 != sz) {
                    ans = retrieval [v [temp1].second];
                }
                printf ("%lld\n", ans);
            } else {
                int temp1 = (lower_bound (vx.begin (), vx.end (), make_pair ((int) f, 0)) - vx.begin ());
                ll ans = 0;
                if (temp1 != sz && vx [temp1].first == f) {
                    ans = retrieval [vx [temp1].second];
                }
                printf ("%lld\n", ans);
            }
        }
    }
    return 0;
}

