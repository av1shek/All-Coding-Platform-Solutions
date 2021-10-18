#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
 
	while (t--)
	{
		int h, w;
		cin >> h >> w;
		vector<vector<int>> table(h, vector<int>(w));
		for (int i = 0; i < w; i++)
		{
			if (i % 2 == 0)
				table[0][i] = table[h - 1][i] = 1;
		}
		for (int i = 2; i < h - 2; i++)
		{
			if (i % 2 == 0)
				table[i][0] = 1;
			if (i % 2 == 0)
				table[i][w - 1] = 1;
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
				cout << table[i][j];
			cout << endl;
		}
		cout << endl;
	}
}
