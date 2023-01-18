#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 105;

int a[N][N], dp[N][N];
bool vis[N][N];
int n, k;
int w[5][4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(int x, int y)
{
	if (vis[x][y])return dp[x][y];
	vis[x][y] = 1;
	dp[x][y] = a[x][y];
	int sum = 0;
	for (int i = 0; i < 4; ++i)for (int j = 1; j <= k; ++j)
			{
				int tx = x + j * w[i][0], ty = y + j * w[i][1];
				if (a[tx][ty] > a[x][y] && tx >= 1 && tx <= n && ty >= 1 && ty <= n)
					{
						sum = max(sum, dfs(tx, ty));
					}
			}
	dp[x][y] += sum;
	return dp[x][y];
}

int main()
{
	while (cin >> n >> k && (	n != -1 || k != -1))
		{
			memset(vis, 0, sizeof(vis));
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)cin >> a[i][j];

			cout << dfs(1, 1) << endl;
		}

	return 0;
}

