#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9
#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i!=s.end(); i++)

using namespace std;
typedef long long ll;
typedef long long ull;

const int MAXL = 20 + 7;
char str [MAXL];
int n;
int len;
int counter [MAXL];
ull fact [MAXL];

void pregen () {
    fact [0] = fact [1] = 1;
    for (int i = 2; i <= MAXL- 7; i++) {
        fact [i] = i * fact [i - 1];
    }
}

bool possible () {
    memset (counter, 0, sizeof counter);
    for (int i = 0; str [i]; i++) {
        counter [str [i] - 'a']++;
    }
    ull limit = fact [len];
    for (int i = 0; i < 26; i++) limit /= fact [counter [i]];
    return n <= limit;
}

ull calc (int f, int indx) {
    ull tot = fact [len - f - 1];
    for (int i = 0; i < 26; i++) {
        if (i == indx) tot /= fact [counter [i] - 1];
        else tot /= fact [counter [i]];
    }
    return tot;
}

int main () {
    pregen ();
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> str >> n;
        len = strlen (str);

        printf ("Case %d: ", kase);
        if (!possible ()) cout << "Impossible" << endl;
        else {
            for (int i = 0; i < len; i++) {
                ull previous = 0;
                ull temp = 0;
                for (int j = 0; j < 26; j++) {
                    if (!counter [j]) continue;
                    temp += calc (i, j);
                    //cout << temp << endl;

                    if (temp >= n) {
                        n -= previous;
                        str [i] = 'a' + j;
                        counter [j]--;
                        break;
                    }
                    previous = temp;
                }
            }

            cout << str << endl;
        }
    }
    return 0;
}
