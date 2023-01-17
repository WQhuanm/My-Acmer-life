#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 25;

char a[N][N];
bool vis[N][N];
int n, m, sx, sy, ans;
int w[5][3] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void dfs(int x, int y)
{
	++ans;
	for (int i = 0; i < 4; ++i)
		{
			int tx = x + w[i][0], ty = y + w[i][1];
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] == '.' && !vis[tx][ty])
				{
					vis[tx][ty] = 1;
					dfs(tx, ty);
				}
		}
}

int main()
{
	while (cin >> m >> n && (n || m))
		{
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
					{
						cin >> a[i][j];
						if (a[i][j] == '@')sx = i, sy = j;
					}
			memset(vis, 0, sizeof(vis));
			ans = 0;
			dfs(sx, sy);
			cout << ans << endl;
		}

	return 0;
}
