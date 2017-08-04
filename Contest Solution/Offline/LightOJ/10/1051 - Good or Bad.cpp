/* C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/* C++ STL */
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>

/* Macros */
#define EPS 1e-9
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 50, MAXN = 10;

bool cache [MAX + 7][2][MAXN];
bool visit [MAX + 7][2][MAXN];
bool bad;
char str [100];

bool dp (int pos, bool state, int mark) {
    if (pos < 0) return true;
    bool &ret = cache [pos][state][mark];
    if (visit [pos][state][mark]) return ret;
    visit [pos][state][mark] = true;

    ret = false;
    if (str [pos] == '?') {
        if (state) {
            if (mark < 4) ret |= dp (pos - 1, state, mark + 1);
            if (mark == 4) bad = true;
            ret |= dp (pos - 1, false, 1);
        } else {
            if (mark < 2) ret |= dp (pos - 1, state, mark + 1);
            if (mark == 2) bad = true;
            ret |= dp (pos - 1, true, 1);
        }
    } else {
        if (str [pos] == 'A' || str [pos] == 'E' || str [pos] == 'I' || str [pos] == 'O' || str [pos] == 'U') {
            if (state) ret |= dp (pos - 1, false, 1);
            else if (!state) {
                if (mark < 2)  ret |= dp (pos - 1, state, mark + 1);
                if (mark == 2) bad = true;
            }
        } else {
            if (!state) ret |= dp (pos - 1, true, 1);
            else if (state) {
                if (mark < 4) ret |= dp (pos - 1, state, mark + 1);
                if (mark == 4) bad = true;
            }
        }
    }
    return ret;
}

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> str;
        int len = strlen (str);
        bad = false;
        memset (visit, false, sizeof (visit));
        bool good = dp (len - 1, 0, 0);
        printf ("Case %d: ", kase);
        if (good) {
            if (bad) cout << "MIXED" << endl;
            else cout << "GOOD" << endl;
        } else cout << "BAD" << endl;
    }
    return 0;
}
