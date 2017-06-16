//BFS = Breadth first search
#define FOREACH(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); i++)
#define mset (a,v) memset (a, v, sizeof (a));

typedef long long ll;
const int MAX = 1000;

bool visit [MAX + 7][MAX + 7];
int cost [MAX + 7][MAX + 7];

queue <pair <int, int> > q;

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

void init (int startx, int starty) {
    mset (visit, false);
    cost [startx][starty] = 0;
    visit [startx][starty] = true;
    q.push (make_pair (startx, starty));
}

void BFS (int startx, int starty) {
    init (startx, starty);
    while (!q.empty ()) {
        int x = q.front ().first, y = q.front ().second;
        q.pop ();

        for (int i = 0; i < 8; i++) {
            int u = x + dr [i];
            int v = y + dc [i];

            if (is_valid (u, v)) {
                cost [u][v] = cost [x][y] + 1;
                q.push (make_pair (u, v));
                visit [u][v] = true;
            }
        }
    }
}

