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
#define INF 999999999
#define MOD 100000007

using namespace std;

int n,m,q,cnt;
char grid[510][510];
int memo[510][510];
bool visit[510][510],setcourse[510][510][4];

int d_r[]={0,0,1,-1};
int d_c[]={1,-1,0,0};

bool is_valid(int i,int j){
    if (i<0 || i>=n) return false;
    if (j<0 || j>=m) return false;
    if (grid[i][j]=='#') return false;

    return !(visit[i][j]);
}

void DFS(int x,int y) {
    visit[x][y]=true;
    if (grid[x][y]=='C') cnt++;

    for (int i=0; i<4; i++){
        int u=x+d_r[i],v=y+d_c[i];
        if (is_valid(u,v)) {
            setcourse[x][y][i]=true;
            DFS(u,v);
        }
    }
}

void Set_mark(int x,int y) {
    memo[x][y]=cnt;

    for (int i=0; i<4; i++)
        if (setcourse[x][y][i]){
            int u=x+d_r[i],v=y+d_c[i];
            Set_mark(u,v);
        }
}

void Set_zero(){
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (grid[i][j]=='#'){
                visit[i][j]=true;
                memo[i][j]=0;
            }
}

int main() {
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);

    for (int kase=1; kase<=t; kase++) {
        scanf("%d %d %d",&n,&m,&q);
        memset(visit,false,sizeof(visit));
        memset(setcourse,false,sizeof(setcourse));
        for (int i=0; i<n; i++)
            scanf("%s",grid[i]);

        Set_zero();

        printf("Case %d:\n",kase);
        for (int i=0; i<q; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            x--; y--;
            if (visit[x][y]) printf("%d\n",memo[x][y]);
            else {
                cnt=0;
                DFS(x,y);
                Set_mark(x,y);
                printf("%d\n",memo[x][y]);
            }
        }
    }

    return 0;
}
