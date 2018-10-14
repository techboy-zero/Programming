#include <bits/stdc++.h>

#define FOREACH(i,s) for(__typeof(s.end()) i = s.begin(); i != s.end(); ++i)

#define EPS 1e-8
#define INF 1e8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 2e5 + 7;
ll cumsum[MAX];

int main () {
    int n, k;

    while (cin >> n >> k) {
        memset(cumsum, 0, sizeof cumsum);
        int height, minheight = MAX, maxheight = 0;
        for (int i = 0; i < n; i++) {
            cin >> height;
            cumsum[height]++;
            minheight = min(minheight, height);
            maxheight = max(maxheight, height);
        }

        for (int i = maxheight - 1; i >= minheight; i--) {
            cumsum [i] += cumsum[i + 1];
        }

        ll block = 0;
        int cut = 0;
        for (int i = maxheight - 1; i >= minheight; i--) {
            if (block + cumsum[i + 1] > k) {
                block = 0;
                cut++;
            }
            block += cumsum[i + 1];
        }
        if (block > 0) {
            cut++;
        }
        cout << cut << endl;
    }
    return 0;
}

