#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

map <string, int> counter;

int main () {
    int t;
    cin >> t;

    for (int kase = 1; kase <= t; kase++) {
        int n, mx = 0;
        string most;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string word;
            cin >> word;
            counter [word]++;
            if (counter [word] > mx) {
                mx = counter [word];
                most = word;
            }
        }
        printf ("Case %d: ", kase);
        cout << most << endl;
        counter.clear ();
    }
    return 0;
}

