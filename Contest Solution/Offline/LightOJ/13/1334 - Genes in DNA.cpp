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
int pi [MAX], val [MAX], len;
int occurance [MAX];
ll tot;

void failure () {
    int i, shift = 0;
    val [1] = 1;
    for (i = 2; pat [i - 1]; ++i) {
        while (shift > 0 && pat [shift] != pat [i - 1]) shift = pi [shift];
        if (pat [shift] == pat [i - 1]) shift++;
        pi [i] = shift;
        val [i] = val [pi [i]] + 1;
    }
}

void KMP () {
    failure ();
    int i, shift = 0;

    for (i = 0; str [i]; ++i) {
        while (shift > 0 && pat [shift] != str [i]) shift = pi [shift];
        if (pat [shift] == str [i]) ++shift;
        occurance [i] = val [shift];
        if (shift == len) {
            shift = pi [shift];
            occurance [i]--;
        }
        tot += (ll) occurance [i] * occurance [i + 1];
    }
}

int main () {
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif // LOCAL
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%s %s", &str, &pat);
        memset (occurance, 0, sizeof (occurance));
        tot = 0;
        len = strlen (pat);
        int len1 = strlen (str);

        KMP ();
        reverse (pat, pat + len);
        reverse (str, str + len1);
        reverse (occurance, occurance + len1);
        KMP ();

        printf ("Case %d: %lld\n", kase, tot);
    }

    return 0;
}
