#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 110;

int dp[N][N][N];
int a[N], sum[N];
int main()
{
	int t, n, t1 = 0;
	cin >> t;
	while (t--)
		{

			cin >> n;
			for (int i = 1; i <= n; ++i)cin >> a[i], sum[i] = sum[i - 1] + a[i];
			for (int i = 1; i <= n; ++i)for (int j = i; j <= n; ++j)for (int len = 1; len <= n; ++len)dp[i][j][len] = INF;
			for (int len = 1; len <= n; ++len)
				{
					for (int i = 1; i + len - 1 <= n; ++i)
						{
							int j = i + len - 1;
							for (int k = i; k <= j; ++k)
								dp[i][j][len] = min(dp[i][j][len], dp[i][k - 1][k - 1 - i + 1] + a[k] * (len - 1) + dp[k + 1][j][j - k - 1 + 1] + ( k  - i) * (sum[j] - sum[k]));
						}
				}
			printf("Case #%d: ", ++t1);
			cout << dp[1][n][n] << endl;

		}
	return 0;
}
