#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
const int N = 2e3 + 10;

int dp[N * 10][N];
int a[N * 10];

void mysolve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 1; i < m; ++i)dp[0][i] = a[0];
	for (int i = 1; i < m; ++i)
		{
			dp[i][1] = a[i] + a[i - 1];
			for (int j = 2; j <= i; ++j)dp[i][j] = min(dp[i][j - 1], a[i] + a[i - j]);
			for (int j = i + 1; j < m; ++j)dp[i][j] = dp[i][j - 1];
		}

	for (int i = m; i < n; ++i)
		{
			int p = i % m;
			dp[p][1] = a[i] + dp[(i - 1) % m][m - 1];
			for (int j = 2; j < m; ++j)dp[p][j] = min(dp[p][j - 1], a[i] + dp[(i - j) % m][m - j]);
		}
	int ans = inf;
	for (int i = 1; i < m; ++i)ans = min(ans, dp[(n - i) % m][m - i]);
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
