#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll  N= 1e6+10;
ll dp1[N];
ll dp2[N];
ll dp3[N];
ll dp4[N];
ll M=1e9+7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp2[1]=1;
	dp2[2]=1;
			dp2[3]=2;
			dp2[4]=3;
			dp2[5]=4;
			dp2[6]=8;
			dp3[1]=0;
			dp3[2]=0;
			dp3[3]=0;
			dp3[4]=1;
			dp3[5]=1;
			dp3[6]=1;
			dp4[1]=0;
			dp4[2]=0;
			dp4[3]=1;
			dp4[4]=1;
			dp4[5]=1;
			dp4[6]=3;

			for(ll i=7;i<=1000000;i++)
			{
				dp2[i]=((((dp2[i-1]%M)+dp2[i-3]%M)%M)+(2*dp3[i-2])%M)%M;
				dp3[i]=((dp3[i-3]%M)+(dp4[i-1]%M))%M;
				dp4[i]=((dp2[i-3]%M)+(dp4[i-3]%M))%M;
			}
	ll t;
	cin>>t;
	while(t--)
	{
		ll k,n;
		cin>>k>>n;
		if(k==1)
		{
			if((n%3)==0)
			{
				cout<<1<<'\n';
			}
			else
			{
				cout<<0<<'\n';
			}
		}
		if(k>1)
		{
			dp1[1]=0;
			dp1[2]=1;
			dp1[3]=1;
			for(ll i=4;i<=n;i++)
			{
				dp1[i]=((dp1[i-2]%M)+(dp1[i-3]%M))%M;
			}
			if(k==2)
			{
				cout<<dp1[n]%M<<'\n';
			}
		}
		if(k==3)
		{
			
			cout<<dp2[n]%M<<'\n';
		}
	}
	return 0;
}
