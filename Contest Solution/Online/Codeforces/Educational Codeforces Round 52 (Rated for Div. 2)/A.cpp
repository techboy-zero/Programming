#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main () {
    ll t, s, a, b, c;
    cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        cin >> s >> a >> b >> c;
        ll choco = 0;
        choco += s / c;
        choco += (choco / a) * b;
        cout << choco << endl;
    }
    return 0;
}

