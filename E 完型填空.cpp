#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 110;
int dp[N][30][30][30];
int a[N][5];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
	for (int i = 1; i <= n; ++i)for (int j = 0; j <= n / 4 && j < i; ++j)for (int k = 0; k <= n / 4 && k + j < i; ++k)for (int h = 0; h <= n / 4 && j + k + h < i; ++h)
					{
						int tmp = dp[i - 1][j][k][h];
						dp[i][j][k][h] = max(dp[i][j][k][h], tmp + a[i][4]);
						dp[i][j + 1][k][h] = max(dp[i][j + 1][k][h], tmp + a[i][1]);
						dp[i][j][k + 1][h] = max(dp[i][j][k + 1][h], tmp + a[i][2]);
						dp[i][j][k][h + 1] = max(dp[i][j][k][h + 1], tmp + a[i][3]);
					}
	cout << dp[n][n / 4][n / 4][n / 4] << endl;
	return 0;
}
