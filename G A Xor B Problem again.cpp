#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

int dp[1 << 17], a[1 << 17];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i], dp[a[i]]++;//先记录初始个数
	for (int i = 0; i < 17; ++i)for (int j = 0; j < (1 << 17); ++j)if ((j >> i) & 1)dp[j] += dp[j ^ (1 << i)];//逐位遍历更新
	ll ans = 0;
	for (int i = 1; i <= n; ++i)ans += dp[(1 << 17) - 1 - a[i]]; //1<<17-1，把17位（0~16）都置为1
	cout << ans << endl;
	return 0;
}
