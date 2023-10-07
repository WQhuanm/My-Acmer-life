#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 3e3 + 10;

int k, n;
ll a[N], b[N];
ll dp[N][N], mx[N][N];

int p[2][4] = {{1, 1, -1, -1}, {1, -1, 1, -1}};

void mysolve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= n; ++i)cin >> b[i];

	for (int i = 0; i <= n; ++i)for (int j = 1; j <= n; ++j)mx[i][j] = dp[i][j] = -INF;
	for (int i = 0; i <= n; ++i)dp[i][0] = 0;
	for (int u = 0; u < 4; ++u)mx[u][0] = -p[0][u] * b[1] - p[1][u] * a[1];
	for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= k; ++j)dp[i][j] = dp[i - 1][j];
			for (int j = 0; j <= min(k, i); ++j)
				{
					int id = i - j;
					for (int u = 0; u < 4; ++u)
						dp[i][j] = max(dp[i][j], mx[u][id] + p[0][u] * a[i] + p[1][u] * b[i]);
					for (int u = 0; u < 4; ++u)mx[u][id] = max(mx[u][id], dp[i][j] - p[0][u] * b[i + 1] - p[1][u] * a[i + 1]);
				}
		}
	cout << dp[n][k] << endl;
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
