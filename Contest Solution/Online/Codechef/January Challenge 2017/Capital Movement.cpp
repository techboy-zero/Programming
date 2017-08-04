#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 5e4 +7;

vector <int> edges [MAXN];
set <int> cost;
map <int, int> mark;

int population [MAXN];
int n;

void init () {
    for (int i = 1; i <= n; i++) {
        edges [i].clear ();
    }
    mark.clear ();
    cost.clear ();
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> n;
        init ();
        for (int i = 1; i <= n; i++) {
            cin >> population [i];
            cost.insert (population [i]);
            mark [population [i]] = i;
        }

        for (int i = 1; i < n; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            edges [n1].push_back (n2);
            edges [n2].push_back (n1);
        }

        for (int i = 1; i <= n; i++) {
            cost.erase (population [i]);
            FOREACH (j, edges [i]) {
                int v = *j;
                cost.erase (population [v]);
            }
            if (!cost.empty()) {
                cout << mark [*cost.rbegin()];
            } else cout << 0;

            cost.insert (population [i]);
            FOREACH (j, edges [i]) {
                int v = *j;
                cost.insert (population [v]);
            }

            if (i < n) cout << " ";
            else cout << endl;
        }
    }

    return 0;
}
