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
const int N = 30;

int mp[N][N][N][N];
int dp[N][N];
bool vis[N][N];
int w[5][3] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;

struct node
{
	int x, y, t;
	node(int a, int b, int t1)
	{
		x = a, y = b, t = t1;
	}
	bool operator<(const node&k)const
	{
		return t > k.t;
	}

};

int main()
{

	while (cin >> n >> m && (n || m))
		{
			n++;
			int x;
			char a;
			memset(mp, 0x3f, sizeof(mp));
			memset(dp, 0x3f, sizeof(dp));
			memset(vis, 0, sizeof(vis));
			for (int i = 1; i <= n; ++i)
				{
					for (int j = 1; j <= m; ++j)
						{
							cin >> x >> a;
							if (x == 0)continue;
							if (a == '*')
								{
									mp[i][j][i][j + 1] = mp[i][j + 1][i][j] = 2520 / x;
								}
							else if (a == '>')mp[i][j][i][j + 1] = 2520 / x;
							else mp[i][j + 1][i][j] = 2520 / x;
						}
					if (i < n)
						{
							for (int j = 1; j <= m + 1; ++j)
								{
									cin >> x >> a;
									if (x == 0)continue;
									int tmp = 2520 / x;
									if (a == '*')
										{
											mp[i][j][i + 1][j] = mp[i + 1][j][i][j] = tmp;
										}
									else if (a == 'v')
										{
											mp[i][j][i + 1][j] = tmp;
										}
									else  mp[i + 1][j][i][j] = tmp;
								}
						}

				}
			priority_queue<node>q;
			dp[n][m + 1] = 0;
			q.push({n, m + 1, 0});
			while (!q.empty())
				{
					int x = q.top().x, y = q.top().y;
					q.pop();
					if (vis[x][y])continue;
					vis[x][y] = 1;
					for (int i = 0; i < 4; ++i)
						{
							int tx = x + w[i][0], ty = y + w[i][1];
							if (tx >= 1 && tx <= n && ty >= 1 && ty <= m + 1 && mp[tx][ty][x][y] < INF && dp[tx][ty] > dp[x][y] + mp[tx][ty][x][y])
								{
									dp[tx][ty] = dp[x][y] + mp[tx][ty][x][y];
									if (!vis[tx][ty])q.push({tx, ty, dp[tx][ty]});
								}
						}
				}
			if (dp[1][1] < INF)
				cout << dp[1][1] << " blips" << endl;
			else cout << "Holiday" << endl;

		}

	return 0;
}

