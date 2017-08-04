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

struct point
{
    int x,y;

}start,home,p,q;

queue <point> mall;

int t,m,n,power[3];

int mark[21][21];
char grid[21][21];
bool check[21][21];

int dirrection_r[]={0,0,1,-1};
int dirrection_c[]={1,-1,0,0};

void homefinder(void)
{
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (grid[i][j]=='h')
            {
                home.x=i;
                home.y=j;

                return;
            }
}

inline bool validity(int i,int j)
{
    if (i<0 || i>=m)     return false;
    if (j<0 || j>=n)     return false;
    if (check[i][j])     return false;
    if (grid[i][j]=='m') return false;
    if (grid[i][j]=='#') return false;

    return true;
}

void bfs(void)
{
    mall.push(start);
    mark[start.x][start.y]=0;
    check[start.x][start.y]=true;

    while (!mall.empty())
    {
        p=mall.front();
        mall.pop();

        for (int i=0; i<4; i++)
        {
            q=p;

            q.x+=dirrection_r[i];
            q.y+=dirrection_c[i];

            if (validity(q.x,q.y))
            {
                mall.push(q);
                mark[q.x][q.y] = mark[p.x][p.y] + 1;
                check[q.x][q.y]=true;
            }
        }
    }
}

int main()
{
    cin>>t;

    for (int i=1; i<=t; i++)
    {
        cin>>m>>n;

        for (int j=0; j<m; j++)
            cin>>grid[j];

        homefinder();

        for (int j=0; j<m; j++)
            for (int k=0; k<n; k++)
                if (grid[j][k]>='a' && grid[j][k]<='c')
                {
                    memset(check,false,sizeof(check));

                    start.x=j;
                    start.y=k;

                    bfs();

                    power[ grid[j][k] - 'a'] = mark[home.x][home.y];
                }

        sort(power,power+3);

        printf("Case %d: %d\n",i,power[2]);
    }

    return 0;
}
