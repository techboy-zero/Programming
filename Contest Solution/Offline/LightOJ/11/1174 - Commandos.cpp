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

int adj_mat[110][110];

void Floyd_warshall(int n) {

    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                adj_mat[i][j]=min(adj_mat[i][j],adj_mat[i][k]+adj_mat[k][j]);
}

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    for (int kase=1; kase<=t; kase++){
        int n,r,mx=0,s,d,nod1,nod2;
        cin>>n>>r;

        for (int i=0; i<n; i++){
            fill(adj_mat[i],adj_mat[i]+n,INF);
            adj_mat[i][i]=0;
        }

        for (int i=1; i<=r; i++) {
            cin>>nod1>>nod2;
            adj_mat[nod1][nod2]=adj_mat[nod2][nod1]=1;
        }

        cin>>s>>d;
        Floyd_warshall(n);

        for (int i=0; i<n; i++)
            if (mx<adj_mat[s][i]+adj_mat[i][d])
                mx=adj_mat[s][i]+adj_mat[i][d];

        printf("Case %d: %d\n",kase,mx);
    }

    return 0;
}
