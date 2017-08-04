#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 3e2 + 7;

int n, k;
vector <int> id [MAXN];
int sz [MAXN];
bool neighbour [MAXN][MAXN];

void Init (int n) {
    for (int i = 1; i <= n; i++) {
        sz [i] = 0;
        id [i].clear ();
    }
    memset (neighbour, false, sizeof neighbour);
}

int main () {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    while (cin >> n >> k) {
        Init (n);
        for (int i = 1; i <= n; i++) {
            cin >> sz [i];
            for (int j = 0; j < sz [i]; j++) {
                int num;
                cin >> num;
                id [i].push_back (num);
            }
            sort (id [i].begin (), id [i].end ());
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int cnt = 0;
                for (int l = 0; l < sz [i]; l++) {
                    if (binary_search (id [j].begin (), id [j].end (), id [i][l])) {
                        cnt++;
                    }
                    if (cnt == k) {
                        neighbour [i][j] = true;
                        break;
                    }
                }
            }
        }
        neighbour [1][1] = true;

        queue <int> q;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (neighbour [1][i]) {
                q.push (i);
                cnt++;
            }
        }
        while (!q.empty ()) {
            int curr = q.front ();
            q.pop ();
            for (int i = 1; i <= n; i++) {
                if (neighbour [curr][i] && !neighbour [1][i]) {
                    neighbour [1][i] = true;
                    q.push (i);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
