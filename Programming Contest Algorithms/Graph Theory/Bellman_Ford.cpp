
#define INF 1e9

typedef long long ll;
const int MAX_E = 1000, MAX_N = 100;

struct edges {
    int x, y, c;
}e [MAX_E + 10];

int cost [MAX_N + 10], par [MAX_N + 10];

void Init (int start) {
    for (int i = 1; i <= MAX_N; i++) {
        cost [i] = INF;
        par [i] = -1;
    }
    cost [start] = 0;
    par [start] = start;
}

void bellmanFord (int start) {
    Init (int start);

    for (int i = 1; i < MAX_N; i++) {
        bool update = false;
        for (int j = 1; j <= MAX_E; j++) {
            int u = e [j].x, v = e [j].y;
            if (cost [v] > cost [u] + e [j].c) {
                cost [v] = cost [u] + e [j].c;
                par [v] = u;
                update = true;
            }
        }
        if (!update) break;
    }
}

/*Bellman ford algorithm is also used to detect negative cycle in a graph. We have to
run the outer loop equal to MAX_N and if we find update at the Nth time then the
graph has a negative cycle.
*/
