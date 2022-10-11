//CodeChef Problem Code: CARVANS
#include <iostream>
using namespace std;
#define el "\n";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n,i,m,c;
	cin>>t;
	while(t--){
	    cin>>n; i=c=0;
		int *arr = new int[n];
		while(i<n){
			cin>>arr[i++];
		}
		m=arr[0]; i=c=1;
		while(i<n){
			if(arr[i]<=m){
				c++; m=arr[i];
			}
			i++;
		}
		cout<<c<<el;
	}
	return 0;
}
