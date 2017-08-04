#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

//{{{ ************[  Floating points     ]************
#define ABS(x)          (((x) < 0) ? - (x) : (x))
#define ZERO(x)         (ABS (x) < EPS)
#define EQUAL(x, y)     (ZERO ((x) - (y)))

#define sqr(x)        (x*x)
#define cube(x)        (x*x*x)
#define INF            (int)1e9
#define EPS            1e-9

#define mset(a,v)    memset(a, v, sizeof(a))

using namespace std;

int n, m;
int dr [] = {0, 0, 1, -1};
int dc [] = {1, -1, 0, 0};

bool bi [25][25];
bool visit [25][25];
char grid [25][25];

struct parent {
    int x, y;
}par [25][25];

bool is_valid (int i, int j) {
    if (i < 0 || i >= n) return false;
    if (j < 0 || j >= m) return false;
    if (visit [i][j])   return false;
    return (grid [i][j] == '*');
}

bool gold_check (int i, int j) {
    if (i < 0 || i >= n) return false;
    if (j < 0 || j >= m) return false;
    return (grid [i][j] == '*');
}

bool par_check (int i, int j) { return (par [i][j].x == -1 && par [i][j].y == -1); }

void Bicolor (int i, int j, bool color) {
    visit [i][j] = true;
    bi [i][j] = color;

    for (int k = 0; k < 4; k++) {
        int u = dr [k] + i,v = dc [k] + j;
        if (is_valid (u, v)) Bicolor (u, v, !color);
    }
}

bool Kuhn (int i, int j) {
    if (visit [i][j]) return false;
    visit [i][j] = true;

    for (int k = 0; k < 4; k++) {
        int u = dr [k] + i,v = dc [k] + j;

        if ( gold_check (u, v) && ( par_check (u, v) || Kuhn (par [u][v].x, par [u][v].y)) ) {
            par [u][v].x = i;
            par [u][v].y = j;
            return true;
        }
    }

    return false;
}

void Init () {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            par [i][j].x = par [i][j].y = -1;
}

void Bipartite_Matching () {
    Init ();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (bi [i][j]) {
                mset (visit, false);
                bool t = Kuhn (i, j);
            }
    }
}

int main(){
    int t;
    cin>>t;

    for (int kase = 1; kase <= t; kase++) {
        cin>>n>>m;
        for (int i = 0; i < n; i++)
            cin>>grid [i];

        mset (visit, false);
        mset (bi, false);
        int gold = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visit [i][j] && gold_check(i, j))
                    Bicolor (i, j, true);
                if (grid [i][j] == '*')
                    gold++;
            }
        }

        Bipartite_Matching ();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if (par [i][j].x != -1 && par [i][j].y != -1)
                    gold--;
        }

        printf ("Case %d: %d\n", kase, gold);
    }

    return 0;
}
