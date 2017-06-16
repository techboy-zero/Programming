#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-8
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1e3 + 7;

int n;
int partner1 [MAX];
int partner2 [MAX];
int choice1 [MAX][MAX];
int choice2 [MAX][MAX];
int prefer1 [MAX][MAX];
int prefer2 [MAX][MAX];

queue <int> unmarried;

void Init () {
    memset (partner1, -1, sizeof (partner1));
    memset (partner2, -1, sizeof (partner1));
    for (int i = 1; i <= n; i++) {
        unmarried.push (i);
    }
}

void stableMarriage () {
    while (!unmarried.empty ()) {
        int person1 = unmarried.front ();
        unmarried.pop ();
        for (int i = 1; i <= n; i++) {
            int person2 = choice1 [person1][i];
            if (person2 != -1) {
                int current = partner2 [person2];
                if (current != -1 && prefer2 [person2][current] > prefer2 [person2][person1]) {
                    unmarried.push (current);
                    current = partner1 [current] = -1;
                }
                choice1 [person1][i] = -1;
                if (current == -1) {
                    partner2 [person2] = person1;
                    partner1 [person1] = person2;
                    break;
                }
            }
        }
    }
}
