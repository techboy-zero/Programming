#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5 + 7;

struct parade {
    int l, r;
} army [MAX];

int n;
int totalleft, totalright;

int main () {
    while (cin >> n) {
        totalleft = totalright = 0;
        for (int i = 1; i <= n; i++) {
            cin >> army [i].l >> army [i].r;
            totalleft += army [i].l;
            totalright += army [i].r;
        }
        int mx = abs (totalleft - totalright);
        int mxindx = 0;
        for (int i = 1; i <= n; i++) {
            int templeft = totalleft;
            int tempright = totalright;
            templeft = templeft - army [i].l + army [i].r;
            tempright = tempright + army [i].l - army [i].r;

            if (abs (templeft - tempright) > mx) {
                mx = abs (templeft - tempright);
                mxindx = i;
            }
        }
        cout << mxindx << endl;
    }
    return 0;
}

