#include<bits/stdc++.h>
#define f(i,n,p) for(int i=0;i<n;i++)
using namespace std;
int main()
{ios_base::sync_with_stdio(NULL);
cin.tie(NULL);cout.tie(NULL);
    int n,count1=0,count2=0,count3=0,count4=0;
    cin>>n;
    int a[n];
    f(i,n,p)
    {cin>>a[i];
    }
    f(i,n,p)
    {
        if(a[i]==1)
        {count1++;}
        else if (a[i]==2)
        {count2++;}
        else if (a[i]==3)
        {count3++;}
        else if (a[i]==4)
        {count4++;}
    }int total = count4 + count3 + count2/ 2;
    count1 -= count3;
    if (count2 % 2 == 1)
    {
        total += 1;
        count1 -= 2;
    }
    if (count1 > 0)
    {
        total += (count1 + 3) / 4;
    }cout<<total;
    return 0;
}