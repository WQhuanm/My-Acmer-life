#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e3 + 10;

int f[N][N], dp[N][N];
int a[N];
int main()
{
	int n, x, y;
//	bool flag = 1;
	while (cin >> n && n)
		{
			memset(dp, 0, sizeof(dp));
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)
					{
						cin >> f[i][j];
						if (f[i][j] == -1)f[i][j] = INF;
						dp[i][j] = f[i][j];
					}
			for (int i = 1; i <= n; ++i)cin >> a[i];
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)dp[i][j] += a[j] + a[i];

			for (int k = 1; k <= n; ++k)for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] - a[k]);

			while (cin >> x >> y && (x != -1 || y != -1))
				{
//					if (flag)flag = 0;
//					else cout << endl;
					printf("From %d to %d :\nPath: ", x, y);

					cout << x;
					int t = x;
					while (t != y)
						for (int i = 1; i <= n; ++i)
							if (i != t)if (dp[t][y] == dp[i][y] + f[t][i] + a[t] + (i == y ? -a[i] : 0) )
									{
										cout << "-->" << i;
										t = i;
										break;
									}
					cout << endl;
					cout << "Total cost : " << dp[x][y] - a[x] - a[y] << endl;
					cout << endl;
				}
		}

	return 0;
}
