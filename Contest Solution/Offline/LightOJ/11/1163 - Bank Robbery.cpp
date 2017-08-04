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

unsigned long long num;

int main()
{
    int t;

    cin>>t;

    for (int i=1; i<=t; i++)
    {
        cin>>num;

        cout<<"Case "<<i<<": ";

        if (num%9==0)   cout<<(num*10)/9-1<<" ";

        cout<<(num*10)/9<<endl;
    }

    return 0;
}
