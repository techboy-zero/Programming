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

#define sqr(x) (x*x)
#define cube(x) (x*x*x)

using namespace std;

char prince[21][21];
int cnt,m,n;
int direction_r[]={0,0,1,-1};
int direction_c[]={1,-1,0,0};

bool validity(int r,int c)
{
    if (r<0 || r>=m)        return false;
    if (c<0 || c>=n)        return false;
    if (prince[r][c]=='#')  return false;

    return true;
}

void dfs(int i,int j)
{
    prince[i][j]='#';
    cnt++;

    for (int k=0; k<4; k++)
        if (validity(i+direction_r[k],j+direction_c[k]))
            dfs(i+direction_r[k],j+direction_c[k]);
}

int main()
{
    int t;

    cin>>t;

    for (int i=1; i<=t; i++)
    {
        bool stat=true;

        cin>>n>>m;

        for (int j=0; j<m; j++)
            cin>>prince[j];

        for (int j=0; j<m; j++)
        {
            for (int k=0; k<n; k++)
                if (prince[j][k]=='@')
                {
                    cnt=0;
                    dfs(j,k);
                    stat=false;
                    break;
                }

            if (!stat)  break;
        }

        cout<<"Case "<<i<<": "<<cnt<<endl;
    }

    return 0;
}
