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
typedef long long ll;

struct node {
    ll prop, sum;
}seg [300010];

int a [100010];

void Init (int node, int l, int r) {
    if (l == r) {
        seg [node].prop = -1;
        seg [node].sum = 0;
        return;
    }

    int mid = (l + r) / 2;
    int lft = 2 * node;
    int rght = lft + 1;

    Init (lft, l, mid);
    Init (rght, mid + 1, r);
    seg [node].sum = 0;
    seg [node].prop = -1;
}

void update (int node, int i, int j, int l, int r, ll v, ll prop) {
    if (l > j || r < i) {
        if (prop != -1) {
            seg [node].prop = prop;
            seg [node].sum = prop * (r - l + 1);
        }
        return;
    }

    if (l >= i && r <= j) {
        seg [node].prop = v;
        seg [node].sum = v * (r - l + 1);
        return;
    }

    int mid = (l + r) / 2;
    int lft = 2 * node;
    int rght = lft + 1;

    if (seg [node].prop != -1 && prop == -1) prop = seg [node].prop;
    update (lft, i, j, l, mid, v, prop);
    update (rght, i, j, mid + 1, r, v, prop);
    seg [node].prop = -1;
    seg [node].sum = seg [lft].sum + seg [rght].sum;
    return;
}

ll query (int node, int i, int j, int l, int r, ll carry) {
    if (l > j || r < i) return 0;
    if (l >= i && r <= j) {
        if (carry != -1) {
            seg [node].prop = carry;
            seg [node].sum = carry * (r - l + 1);
        }

        return seg [node].sum;
    }

    int mid = (l + r) / 2;
    int lft = 2 * node;
    int rght = lft + 1;

    if (seg [node].prop != -1 && carry == -1) carry = seg [node].prop;

    ll p1 = query (lft, i, j, l, mid, carry);
    ll p2 = query (rght, i, j, mid + 1, r, carry);

    return p1 + p2;
}

int main(){
    //freopen ("input.txt", "r", stdin);
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        int n, q;
        scanf ("%d %d", &n, &q);
        Init (1, 1, n);

        printf ("Case %d:\n", kase);
        while (q--) {
            int choice;
            scanf ("%d", &choice);

            if (choice == 1) {
                int i, j, v;
                scanf ("%d %d %d", &i, &j, &v);
                update (1, i + 1, j + 1, 1, n, v, seg [1].prop);
            }else {
                int i, j;
                scanf ("%d %d", &i, &j);
                ll total = query (1, i + 1, j + 1, 1, n, -1), denom = j - i + 1;
                ll g = __gcd (total, denom);
                total /= g;
                denom /= g;

                printf ("%lld", total);
                if (denom != 1) printf ("/%lld", denom);
                printf ("\n");
            }
        }
    }

    return 0;
}
