#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define int long long
#define vi vector<int>
#define vs vector<string>
#define nline "\n"
//#define double long double

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

void read(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
        cin >> a[i];
}

void read(vector<string> &a)
{
    for (int i = 0; i < a.size(); i++)
        cin >> a[i];
}

void print(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}

void print(vector<string> &a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}

int INF = 1e8;
int mod = 1000000007;

int binpow(int a, int r)
{
    if (r == 0)
        return 1;
    int ans = binpow(a, r / 2);
    ans = (ans * ans);
    if (r & 1)
        ans = (ans * a);
    return ans;
}

bool com(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}

bool vowel(char c)
{
    string s = "aeiouAEIOU";
    for (auto x : s)
    {
        if (x == c)
            return 1;
    }
    return 0;
}

// prime numbers seive
/*
vector<bool> isPrime(1000000 + 1, true); // set all of them to primes
void sieve(int n)
{
    isPrime[0] = isPrime[1] = 0; // 0, 1 are not primes

    for (int i = 2; i * i <= n; ++i)
    { // For each prime in range
        if (isPrime[i])
        {
            for (int j = i * 2; j <= n; j += i) // remove n / pi number
                isPrime[j] = 0;
        }
    }
}
*/
class dsu
{
public:
    int n;
    vector<int> par, s;
    dsu(int k)
    {
        n = k;
        for (int i = 0; i < n; i++)
        {
            par.push_back(i);
            s.push_back(1);
        }
    }

    int root(int i)
    {
        if (i == par[i])
            return i;
        return par[i] = root(par[i]);
    }

    bool _find(int i, int j)
    {
        if (par[i] == par[j])
            return 1;
        return 0;
    }

    void _union(int a, int b)
    {
        int ar = root(a);
        int br = root(b);
        //        cout<<"-=- "<<a<<" "<<b<<endl;
        if (ar == br)
            return;
        if (s[ar] < s[br])
        {
            par[ar] = par[br];
            s[br] += s[ar];
            s[ar] = 0;
            //        cout<<"inside";
        }
        else
        {
            par[br] = par[ar];
            s[ar] += s[br];
            s[br] = 0;
        }
    }
};

bool valid(int x, int y, int n, int m)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return 0;
    return 1;
}
int dx[8]{-1, 0, 1, 0, -1, 1, 1, -1};
int dy[8]{0, 1, 0, -1, 1, 1, -1, -1};

void sol()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans;
    for (int i = 0; i < n; i++)
    {
        if (i + 2 < n && (s[i + 2] == '0') && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26 && !(i + 3 < n && s[i + 3] == '0'))
        {
            ans.push_back((s[i] - '0') * 10 + (s[i + 1] - '0') - 1 + 'a');
            i = i + 2;
        }
        else
            ans.push_back((s[i] - '0') - 1 + 'a');
    }

    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        sol();
    }
}

/// 1 5 2 6 3 7 4
/// row-i
/// col-j
/// diag1 if (i>=j) 7+i-j else 7-j+i
/// diag2 i+j%
