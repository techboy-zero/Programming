#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e2 + 7;

int n;
int paired [2 * MAX];
int choice [2 * MAX][2 * MAX];
int preference [2 * MAX][2 * MAX];

queue <int> job;

void Init () {
    memset (paired, -1, sizeof (int) * (2 * n + 1));
    for (int i = 1; i <= n; i++) {
        job.push (i);
    }
}

void stableMarriage () {
    while (!job.empty ()) {
        int candidate = job.front ();
        job.pop ();
        if (paired [candidate] == -1) {
            for (int company = 1; company <= n; company++) {
                int target = choice [candidate][company];
                if (target != -1) {
                    int curr = paired [target];
                    if (curr != -1 && preference [target][curr] > preference [target][candidate]) {
                        job.push (curr);
                        curr = paired [curr] = -1;
                    }
                    choice [candidate][company] = -1;
                    if (curr == -1) {
                        paired [target] = candidate;
                        paired [candidate] = target;
                        break;
                    }
                }
            }
        }
    }
}

int main () {
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%d", &n);
        Init ();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf ("%d", &choice [i][j]);
                preference [i][choice [i][j]] = j;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf ("%d", &choice [i + n][j]);
                preference [i + n][choice [i + n][j]] = j;
            }
        }

        stableMarriage ();
        printf ("Case %d:", kase);
        for (int i = 1; i <= n; i++) {
            printf (" (%d %d)", i, paired [i]);
        }
        printf ("\n");
    }

    return 0;
}
