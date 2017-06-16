
#define FOREACH(i, s) for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); i++)

const int MAX = 110, INF = (int) 1e9;
set < pair <int, int> > s;
vector < pair <int, int> > edges [MAX + 7];
int cost [MAX + 7];

void Init (int start) {
    for (int i = 1; i <= MAX; i++)
        cost [i] = INF;
    cost [start] = 0;
}

void Dijkstra (int start) {
    Init (start);
    s.insert (make_pair (0, start));
    while (!s.empty ()) {
        int u = s.begin () -> second, sz = edges [u].size ();
        s.erase (s.begin ());

        for (int i = 0; i < sz; i++) {
            int v = edges [u][i].first, c = edges [u][i].second;
            if (cost [v] > cost [u] + c) {
                s.erase (make_pair (cost [v], v));
                cost [v] = cost [u] + c;
                s.insert (make_pair (cost [v], v));
            }
        }
    }
}
