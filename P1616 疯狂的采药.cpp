#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e7 + 100;

ll dp[N];
ll a[N];//时间
ll b[N];//价值

int main()
{
	ll t, m;
	cin >> t >> m;
	for (ll i = 1; i <= m; ++i)cin >> a[i] >> b[i];

	for (ll i = 1; i <= m; ++i)
		{
			for (int j = 0; j <= t; ++j)if (j >= a[i])dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
		}
	cout << dp[t] << endl;
	return 0;
}
