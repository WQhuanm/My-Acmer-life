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
const int mod = 998244353;
const int N = 510;

int n, m;
ll dp[N][N], cnt[N][N], a[N][N];
void mysolve()
{
	int x, y, w;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)a[i][j] = dp[i][j] = (i == j ? 0 : INF);
	while (m--)
		{
			cin >> x >> y >> w;
			a[x][y] = w;
			dp[x][y] = w;
			cnt[x][y] = 1;
		}
	int mn = INF, ans = 0;
	for (int k = 1; k <= n; ++k)
		{
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)
					{
						if (dp[i][k] + dp[k][j] < dp[i][j])dp[i][j] = dp[i][k] + dp[k][j], cnt[i][j] = cnt[i][k] * cnt[k][j] % mod;
						else if (dp[i][k] + dp[k][j] == dp[i][j])cnt[i][j] = (cnt[i][j] + cnt[i][k] * cnt[k][j] % mod) % mod;
					}
			for (int i = 1; i < k; ++i)
				{
					if (a[i][k] + dp[k][i] < mn)mn = dp[k][i] + a[i][k], ans = cnt[k][i];
					else if (a[i][k] + dp[k][i] == mn)ans = (ans + cnt[k][i]) % mod;
				}
		}
	if (mn == INF)mn = -1, ans = -1;
	cout << mn << " " << ans << endl;
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
