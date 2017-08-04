#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 7;
char str1 [MAXN], str2 [MAXN];
int counter [30];

int main () {
    #ifdef TECHBOY
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> str1;
        cin >> str2;
        int len1 = strlen (str1);
        int len2 = strlen (str2);
        int mid1 = len1 / 2;
        int mid2 = len2 / 2;
        memset (counter, -1, sizeof counter);


        for (int i = mid2, j = mid2 + 1; i >= 0 || j < len2; i--,j++) {
            if (i >= 0) {
                char ch = str2 [i];
                if (counter [ch - 'A'] == -1) {
                    counter [ch - 'A'] = i;
                }
            }
            if (j < len2) {
                char ch = str2 [j];
                if (counter [ch - 'A'] == -1) {
                    counter [ch - 'A'] = j;
                }
            }
        }
        int mn = INF;
        for (int i = 0; str1 [i]; i++) {
            char ch = str1 [i];
            if (counter [ch - 'A'] != -1) {
                int curr = 0;
                curr += abs (i - counter [ch - 'A']);
                curr += abs (counter [ch - 'A'] - (len1 - i - 1));
                curr += abs ((len1 - i - 1) - (len2 - counter [ch - 'A'] - 1));
                curr += abs ((len2 - counter [ch - 'A'] - 1) - i);

                mn = min (mn, curr);
            }
        }

        cout << mn << endl;
    }

    return 0;
}

