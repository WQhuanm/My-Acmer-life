#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 1100;

ll a[N];
ll dp[N][N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			a[i + n] = a[i];
		}
	ll maxn = -INF;
	for (int len = 2; len <= n; ++len)
		{
			for (int i = 1; i <= 2 * n - 1; ++i)
				{
					int j = len + i - 1;
					for (int k = i; k < j; ++k)
						{
							dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
							maxn = max(maxn, dp[i][j]);
						}
				}
		}

	cout << maxn << endl;
	return 0;
}
