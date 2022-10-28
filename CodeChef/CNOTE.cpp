#include <iostream>

using namespace std;

int main()
{

    int T,x,y,k,n,p,c;
    cin>>T;

    while(T>0)
    {
        cin>>x>>y>>k>>n;

        x=x-y;

        bool luck = false;
        for(int i =0;i<n;i++)
        {
            cin>>p>>c;
            if(x<=p&&k>=c)
             luck = true;
        }

        if(luck)
            cout<<"LuckyChef\n";
        else
            cout<<"UnluckyChef\n";

        T--;

    }
    return 0;
}
