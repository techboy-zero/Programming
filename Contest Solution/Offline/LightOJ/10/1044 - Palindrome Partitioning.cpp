#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e3 + 7;

char str [MAX];
bool paline [MAX][MAX];
bool check [MAX][MAX];
int cache [MAX][MAX];

int minPalinedrome (int i, int j) {
    if (!str [j]) {
        if (paline [i][j - 1]) return 1;
        return INF;
    }
    int &ret = cache [i][j];
    if (check [i][j]) return ret;
    check [i][j] = true;

    ret = INF;
    if (paline [i][j]) ret = minPalinedrome (j + 1, j + 1) + 1;
    ret = min (ret, minPalinedrome (i, j + 1));

    return ret;
}

void substringPalinedrome () {
    for (int i = 0; str [i]; i++) {
        int j = i, k = i;
        bool stat = true;
        while (j >= 0 && str [k]) {
            if (str [j] != str [k]) stat = false;
            paline [j][k] = stat;
            j--; k++;
        }

        j = i;
        k = i + 1;
        stat = true;
        while (j >= 0 && str [k]) {
            if (str [j] != str [k]) stat = false;
            paline [j][k] = stat;
            j--; k++;
        }
    }
}

int main () {
    #ifdef TECHBOY
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> str;
        substringPalinedrome ();
        memset (check, false, sizeof check);
        int ans = minPalinedrome (0, 0);
        printf ("Case %d: %d\n", kase, ans);
    }

    return 0;
}

