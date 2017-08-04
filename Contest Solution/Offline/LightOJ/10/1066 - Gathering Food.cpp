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

int t,n,cnt,in;

char grid[11][11],next;
int mark[11][11],total;
bool check[11][11];

int dirrection_r[]={0,0,1,-1};
int dirrection_c[]={1,-1,0,0};

struct point
{
    int x,y;
}start,end,p,q,array[30];

queue <point> forest;

inline bool validity(int i,int j)
{
    if (i<0 || i>=n) return false;
    if (j<0 || j>=n) return false;
    if (check[i][j]) return false;

    if (grid[i][j]=='.')  return true;
    if (grid[i][j]==next) return true;

    return false;
}

void bfs(void)
{
    forest.push(start);
    mark[start.x][start.y]=0;
    check[start.x][start.y]=true;

    while (!forest.empty())
    {
        p=forest.front();
        forest.pop();

        for (int i=0; i<4; i++)
        {
            q=p;

            q.x+=dirrection_r[i];
            q.y+=dirrection_c[i];

            if (validity(q.x,q.y))
            {
                forest.push(q);
                mark[q.x][q.y] = mark[p.x][p.y] + 1;
                check[q.x][q.y]=true;

                if (grid[q.x][q.y]==next)
                {
                    total+=mark[q.x][q.y];
                    return;
                }
            }
        }
    }
}

void visit_list(void)
{
    for (int j=0; j<n; j++)
        for (int k=0; k<n; k++)
            if (grid[j][k]>='A' && grid[j][k]<='Z')
            {
                cnt++;
                array[ grid[j][k] - 'A' ].x=j;
                array[ grid[j][k] - 'A' ].y=k;
            }
}

void clean(void)
{
    memset(check,false,sizeof(check));

    while (!forest.empty())
        forest.pop();
}

int main()
{
    cin>>t;

    for (int i=1; i<=t; i++)
    {
        cin>>n;

        for (int j=0; j<n; j++)
            cin>>grid[j];

        cnt=total=0;

        visit_list();

        cnt--;
        in=cnt;

        for (int j=0; j<in; j++)
        {
            clean();

            next=j+1+'A';
            start.x=array[j].x;
            start.y=array[j].y;

            bfs();

            if (check[array[j+1].x][array[j+1].y]) cnt--;
            grid[start.x][start.y]='.';
        }

        if (!cnt) printf("Case %d: %d\n",i,total);
        else      printf("Case %d: Impossible\n",i);
    }

    return 0;
}
