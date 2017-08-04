#include <bits/stdc++.h>

#define INF 1e7
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXR = 10, MAXMASK = (1 << 8) + 7;
int row, col;
int mask [MAXR];
int cache [MAXR][MAXMASK][MAXMASK];
bool visit [MAXR][MAXMASK][MAXMASK];

int dp (int currrow, int currmask, int prevmask) {
    if (currrow >= row) {
        if (prevmask == (1 << col) - 1) return 0;
        return INF;
    }
    int &ret = cache [currrow][currmask][prevmask];
    if (visit [currrow][currmask][prevmask]) return ret;
    visit [currrow][currmask][prevmask] = true;
    ret = INF;

    for (int i = 0; i < (1 << col); i++) {
        int temprow [] = {prevmask, currmask, mask [currrow + 1]};
        int res = 0;
        for (int j = 0; j < col; j++) {
            if (i & (1 << j)) {
                res++;
                for (int k = 0; k < 3; k++) {
                    temprow [k] ^= (1 << j);
                    if (j < col - 1) temprow [k] ^= (1 << (j + 1));
                    if (j > 0) temprow [k] ^= (1 << (j - 1));
                }
            }
        }

        if (!currrow || (temprow [0] == (1 << col) - 1)) {
            ret = min (ret, res + dp (currrow + 1, temprow [2], temprow [1]));
        }
    }
    return ret;
}

void masking (int idx, char str []) {
    for (int i = 0; i < col; i++) {
        if (str [i] == '*') {
            mask [idx] |= (1 << i);
        }
    }
}

int main () {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int test;
    cin >> test;

    for (int kase = 1; kase <= test; kase++) {
        cin >> row >> col;
        char str [MAXR];
        memset (mask, 0, sizeof mask);
        for (int i = 0; i < row; i++) {
            cin >> str;
            masking (i, str);
        }
        memset (visit, false, sizeof visit);
        int ret = dp (0, mask [0], 0);
        printf ("Case %d: ", kase);
        if (ret >= INF) cout << "impossible" << endl;
        else cout << ret << endl;
    }

    return 0;
}
