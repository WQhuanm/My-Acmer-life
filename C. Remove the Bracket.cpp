#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;

int dp[N][3], a[N][3];

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, n, s, x;
	cin >> t;
	while (t--)
		{
			cin >> n >> s;
			for (int i = 1; i <= n; ++i)
				{
					cin >> x;
					if (i == 1 || i == n)a[i][0] = a[i][1] = x;
					else
						{
							if (x >= s)a[i][0] = s, a[i][1] = x - s;
							else a[i][0] = 0, a[i][1] = x;
						}
				}
			//dp[i][0]表示累加到第i个，且第i+1个用去了a[i+1][0](那么后面dp[i+1]使用a[i+1]时就只能用a[i+1][1])，dp[i][1]同理
			dp[1][0] = a[1][0] * a[2][0];
			dp[1][1] = a[1][0] * a[2][1];
			for (int i = 2; i < n; ++i)
				{
					//如：如果用dp[i-1][0],那么上次用去了a[i][0],这次用a[i][1]*a[i+1][0],乘a[i+1][0]是因为dp[i][0]表示以使用0来结束
					dp[i][0] = min(dp[i - 1][0] + a[i][1] * a[i + 1][0], dp[i - 1][1] + a[i][0] * a[i + 1][0]);//dp[i]取dp[i-1][0]与dp[i-1][1]各自加乘a[i]后获得的min
					dp[i][1] = min(dp[i - 1][0] + a[i][1] * a[i + 1][1], dp[i - 1][1] + a[i][0] * a[i + 1][1]);
				}
			int ans = min(dp[n - 1][0], dp[n - 1][1]);
			cout << ans << endl;
		}
	return 0;
}
