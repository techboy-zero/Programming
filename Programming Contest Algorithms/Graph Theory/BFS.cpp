//BFS = Breadth first search
#define FOREACH(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); i++)
#define mset (a,v) memset (a, v, sizeof (a));

typedef long long ll;
const int MAX = 1000;

vector <int> edges [MAX + 7];
queue <int> q;
bool visit [MAX + 7];
int cost [MAX + 7];

void BFS (int s) {
    mset (visit, false);
    cost [s] = 0;
    visit [s] = true;
    q.push (s);

    while (!q.empty ()) {
        int u = q.front ();
        q.pop ();

        FOREACH(v, edges [u]) {
            if (!visit [*v]) {
                cost [*v] = cost [u] + 1;
                q.push (*v);
                visit [*v] = true;
            }
        }
    }
}
