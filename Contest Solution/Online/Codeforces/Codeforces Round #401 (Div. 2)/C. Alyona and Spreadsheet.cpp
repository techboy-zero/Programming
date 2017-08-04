#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5 + 7;
vector <int> vr [MAX];
vector <int> val [MAX];
vector <int> sum [MAX];

int main () {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int num;
                cin >> num;
                vr [i].push_back (num);
                sum [i].push_back (0);
                if (!i) {
                    val [i].push_back (0);
                } else {
                    if (vr [i][j] >= vr [i - 1][j]) val [i].push_back (1);
                    else val [i].push_back (-1);
                    sum [i][j] += sum [i - 1][j];
                }

            }
        }


    }
    return 0;
}
