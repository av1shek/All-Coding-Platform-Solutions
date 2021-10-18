#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int k,n,m;
	cin>>k>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	vector<int> ans;
	int i=0,j=0;
	while(i<n&&j<m)
	{
		
		if(a[i]==0) 
		{
			//cout<<i<<' ';
			ans.push_back(a[i]);
			i++;
			k++;
		}
		else if(b[j]==0)
		{
			//cout<<j<<' ';
			ans.push_back(b[j]);
			j++;
			k++;
		}
		else
		{
			if(a[i]<=b[j])
			{
				//cout<<i<<' ';
				if(a[i]>k) 
				{
					cout<<-1<<"\n";
					return;
				}
				ans.push_back(a[i]);
				i++;
			}
			else
			{
				//cout<<j<<' ';
				if(b[j]>k) 
				{
					cout<<-1<<"\n";
					return;
				}
				ans.push_back(b[j]);
				j++;
			}
		}
	}
	while(i<n)
	{
		if(a[i]==0)
		{
			k++;
			ans.push_back(a[i]);
			i++;
		}
		else if(a[i]>k) 
		{
			cout<<-1<<"\n";
			return;
		}
		else
		{
			ans.push_back(a[i]);
			i++;
		}
	}
	while(j<m)
	{
		if(b[j]==0)
		{
			k++;
			ans.push_back(b[j]);
			j++;
		}
		else if(b[j]>k) 
		{
			cout<<-1<<"\n";
			return;
		}
		else
		{
			ans.push_back(b[j]);
			j++;
		}
	}
	for(auto i: ans) cout<<i<<" ";
	cout<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}
