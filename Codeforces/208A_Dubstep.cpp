#include<bits/stdc++.h>
using namespace std;
int main()
{
string s;
int count=1;cin>>s;
for(int i=0;i<s.length();i++)
{
    if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B')
    {i+=2;
    if(!count)
    {cout<<" ";}continue;}
    else {cout<<s[i];count=0;}
    
}
 
    return 0;
}