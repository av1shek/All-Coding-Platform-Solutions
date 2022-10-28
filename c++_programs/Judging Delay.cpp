#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int s[n],j[n];
	    for(int i=1;i<=n;i++){
	        cin>>s[i]>>j[i];
	    }
	    int count=0;
	    for(int i=1;i<=n;i++){
	        if(j[i]-s[i]>5) count++;
	        else continue;
	    }
	    cout<<count<<endl;
	}
	return 0;
}
