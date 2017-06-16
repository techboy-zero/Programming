
#define FOREACH(i, s) for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); i++)

const int MAX = 110, INF = (int) 1e9;
priority_queue < pair <int, int> > pq;
vector < pair <int, int> > edges [MAX + 7];
int cost [MAX + 7];

void Init (int start) {
    for (int i = 1; i <= MAX; i++)
        cost [i] = INF;
    cost [start] = 0;
}

void Dijkstra (int start) {
    Init (start);
    pq.push (make_pair (0, start));
    while (!pq.empty ()) {
        int u = pq.top ().second, curr = -pq.top ().first, sz = edges [u].size ();
        pq.pop();
        if (curr > cost [u]) continue;

        for (int i = 0; i < sz; i++) {
            int v = edges [u][i].first, c = edges [u][i].second;
            if (cost [v] > cost [u] + c) {
                cost [v] = cost [u] + c;
                pq.push (make_pair (-cost [v], v));
            }
        }
    }
}
