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

int f[N][N];
int a[N];
int sum = 0;
int dp[N * N];
int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T, n, m, x, y, t;
	cin >> T;
	while (T--)
		{
			cin >> n >> m;
			memset(f, 0x3f, sizeof(f));
			memset(dp, 0, sizeof(dp));
			for (int i = 0; i <= n; ++i)f[i][i] = 0;
			for (int i = 1; i <= m; ++i)
				{
					cin >> x >> y >> t;
					f[x][y] = f[y][x] = min(f[x][y], t);
				}
			sum = 0;
			for (int i = 1; i <= n; ++i)cin >> a[i], sum += a[i];
			int ans = INF;
			for (int k = 0; k <= n; ++k)for (int i = 0; i <= n; ++i)for (int j = 0; j <= n; ++j)f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			for (int i = 1; i <= n; ++i)for (int j = 10010; j >= f[0][i]; --j)
					{
						dp[j] = max(dp[j], dp[j - f[0][i]] + a[i]);
						if (dp[j] >= sum / 2 + 1)ans = min(ans, j);
					}

			if (ans < INF)cout << ans << endl;
			else cout << "impossible" << endl;
		}

	return 0;
}
