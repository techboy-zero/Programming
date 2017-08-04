#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1e5 + 7;
char str [MAX];
stack <char> s;

int main () {
    #ifdef TECHBOY
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        cin >> str;
        bool possible = true;
        for (int i = 0; str [i]; i++) {
            if (str [i] == 'M') {
                if (!s.empty () && s.top () == 'E') {
                    s.pop ();
                    s.pop ();
                } else possible = false;
            } else if (str [i] == 'E') {
                if (!s.empty () && s.top () == 'I') {
                    s.push ('E');
                } else possible = false;
            } else {
                s.push ('I');
            }
            if (!possible) break;
        }
        if (!possible || !s.empty ()) cout << "No" << endl;
        else cout << "Yes" << endl;

        while (!s.empty ()) s.pop ();
    }
    return 0;
}

