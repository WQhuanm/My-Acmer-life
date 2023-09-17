#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 3e6 + 10;

int n;
int a[N];
ll dp[2], cnt[2], t_dp[2], t_cnt[2];
void mysolve()
{
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i], ans = (ans + a[i] * a[i] % mod * a[i] % mod) % mod;
	sort(a + 1, a + 1 + n);
	for (int k = 0; k < 32; ++k)
		{
			dp[0] = dp[1] = cnt[0] = cnt[1] = 0;
			int K = 1 << k;
			for (int i = 1; i <= n; ++i)
				{
					if ((a[i] >> k) & 1)
						{
							ans = (ans + (dp[0] + cnt[0]) * a[i] % mod * K % mod) % mod;
							t_dp[1] = (dp[1] + dp[0] + cnt[0] + a[i]) % mod, t_cnt[1] = (cnt[1] + cnt[0] + a[i]) % mod;
							t_dp[0] = (dp[0] + dp[1] + cnt[1]) % mod, t_cnt[0] = (cnt[0] + cnt[1]) % mod;
						}
					else
						{
							ans = (ans + (dp[1] + cnt[1]) * a[i] % mod * K % mod) % mod;
							t_dp[1] = (dp[1] + dp[1] + cnt[1]) % mod, t_cnt[1] = (cnt[1] + cnt[1]) % mod;
							t_dp[0] = (dp[0] + dp[0] + cnt[0] + a[i]) % mod, t_cnt[0] = (cnt[0] + cnt[0] + a[i]) % mod;
						}
					for (int i = 0; i < 2; ++i)dp[i] = t_dp[i], cnt[i] = t_cnt[i];
				}
		}
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
