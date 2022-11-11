#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

int dp[N];
int a[N];//时间
int b[N];//价值

int main()
{
	int t, m;
	cin >> t >> m;
	for (int i = 1; i <= m; ++i)cin >> a[i] >> b[i];
	for (int i = 1; i <= m; ++i)
		{
			for (int j = t; j >= a[i]; --j)dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
		}
	cout << dp[t] << endl;
	return 0;
}
