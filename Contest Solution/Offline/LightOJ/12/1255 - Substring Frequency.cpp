#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define FOREACH(i,s) for(__typeof((s).end()) i = (s).begin(); i != (s).end(); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e6 + 7;
char pat [MAX], str [MAX];
int pi [MAX], len;
vector <int> occurance;

void failure () {
    int i, shift = 0;
    for (i = 2; pat [i - 1]; ++i) {
        while (shift > 0 && pat [shift] != pat [i - 1]) shift = pi [shift];
        pi [i] = shift += (pat [shift] == pat [i - 1]);
    }
}

int KMP () {
    failure ();
    int i, shift = 0;
    occurance.clear ();

    for (i = 0; str [i]; ++i) {
        while (shift > 0 && pat [shift] != str [i]) shift = pi [shift];
        if (pat [shift] == str [i]) ++shift;
        if (shift == len) {
            occurance.push_back (i - len + 1);
            shift = pi [shift];
        }
    }
    return occurance.size ();
}

int main () {
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif // LOCAL
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%s %s", &str, &pat);
        len = strlen (pat);
        printf ("Case %d: %d\n", kase, KMP ());
    }

    return 0;
}
