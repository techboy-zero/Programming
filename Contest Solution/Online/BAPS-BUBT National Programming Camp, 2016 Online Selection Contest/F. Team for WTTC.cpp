#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 7;
int ar [MAXN];

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int m;
        scanf ("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf ("%d", &ar [i]);
        }
        sort (ar, ar + m);
        int a, b;
        scanf ("%d %d", &a, &b);
        ll cnt = 0;

        for (int i = 0; i < m; i++) {
            int temp = ar [i];
            if (temp > b) continue;
            for (int j = i; j < m; j++) {
                temp += ar [j];
                if (temp > b) continue;
                for (int k = j; k < m; k++) {
                    temp += ar [k];
                    if (temp > b) continue;
                    if (temp < a) {
                        int key = a - temp;
                        int temp1 = (lower_bound (ar, ar + m, key) - ar);
                        int temp2 = (lower_bound (ar, ar + m, b - temp + 1) - ar);
                        cnt += temp2 - temp1;
                    } else {
                        int temp2 = (lower_bound (ar, ar + m, b - temp + 1) - ar);
                        cnt += temp2;
                    }
                }
            }
        }

        printf ("Case %d: %lld\n", kase, cnt);
    }

    return 0;
}

