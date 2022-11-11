#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e3 + 100;

ll a[N];//金钱
ll b[N];//时间
ll dp[N][N];

int main()
{
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 1; i <= n; ++i)cin >> a[i] >> b[i];
	for (int i = 1; i <= n; ++i)for (int j = m; j >= a[i]; --j)for (int k = t; k >= b[i]; --k)dp[j][k] = max(dp[j][k], dp[j - a[i]][k - b[i]] + 1);
	cout << dp[m][t] << endl;
	return 0;
}
