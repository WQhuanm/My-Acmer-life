#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 3e5 + 10;
const int mod = 1e9 + 7;

int a[N];
ll sum[N];

ll fastmi(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans = ans * base % mod;
			base = base * base % mod;
			power >>= 1;
		}
	return ans;
}

void mysolve()
{
	int n, m;
	cin >> n >> m;
	map<int, int>mp;
	for (int i = 1; i <= n; ++i)cin >> a[i], mp[a[i]]++;
	sort(a + 1, a + 1 + n);
	int len = unique(a + 1, a + 1 + n) - a - 1;
	sum[0] = 1;
	ll ans = 0;
	for (int i = 1; i <= len; ++i)sum[i] = sum[i - 1] * mp[a[i]] % mod;
	for (int l = 1, r = 1; l <= len - m + 1; ++l)
		{
			while (r - l + 1 < m && a[r + 1] == a[r] + 1)r++;
			if (r - l + 1 == m)
				{
					ans = (ans + sum[r] * fastmi(sum[l - 1], mod - 2) % mod) % mod;
				}
			else
				{
					l = r, r = r + 1;
				}
		}
	cout << ans << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
		cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
