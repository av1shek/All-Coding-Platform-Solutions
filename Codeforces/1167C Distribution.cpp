#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define inf (long long)1e18
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define gcd(a, b) __gcd(a, b)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const int N = 1e9 + 7;
ll powm(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int pow(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = ((res) * (x));
        res %= N;
        y = y >> 1;
        x = ((x) * (x));
    }
    return res;
}

void swaps(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapi(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> s(n), t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    vector<int> ans(n);
    int ix = -1;
    // for (ix = n; ix < 2 * n; ix++)
    // {
    //     if (t[ix % n] <= s[(ix - 1) % n]&&)
    //     {
    //         // ans[ix % n] = t[ix % n];
    //         break;
    //     }
    // }
    if (ix == -1)
    {
        int idx = 0, mn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (t[i] < mn)
            {
                mn = t[i];
                idx = i;
            }
        }
        ix = idx;
    }
    ix = ix % n;

    int tmp = t[ix], i;
    for (i = ix; i != (ix - 1 + n) % n; i = (i + 1) % n)
    {
        if (t[i] < s[i - 1] + tmp)
        {
            ans[i] = t[i];
            // cout << t[i] << "\n";
            tmp = t[i];
        }
        else
        {
            ans[i] = s[i - 1] + tmp;

            tmp = s[i - 1] + tmp;
        }
    }
    if (t[i] < s[i - 1] + tmp)
    {
        ans[i] = t[i];
        // cout << t[i] << "\n";
        tmp = t[i];
    }
    else
    {
        ans[i] = s[i - 1] + tmp;

        tmp = s[i - 1] + tmp;
    }

    for (auto i : ans)
    {
        cout << i << "\n";
    }
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    // int t;
    // scanf("%d", &t);
    // while (t--)
    // {
    solve();
    //     cout << "\n";
    // }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}
