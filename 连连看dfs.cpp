#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1010;

int a[N][N];
int n, m, sx, sy, ex, ey;
int w[5][3] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool flag, vis[N][N];

void dfs(int x, int y, int t, int j)
{
	if (flag)return;
	if (x == ex && y == ey)
		{
			flag = 1;
			return;
		}
	if (t == 2)
		{
			if (j == 0 && y == ey && x < ex)
				{
					int tx = x + 1, ty = y;
					if (!vis[x + 1][y] &&  ( !a[tx][ty] || (tx == ex && ty == ey)) && tx >= 1 && ty >= 1 && tx <= n && ty <= m)
						{
							vis[x + 1][y] = 1;
							dfs(x + 1, y, 2, j);
							if (flag)return;
							vis[x + 1][y] = 0;
						}
				}
			if (j == 1 && y == ey && x > ex)
				{
					int tx = x - 1, ty = y;
					if (!vis[x - 1][y] &&  ( !a[tx][ty] || (tx == ex && ty == ey)) && tx >= 1 && ty >= 1 && tx <= n && ty <= m)
						{
							vis[x - 1][y] = 1;
							dfs(x - 1, y, 2, j);
							if (flag)return;
							vis[x - 1][y] = 0;
						}
				}
			if (j == 2 && y < ey && x == ex)
				{
					int tx = x, ty = y + 1;
					if (!vis[x ][y + 1] &&  ( !a[tx][ty] || (tx == ex && ty == ey)) && tx >= 1 && ty >= 1 && tx <= n && ty <= m)
						{
							vis[x] [y + 1] = 1;
							dfs(x, y + 1, 2, j);
							if (flag)return;
							vis[x][y + 1] = 0;
						}
				}
			if (j == 3 && y > ey && x == ex)
				{
					int tx = x, ty = y - 1;
					if (!vis[x][y - 1] &&  ( !a[tx][ty] || (tx == ex && ty == ey)) && tx >= 1 && ty >= 1 && tx <= n && ty <= m)
						{
							vis[x ][y - 1] = 1;
							dfs(x, y - 1, 2, j);
							if (flag)return;
							vis[x][y - 1] = 0;
						}
				}
		}
	else
		{
			for (int i = 0; i < 4; ++i)
				{
					int tx = x + w[i][0], ty = y + w[i][1];
					if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && ( !a[tx][ty] || (tx == ex && ty == ey)) && !vis[tx][ty])
						{
							vis[tx][ty] = 1;
							if (j == -1 || i == j)dfs(tx, ty, t, i);
							else dfs(tx, ty, t + 1, i);
							if (flag)return ;
							vis[tx][ty] = 0;
						}
				}
		}

}

int main()
{
	while (cin >> n >> m && (n || m))
		{
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)cin >> a[i][j];
			int q;
			cin >> q;
			while (q--)
				{
					cin >> sx >> sy >> ex >> ey;
					flag = 0;
					if (a[sx][sy] == a[ex][ey] && a[sx][sy])
						memset(vis, 0, sizeof(vis)), dfs(sx, sy, 0, -1);
					if (flag)cout << "YES" << endl;
					else cout << "NO" << endl;
				}
		}

}
