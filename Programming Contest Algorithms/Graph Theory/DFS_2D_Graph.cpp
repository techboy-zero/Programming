//DFS = Depth First Search

#define FOREACH(i, s) for (__typeof((s).end()) i = (s).begin (); i != (s).end (); i++)

typedef long long ll;
const int MAX = 1000;
bool visit [MAX + 7][MAX + 7];

//direction array to define possible moves. Usually it contains either 4 or 8 directions
int dr [] = {0, 1, 1, 1, 0, -1, -1, -1}; //row
int dc [] = {1, 1, 0, -1, -1, -1, 0, 1}; //column

bool is_valid (int i, int j) {
    if (i < 0 || i >= MAX) return false;
    if (j < 0 || j >= MAX) return false;
    if (visit [i][j]) return false;
    //other conditions according to the problem
    return true;
}

void dfs (int i, int j) {
    visit [i][j] = true;

    for (int k = 0; k < 8; k++) {
        int u = i + dr [k], v = j + dc [k];
        if (is_valid (u, v)) dfs (u, v);
    }
}

