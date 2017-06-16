
#define FOREACH(i, s) for (__typeof((s).end()) i = (s).begin(); i != (s).end(); i++)
const int MAX = 110;
vector <int> edges [MAX + 7], order;
bool visit [MAX + 7];

void topsort (int u) {
    visit [u] = true;
    FOREACH (v, edges [u])
        if (!visit [*v])
            topsort (*v);
    order.push_back (u);
}

int main () {

    for (int i = 1; i <= MAX; i++)
        if (!visit [i])
            topsort (i);

    return 0;
}
