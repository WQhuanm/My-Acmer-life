#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

int a[10][10000];
int dp[N];

int main()
{
	for (int i = 1; i <= 4; ++i)cin >> a[i][0];
	ll t = 0;
	for (int i = 1; i <= 4; ++i)
		{
			ll sum = 0;
			for (int j = 1; j <= a[i][0]; ++j)cin >> a[i][j], sum += a[i][j];
			for (int j = 1; j <= a[i][0]; ++j)for (ll k = sum / 2; k >= a[i][j]; --k)dp[k] = max(dp[k], dp[k - a[i][j]] + a[i][j]);
			t += sum - dp[sum / 2];
			memset(dp, 0, sizeof(dp));
		}
	cout << t << endl;
	return 0;
}
