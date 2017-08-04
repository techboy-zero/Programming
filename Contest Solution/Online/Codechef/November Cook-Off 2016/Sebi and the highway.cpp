#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

double s, sg, fg, tsec, d;

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> s >> sg >> fg >> d >> tsec;
        double km = d * 50.0 / 1000;
        double truck = s + km / tsec * 3600;
        double d1 = fabs (sg - truck);
        double d2 = fabs (fg - truck);

        if (fabs (d1 - d2) < EPS) cout << "DRAW" << endl;
        else if (d1 + EPS < d2) cout << "SEBI" << endl;
        else cout << "FATHER" << endl;
    }

    return 0;
}

