#include <bits/stdc++.h>
using namespace std;

int findWater(int heights[], int n) {
	int l[n], r[n], ans = 0;
	l[0] = heights[0];

	for (int i = 1; i < n; i++)
		l[i] = max(l[i-1], heights[i]);

	r[n - 1] = heights[n - 1];

	for (int i = n - 2; i >= 0; i--)
		r[i] = max(r[i+1], heights[i]);

	for (int i = 1; i < n-1; i++) {
        int temp=min(l[i-1],r[i+1]);
        if(temp > heights[i]) {
            ans += temp - heights[i];
        }
	}
	return ans;
}

int main() {
    int n;
    cin >> n;
    int heights[n] = {0};
    for(int i = 0; i < n; i++)
        cin >> heights[i];
    int ans = findWater(heights, n);
    cout << ans << endl;
	return 0;
}
