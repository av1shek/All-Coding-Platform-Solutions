#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, s;
long long power(long long b, long long n)
{
   long long s = 1;
   while (n)
   {
      if (n % 2 == 1)
         s = s * b % 998244353;
      b = b * b % 998244353;
      n /= 2;
   }
   return s;
}
long long count(int i, int j)
{
   return ((i / (1 << (j + 1))) << j) + (max(0ll, i % (1 << (j + 1)) - (1 << j) + 1));
}
void solve()
{
   cin >> n >> m;
   s = 0;
   for (int i = 0; i < 31; ++i)
      s = (s + (power(count(m, i), n) << i) % 998244353) % 998244353;
   cout << s << endl;
}
signed main()
{
   int T;
   cin >> T;
   while (T--)
      solve();
}
