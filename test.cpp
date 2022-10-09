#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

char get(int i)
{
    return 'a' + i - 1;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int i = n - 1;
    string res;
    while (i >= 0)
    {
        if (s[i] != '0')
        {
            res += get(s[i] - '0');
            i--;
        }
        else
        {
            res += get(stoi(s.substr(i - 2, 2)));
            i -= 3;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
}

int main()
{
    int t = 1;
    cin >> t;
    for (int it = 0; it < t; ++it)
    {
        solve();
    }
    return 0;
}