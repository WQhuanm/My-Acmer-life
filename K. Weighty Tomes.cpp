#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

int n, m;
int dp[N][30];
void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)dp[i][1] = i;
	for (int i = 1; i <= m; ++i)dp[1][i] = 1;
	for (int i = 2; i <= n; ++i)for (int k = 2; k <= m; ++k)
			{
				dp[i][k] = i;
				for (int j = 1; j < i; ++j)
					dp[i][k] = min(dp[i][k], max(dp[i - j][k] + 1, dp[j - 1][k - 1] + 1));
			}

	cout << dp[n][m];
	int l = n, r = 1;
	for (int i = 1; i <= n; ++i)
		if (max(dp[n - i][m] + 1, dp[i - 1][m - 1] + 1) == dp[n][m])l = min(l, i), r = max(r, i);
	if (l == r)cout << " " << l << endl;
	else cout << " " << l << "-" << r << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
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
