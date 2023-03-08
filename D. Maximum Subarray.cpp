#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 2e5 + 10;

ll dp[N][25];
int a[N];

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		{
			int n, m, x;
			cin >> n >> m >> x;
			for (int i = 1; i <= n; ++i)cin >> a[i];
			for (int i = 0; i <= n; ++i)for (int j = 0; j <= m; ++j)dp[i][j] = 0;
			ll ans = 0;
			for (int i = 1; i <= n; ++i)for (int j = max(0, m - n + i); j <= m && j <= i; ++j)
					{
						if (j < i)dp[i][j] = max(0ll, dp[i - 1][j]) + a[i] - x;//j<i就有此更新，j==i则不用，因为前面最多更新j-1个
						if (j)dp[i][j] = max(dp[i][j], max(0ll, dp[i - 1][j - 1]) + a[i] + x);
						ans = max(ans, dp[i][j]);//答案就是max(dp[i][j]),不是dp[i][m]，不要求m个都在我的最大连续子串和范围内更新
					}
			cout << ans << endl;
		}
	return 0;
}
