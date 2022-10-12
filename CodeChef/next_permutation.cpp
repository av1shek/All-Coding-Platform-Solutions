#include <bits/stdc++.h>
using namespace std;

void next_permutation (vector<int> &nums) {
	int n = nums.size(), indx1 = -1, indx2 = -1;
	
	for (int i = n - 2; i >= 0; i--) {
		if(nums[i] < nums[i + 1]) {
			indx1 = i;
			break;
		}
	}
	
	if (indx1 == -1) {
		reverse(nums.begin(), nums.end());
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			 if(nums[i] > nums[indx1]) {
				indx2 = i;
				break;
			 }
		 }
		 
		swap(nums[indx1], nums[indx2]);
	
		sort(nums.begin() + indx1 + 1, nums.end());
	}
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	next_permutation (a);
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
    return 0;
} 
