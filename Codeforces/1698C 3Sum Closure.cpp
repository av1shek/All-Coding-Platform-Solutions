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
    ll n;
    cin >> n;
    ll pos = 0, neg = 0, zero = 0;
    vector<ll> a(n), tmp;
    for (auto &i : a)
    {
        cin >> i;
        if (i > 0)
        {
            pos++;
            tmp.push_back(i);
        }
        else if (i < 0)
        {
            neg++;
            tmp.push_back(i);
        }
        else
            zero++;
    }
    if (pos >= 3 || neg >= 3)
    {
        cout << "NO";
        return;
    }
    if (zero > 1)
    {
        tmp.push_back(0);
        tmp.push_back(0);
    }
    else if (zero == 1)
        tmp.push_back(0);
    ll m = tmp.size();
    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            for (ll k = 0; k < m; k++)
            {
                if (i != j && i != k && j != k)
                {
                    auto it = find(tmp.begin(), tmp.end(), (tmp[i] + tmp[j] + tmp[k])) - tmp.begin();

                    if (it == m)
                    {
                        cout << "NO";
                        return;
                    }
                }
            }
        }
    }
    cout << "YES";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
        cout << "\n";
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}
