#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 110;

int dp[N][N];

int main()
{
	int n, m;
	while (cin >> n >> m && (n || m))
		{
			memset(dp, 0x3f, sizeof(dp));
			int a, b, t;
			for (int i = 1; i <= m; ++i)
				{
					cin >> a >> b >> t;
					dp[a][b] = dp[b][a] = min(dp[a][b], t);
				}
			for (int i = 1; i <= n; ++i)dp[i][i] = 0;
			for (int k = 1; k <= n; ++k)for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			cout << dp[1][n] << endl;
		}

	return 0;
}
