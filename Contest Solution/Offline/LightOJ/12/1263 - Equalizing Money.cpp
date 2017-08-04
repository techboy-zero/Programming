#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

#define sqr(x) (x*x)
#define cube(x) (x*x*x)

using namespace std;

int t,n,m,node1,node2;
vector <int> edges[1001],selected;
bool check[1001];
int value[1001];
int total;

void dfs(int u)
{
    check[u]=true;
    total+=value[u];
    selected.push_back(u);

    int v=edges[u].size();

    for (int i=0; i<v; i++)
        if ( !check[edges[u][i]] )
            dfs(edges[u][i]);
}

void clean(void)
{
    for (int i=1; i<=n; i++)
        edges[i].clear();

    memset(check,false,sizeof(check));
}

int main()
{
    cin>>t;

    for (int i=1; i<=t; i++)
    {
        cin>>n>>m;

        for (int j=1; j<=n; j++)
            cin>>value[j];

        for (int j=0; j<m; j++)
        {
            cin>>node1>>node2;

            edges[node1].push_back(node2);
            edges[node2].push_back(node1);
        }

        bool state=true;

        for (int j=1; j<=n; j++)
            if (!check[j])
            {
                total=0;
                selected.clear();

                dfs(j);

                int size=selected.size();

                if (total%size)
                {
                    state=false;
                    break;
                }
                else
                {
                    for (int k=0; k<size; k++)
                        value[selected[k]]=total/size;
                }
            }

        printf("Case %d: ",i);

        if (!state) cout<<"No"<<endl;
        else
        {
            for (int i=1; i<n; i++)
                if (value[i]!=value[i+1])
                {
                    state=false;
                    break;
                }

            if (!state) cout<<"No"<<endl;
            else        cout<<"Yes"<<endl;
        }

        clean();
    }

    return 0;
}
