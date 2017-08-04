#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 2e9
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 2e2 + 7;

struct repair {
    int s, d;
} cars [MAXN];

int main () {
#ifdef TECHBOY
    freopen("input.txt", "r", stdin);
#endif

    int n;

    while (cin >> n) {
        cars [0].s = 0;
        cars [0].d = 1;
        for (int i = 1; i <= n; i++) {
            cin >> cars [i].s >> cars [i].d;
        }

        for (int i = 2; i <= n; i++) {
            bool possible = true;
            int currs = cars [i].s, curre = cars [i].d + currs - 1;
            for (int j = 1; j < i; j++) {
                int s = cars [j].s, e = cars [j].d + s - 1;
                if (currs >= s && currs <= e || curre >= s && curre <= e) {
                    possible = false;
                    break;
                } else if (s >= currs && s <= curre || e >= currs && e <= curre) {
                    possible = false;
                    break;
                }
            }

            if (!possible) {
                int news = INF;
                for (int j = 0; j <= i; j++) {
                    int temps = cars [j].s + cars [j].d;
                    int tempe = temps + cars [i].d - 1;
                    bool chang = true;

                    for (int k = 1; k < i; k++) {
                        int s = cars [k].s, e = cars [k].d + s - 1;
                        if (temps >= s && temps <= e || tempe >= s && tempe <= e) {
                            chang = false;
                            break;
                        } else if (s >= temps && s <= tempe || e >= temps && e <= tempe) {
                            chang = false;
                            break;
                        }
                    }

                    if (chang) {
                        news = min (news, temps);
                    }
                }

                cars [i].s = news;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << cars [i].s << " " << (cars [i].s + cars [i].d - 1) << endl;
        }
    }
    return 0;
}

