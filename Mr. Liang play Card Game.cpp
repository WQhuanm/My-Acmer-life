#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 110, M = 30;
const int mod = 998244353;

int dp[N][N][M][M];

int a[N], b[N], val[M][M],  mx[N][N];

void mysolve()
{
	int n, m, r, p;
	cin >> n >> m >> r >> p;
	for (int i = 0; i <= n; ++i)for (int j = 0; j <= n; ++j)for (int k = 0; k <= m; ++k)for (int h = 0; h <= r; ++h)dp[i][j][k][h] = -1;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= m; ++i)cin >> b[i], val[i][1] = b[i];
	for (int i = 1; i <= n; ++i)dp[i][i][a[i]][1] = b[a[i]], mx[i][i] = b[a[i]];
	for (int i = 1; i <= m; ++i)for (int j = 2; j <= r; ++j)val[i][j] = val[i][j - 1] * p;

	for (int len = 2; len <= n; ++len)for (int i = 1; len + i - 1 <= n; ++i)
			{
				int j = i + len - 1;
				for (int h = 1; h <= r; ++h)for (int c = 1; c <= m; ++c)
						{
							for (int k = i; k < j; ++k)
								{
									if (~dp[i][k][c][h - 1] && ~dp[k + 1][j][c][h - 1])dp[i][j][c][h] = max(dp[i][j][c][h], dp[i][k][c][h - 1] + dp[k + 1][j][c][h - 1] - 2 * val[c][h - 1] + val[c][h]);
									if (~dp[i][k][c][h])dp[i][j][c][h] = max(dp[i][j][c][h], dp[i][k][c][h ] + mx[k + 1][j]);
									if (~dp[k + 1][j][c][h])dp[i][j][c][h] = max(dp[i][j][c][h], mx[i][k ] + dp[k + 1][j][c][h ]);
									mx[i][j] = max(mx[i][j], dp[i][j][c][h]);
								}
						}
			}

	cout << mx[1][n] << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
