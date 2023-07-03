#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 2e3;
const int mod = 1e9 + 7;

int a[N], sum[N], b[N];
void mysolve()
{
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i], sum[i] = sum[i - 1] + a[i];
			if (a[i])b[++cnt] = i;
		}
	int p = 40;
	vector dp(cnt + 1, vector<int>(k + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		{
			int l = max(1ll, sum[i] - p), r = min({cnt, sum[i] + p, i});
			for (int j = r; j >= l; --j)
				{
					int tmp = abs(i - b[j]);
					for (int h = k; h >= tmp; --h)dp[j][h] = (dp[j][h] + dp[j - 1][h - tmp]) % mod;
				}
		}
	ll ans = 0;
	for (int i = k; i >= 0; i -= 2)ans = (ans + dp[cnt][i]) % mod;
	cout << ans << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
