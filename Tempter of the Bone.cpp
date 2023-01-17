#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 10;

char a[N][N];
bool vis[N][N];
int n, m, t, sx, sy, ex, ey;
bool flag;
int w[5][3] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void dfs(int x, int y, int ans)
{
	if (flag)return;
	if (a[x][y] == 'D' && ans == t)
		{
			flag = 1;
			return;
		}
	if (ans >= t)return;
	for (int i = 0; i < 4; ++i)
		{
			int tx = x + w[i][0], ty = y + w[i][1];
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && !vis[tx][ty] && a[tx][ty] != 'X')
				{
					vis[tx][ty] = 1;
					dfs(tx, ty, ans + 1);
					if (flag)return;
					vis[tx][ty] = 0;
				}
		}
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> n >> m >> t && (n || m || t))
		{
			int cnt = 0;
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
					{
						cin >> a[i][j];
						if (a[i][j] == 'S')sx = i, sy = j;
						else if (a[i][j] == 'D')ex = i, ey = j;
						if (a[i][j] != 'X')cnt++;

					}
			memset(vis, 0, sizeof(vis));
			vis[sx][sy] = 1;
			flag = 0;
			if (cnt > t && ( (abs(sx - ex) % 2) ^ (abs(sy - ey) % 2)) == t % 2)
				dfs(sx, sy, 0);
			if (flag)cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	return 0;
}
