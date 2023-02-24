#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
const int N = 5e6 + 100;

int sv[N], s[N], a[N];
int n, mod, k, ki = 1, ans;
inline ll read(ll &x)
{
	x = 0;
	char ch = 0;
	while (ch < '0' || ch > '9')ch = getchar();
	while (ch >= '0' && ch <= '9')
		{
			x = x * 10 + ch - '0';
			ch = getchar();
		}
	return x;
}

ll fastmi(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans = (ans * base) % mod;
			power >>= 1;
			base = (base * base) % mod;
		}
	return ans;
}

int32_t main()
{
	read(n), read(mod), read(k);
	s[0] = 1;
	for (int i = 1; i <= n; ++i)read(a[i]), s[i] = s[i - 1] * a[i] % mod;//乘法记得mod
	sv[n] = fastmi(s[n], mod - 2);
	for (int i = n - 1; i >= 1; --i)sv[i] = sv[i + 1] * a[i + 1] % mod;//求积逆元
	for (int i = 1; i <= n; ++i)
		{
			ki = (ki * k) % mod;
			int	inv = sv[i] * s[i - 1] % mod ;//这勾题卡快读就算了，还卡这种常数，开inv数组没有必要，而且还会mle，用inv暂时存储inv[i]即可
			ans = (ans + inv * ki % mod) % mod;
		}
	cout << ans << endl;
	return 0;
}

