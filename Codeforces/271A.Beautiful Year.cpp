#include<bits/stdc++.h>
using namespace std;
 
bool vis[10];
 
bool isunique ( int y )
{
	memset(vis,0,sizeof vis);
	while(y)
	{
		if ( vis[ y%10 ] ) return 0 ;
		vis[y%10]=1;
		y/=10;
	}
	return 1;
}
 
int main()
{
    int n ;
	scanf("%d",&n);
	bool f=0;
	for(int i=n+1 ; !f ; i++)
	{
		if ( isunique(i) )
		{
			printf("%d\n",i);
			f=1;
		}
	}
}