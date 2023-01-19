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

int f[N][N];
bool vis[N][N];
int a[N];

int main()
{
	int t;
	cin >> t;
	for (int t1 = 1; t1 <= t; ++t1)
		{
			int n, m, x, y;
			memset(f, 0, sizeof(f));
			memset(vis, 0, sizeof(vis));
			cin >> n;
			for (int i = 1; i <= n; ++i)cin >> a[i];
			cin >> m;
			a[n + 1] = 0;
			for (int i = 1; i <= m; ++i)
				{
					cin >> x >> y;
					f[x][y] = a[y];
					vis[x][y] = 1;
				}
			for (int i = 1; i <= n + 1; ++i)vis[i][i] = 1;
			for (int k = 1; k <= n; ++k)for (int i = 1; i <= n; ++i)for (int j = 2; j <= n + 1; ++j)if (vis[i][k] && vis[k][j])
							{
								f[i][j] = max(f[i][j], f[i][k] + f[k][j]);
								vis[i][j] = 1;
							}

			printf("CASE %d#\npoints : %d\ncircuit : ", t1, f[1][n + 1]);
			for (int i = 1; i <= n; ++i)if (f[1][n + 1] == f[1][i] + f[i][n + 1])cout << i << "->";
			cout << 1 << endl;
			if (t1 < t)cout << endl;
		}
	return 0;
}
