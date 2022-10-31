#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int num;
    cout<< "Enter number: ";
    cin>>num;

    int ans = 0;
    int i = 0;


    while(num!=0)
    {
        int bit = num & 1;
        ans = (bit * pow(10, i)) + ans ;
        cout<<bit<<endl;
        
        num = num >> 1;
        i++;
    }

    cout<<ans;
}