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

int Ksat[31][31];
int cnt[31];

int main()
{
    int t,n,m,k,num;
    cin>>t;

    for (int i=1; i<=t; i++)
    {
        cin>>n>>m>>k;

        memset(cnt,0,sizeof(cnt));

        for (int j=1; j<=n; j++)
            for (int l=0; l<k; l++)
            {
                cin>>Ksat[j][l];

                if (Ksat[j][l]<0)    cnt[j]++;
            }

        int p;
        cin>>p;

        for (int j=1; j<=p; j++)
        {
            int choice;
            cin>>choice;

            for (int j=1; j<=n; j++)
                for (int l=0; l<k; l++)
                {
                    if (choice==Ksat[j][l])         cnt[j]++;
                    else if (choice==(-Ksat[j][l])) cnt[j]--;
                }
        }

        bool stat=true;

        for (int j=1; j<=n; j++)
            if (!cnt[j])
            {
                stat=false;
                break;
            }

        if (stat)   cout<<"Case "<<i<<": "<<"Yes"<<endl;
        else        cout<<"Case "<<i<<": "<<"No"<<endl;
    }

    return 0;
}
