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
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 1e5 + 10, M = 15;

ll dp[N][M][M], a[N][M];
int n, m, k;
void mysolve()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)cin >> a[j][i];
	for (int j = 1; j <= m; ++j)sort(a[j] + 1, a[j] + 1 + n, greater<int>());
	for (int i = 1; i <= m - k + 1; ++i)for (int j = 1; j <= k; ++j)for (int x = n; x; --x)
				{
					if (j < k && x > 1)
						{
							dp[i][j][x] = max(dp[i][j][x], dp[i - 1][j + 1][x - 1] + a[i + j - 1][x]);
						}
					for (int y = 1; y <= j; ++y)dp[i][j][1] = max(dp[i][j][1], dp[i - 1][y][x] + a[i + j - 1][1]);
				}
	ll ans = 0;
	int now = m - k + 1;
	for (int i = 1; i <= k; ++i)for (int x = 1; x <= n; ++x)ans = max(ans, dp[now][i][x]);
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
