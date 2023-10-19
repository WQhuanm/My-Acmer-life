#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 2e5 + 10, M = 105;

ll dp[N], pre[M][N], sum[M], invr[M], inv_pre[M][N];
int p[N];

ll fastmi(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans = ans * base % mod;
			power >>= 1, base = base * base % mod;
		}
	return ans;
}
int inv = fastmi(100, mod - 2);

int n;
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> p[i];
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		{
			dp[i] = (1 + pre[p[i]][i + 1] * sum[p[i]] % mod) * invr[p[i]] % mod;
			for (int j = 0; j < 100; ++j)sum[j] = (sum[j] + dp[i] * inv_pre[j][i] % mod)  % mod;
			ans = (ans + dp[i]) % mod;
		}
	cout << ans << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	for (int i = 0; i < 100; ++i)invr[i] = fastmi((1 - 1ll * inv * i % mod + mod) % mod, mod - 2);
	for (int i = 1; i < 100; ++i)
		{
			pre[i][0] = inv_pre[i][0]=1;
			int now = 1ll * inv * i % mod, inv_now = fastmi(now, mod - 2);
			for (int j = 1; j <= N - 5; ++j)
				{
					pre[i][j] = pre[i][j - 1] * now % mod;
					inv_pre[i][j] = inv_pre[i][j - 1] * inv_now % mod;
				}
		}
	mysolve();
	system("pause");
	return 0;
}
