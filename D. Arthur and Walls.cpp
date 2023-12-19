#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 2010;
		
int n, m;
char a[N][N];
bool vis[N][N];
int w[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
		
bool jud(int x, int y)
{
	if (a[x - 1][y] == a[x][y + 1] && a[x - 1][y] == a[x - 1][y + 1] && a[x - 1][y] == '.')return 1;
	if (a[x + 1][y] == a[x][y - 1] && a[x + 1][y] == a[x + 1][y - 1] && a[x + 1][y] == '.')return 1;
	if (a[x - 1][y] == a[x][y - 1] && a[x - 1][y] == a[x - 1][y - 1] && a[x - 1][y] == '.')return 1;
	if (a[x + 1][y] == a[x][y + 1] && a[x + 1][y] == a[x + 1][y + 1] && a[x + 1][y] == '.')return 1;
	return 0;
}
		
void dfs(int x, int y)
{
	vis[x][y] = 1;
	for (int i = 0; i < 4; ++i)
		{
			int tx = x + w[i][0], ty = y + w[i][1];
			if (tx > 0 && tx <= n && ty > 0 && ty <= m &&  !vis[tx][ty])
				{
					if (a[tx][ty] == '*')
						{
							if (jud(tx, ty))a[tx][ty] = '.', dfs(tx, ty);
						}
					else dfs(tx, ty);
				}
		}
	for (int i = 0; i < 8; ++i)
		{
			int tx = x + w[i][0], ty = y + w[i][1];
			if (tx > 0 && tx <= n && ty > 0 && ty <= m &&  !vis[tx][ty])
				{
					if (a[tx][ty] == '*')
						{
							if (jud(tx, ty))a[tx][ty] = '.', dfs(tx, ty);
						}
				}
		}
}
		
void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				cin >> a[i][j];
			}
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)if (a[i][j] == '.' && !vis[i][j])dfs(i, j);
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				cout << a[i][j];
				if (j == m)cout << endl;
			}
}
		
int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
