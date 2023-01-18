#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 105;

int n, m;
int a[N][N];
int mod = 1e4;
int dp[N][N];
int dfs(int x, int y, int ans)
{
	//cout << x << ' ' << y << ' ' << ans << endl;
	if (dp[x][y])return dp[x][y];
	for (int i = 0; i <= ans; ++i)for (int j = 0; j <= ans - i; ++j)if (i || j)
				{

					int tx = x + i, ty = y + j;
					//	cout << tx << ty << endl;
					if (tx >= 1 && tx <= n && ty >= 1 && ty <= m)
						{
							dp[x][y] = (dp[x][y] + dfs(tx, ty, a[tx][ty])) % mod;
						}
				}
	return dp[x][y] % mod;

}

int main()
{
	int t;
	cin >> t;
	while (t--)
		{
			cin >> n >> m;
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)cin >> a[i][j];
			memset(dp, 0, sizeof(dp));
			dp[n][m] = 1;
			cout << dfs(1, 1, a[1][1]) << endl;
		}

	return 0;
}
