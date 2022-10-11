#include<bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main()
{      
      int r; cin>>r;
       int x,y,x1,y1;
       cin>>x>>y>>x1>>y1;
       double d = sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
       int ans = d/(2*r);
       if (ans*2*r==d)
       {
         cout<<ans;
       }
       else cout<<ans+1;
       
     return 0;
}