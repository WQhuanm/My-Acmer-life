#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 110;
int dp[N][N], dpy[N][N];
int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b;
	while (cin >> a >> b)
		{
			int n = (int)a.size();
			a = ' ' + a, b = ' ' + b;
			memset(dp, 0x3f, sizeof(dp));
			memset(dpy, 0x3f, sizeof(dpy));
			for (int i = 1; i <= n; ++i)
				{
					if (a[i] != b[i])
						dp[i][i] = 1;
					else dp[i][i] = 0;
					dpy[i][i] = 1;
				}

			for (int len = 2; len <= n; ++len)for (int i = 1; i + len - 1 <= n; ++i)
					{
						int j = i + len - 1;
						for (int k = i; k < j; ++k)
							{
								if (b[i] == b[j] || b[k] == b[k + 1])dpy[i][j] = min(dpy[i][j], dpy[i][k] + dpy[k + 1][j] - 1);
								else dpy[i][j] = min(dpy[i][j], dpy[i][k] + dpy[k + 1][j] );

								if (b[i] == b[j] && a[i] != b[i] && a[j] != b[j])
									{
										dp[i][j] = min(dp[i][j], dpy[i][k] + dpy[k + 1][j] - 1);
									}
								else
									{
										dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
									}
								if (b[k] == b[k + 1] && a[k] != b[k] && a[k + 1] != b[k + 1])dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] - 1);
								else dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
							}
//						cout << i << ' ' << j << ' ' << dp[i][j] << endl;
//						cout << i << ' ' << j << ' ' << dpy[i][j] << endl;

					}
			cout << dp[1][n] << endl;
		}

	return 0;
}
