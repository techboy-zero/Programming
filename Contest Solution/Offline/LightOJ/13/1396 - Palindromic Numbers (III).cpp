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

char s [100010];

bool all9 (int len) {
    bool state = true;

    for (int i = 0; i < len; i++)
        if (s [i] != '9')
            state = false;

    if (state) {
        for (int i = 0; i <= len; i++)
            if (!i || i == len) printf("1");
            else                printf("0");
        printf("\n");
    }

    return state;
}

int main() {
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf("%s", &s);
        int len = strlen(s);

        printf("Case %d: ",kase);
        if (! all9(len)) {
            char s1 [100010];
            int p = len / 2 - !(len % 2);

            strcpy(s1, s);

            for (int i = 0; i <= p; i++)
                s1 [len - i - 1] = s [i];

            if (strcmp(s1,s) > 0) printf("%s\n", s1);
            else {
                for (int i = p; i >= 0; i--) {
                    if (s1 [i] < '9') {
                        s1 [i]++;
                        s1 [len - i - 1] = s1 [i];
                        break;
                    } else
                        s1 [i] = s1 [len - i - 1] = '0';
                }
                printf("%s\n", s1);
            }
        }
    }

    return 0;
}
