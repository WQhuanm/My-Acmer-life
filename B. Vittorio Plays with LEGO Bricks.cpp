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
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 310;

int n, h, a[N];
ll dp[N][N];

void mysolve()
{
	cin >> n >> h;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= n; ++i)dp[i][i] = h;
	for (int len = 2; len <= n; ++len)
		{
			for (int i = 1; i + len - 1 <= n; ++i)
				{
					int j = i + len - 1;
					for (int k = i; k < j; ++k)
						{
							dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] - max(0ll, h - (a[j] - a[i] - 1) / 2));
						}
				}
		}
	cout << dp[1][n] << endl;
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
