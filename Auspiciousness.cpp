#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
#define int              long long
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
int mod = 998244353;
const int N = 310;
int n;

int c[N][N], dp[N][N][2], pre[N << 1];

void mysolve()
{
	cin >> n >> mod;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= n; ++i)c[i][0] = 1;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= i; ++j)c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	pre[0] = 1;
	for (int i = 1; i <= 2 * n; ++i)pre[i] = pre[i - 1] * i % mod;
	dp[0][0][1] = dp[0][0][0] = 1;
	for (int i = 0; i <= n; ++i)for (int j = 0; j <= n; ++j)
			{
				for (int k = 0; k < j; ++k)dp[i][j][1] = (dp[i][j][1] + dp[i][k][0] * c[n - k][j - k] % mod) % mod;
				for (int k = 0; k < i; ++k)dp[i][j][0] = (dp[i][j][0] + dp[k][j][1] * c[n - k][i - k] % mod) % mod;
			}
//	for (int k = 0; k < 2; ++k)for (int i = 0; i <= n; ++i)for (int j = 0; j <= n; ++j)printf("dp[%lld][%lld][%lld]  : %lld\n", i, j, k, dp[i][j][k]);
	ll ans = 0;
	for (int i = 0; i <= n; ++i)for (int j = 0; j <= n; ++j)
			{
				for (int k = 0; k + 2 <= i; ++k)ans = (ans + dp[k][j][1] * c[n - k][i - k] % mod * (i - k - 1) % mod * (i + j) % mod * pre[2 * n - i - j] % mod) % mod;
				for (int k = 0; k + 2 <= j; ++k)ans = (ans + dp[i][k][0] * c[n - k][j - k] % mod * (j - k - 1) % mod * (i + j) % mod * pre[2 * n - i - j] % mod) % mod;
			}
//	cout << ans << endl;
	ans = (ans + (dp[n][n][0] + dp[n][n][1]) * 2 * n % mod) % mod;
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
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
