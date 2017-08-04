#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 2e7 + 7;

ll resource [MAX];

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        memset (resource, -1, sizeof resource);
        int q;
        scanf ("%d", &q);

        for (int i = 0; i < q; i++) {
            ll pid;
            int rid, typ;
            scanf ("%d", &typ);
            if (typ == 1) {
                scanf ("%lld %d", &pid, &rid);
                if (resource [rid] == -1) {
                    printf ("Y\n");
                    resource [rid] = pid;
                } else {
                    printf ("N\n");
                }
            } else {
                scanf ("%d", &rid);
                if (resource [rid] == -1) {
                    printf ("F\n");
                } else {
                    printf ("%lld\n", resource [rid]);
                    resource [rid] = -1;
                }
            }

        }
    }

    return 0;
}

