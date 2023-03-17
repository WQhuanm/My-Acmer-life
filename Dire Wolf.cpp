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
const int N = 210;

int dp[N][N];
int a[N], b[N];
int main()
{
	int t, n, t1 = 0;
	cin >> t;
	while (t--)
		{
			cin >> n;
			for (int i = 1; i <= n; ++i)for (int j = i; j <= n; ++j)dp[i][j] = INF;
			for (int i = 1; i <= n; ++i)cin >> a[i];
			for (int i = 1; i <= n; ++i)cin >> b[i];
			b[0] = b[n + 1] = 0;
			for (int len = 0; len < n; ++len)for (int i = 1; i + len <= n; ++i)
					{
						int j = i + len;
						for (int k = i ; k <= j; ++k)dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[k] + b[i - 1] + b[j + 1]);
					}
			printf("Case #%d: ", ++t1);
			cout << dp[1][n] << endl;
		}

	return 0;
}
