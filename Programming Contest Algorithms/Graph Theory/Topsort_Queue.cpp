
#define FOREACH(i, s) for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); i++)

const int MAX = 110;
queue <int> q;
vector <int> edges [MAX + 7], order;
int indegree [MAX + 7];

void topsort () {
    for (int i = 1; i <= MAX; i++)
        if (!indegree [i])          //if there are multiple starting node then any order can be valid
            q.push (i);

    while (!q.empty ()) {
        int u = q.front ();
        q.pop ();
        FOREACH (v, edges [u]) {
            indegree [*v]--;
            if (!indegree [v]) q.push (*v);
        }
        order.push_back (u);
    }

    //if size of vector order is not equal to total nodes then cycle is present in graph and topological sort is not possible
}
