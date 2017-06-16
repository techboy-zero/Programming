//DFS = Depth First Search

#define FOREACH(i, s) for (__typeof((s).end()) i = (s).begin (); i != (s).end (); i++)

typedef long long ll;
const int MAX = 1000;
bool visit [MAX + 7];

vector <int> edges [MAX + 7];

void dfs (int u) {
    visit [u] = true;

    FOREACH(v, edges [u])
        if (!visit [*v])
            dfs (*v);
}
