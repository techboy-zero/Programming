
typedef long long ll;
const int mx = 1e7;

int par [mx + 7], sz [mx + 7];

int FindParent (int x) {
    if (par [x] == x) return x;
    return par [x] = FindParent (par [x]);
}

bool InUnion (int x, int y) {
    return (FindParent (x) == FindParent (y));
}

void Init (int n) {
    for (int i = 1; i <= n; i++) {
        par [i] = i;
        sz [i] = 1;
    }
}

void MakeUnion (int x, int y) {
    int u = FindParent (x);
    int v = FindParent (y);

    if (sz [u] < sz [v]) swap (u, v);
    par [v] = u;
    sz [u] += sz [v];
}

/*Disjoint Set Union algo is also used in Kruskal's Minimum Spanning Tree*/
