#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

int a[N];
ll dp[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	ll ans = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i)
		{
			dp[i] = 1;
			for (int j = 1; j < i; ++j)
				{
					if (a[j] <= a[i])
						dp[i] = max(dp[i], dp[j] + 1);
				}
			ans = max(ans, dp[i]);
		}
	cout << ans << endl;
	return 0;
}
