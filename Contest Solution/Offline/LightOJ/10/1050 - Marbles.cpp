#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i!=s.end(); i++)

using namespace std;
typedef long long ll;

const int MAX = 500 + 7;
double cache [MAX][MAX][2];
bool visit [MAX][MAX][2];

double dp (int red, int blue, bool state) {
    if (!blue && !state) return 0;
    if (red + blue == 1 && blue) return 1;
    if (red + blue == 1 && red) return 0;

    double &ret = cache [red][blue][state];
    if (visit [red][blue][state]) return ret;
    visit [red][blue][state] = true;

    ret = 0;
    if (!state) ret = dp (red, blue - 1, true);
    else {
        double probred = red * 1.0 / (red + blue);
        double probblue = blue * 1.0 / (red + blue);

        if (red) ret += probred * dp (red - 1, blue, false);
        if (blue) ret += probblue * dp (red, blue - 1, false);
    }

    return ret;
}

int main () {
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int red, blue;
        cin >> red >> blue;
        printf ("Case %d: %.10lf\n", kase, dp (red, blue, true));
    }

    return 0;
}
