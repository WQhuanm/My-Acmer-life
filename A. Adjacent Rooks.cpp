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
const long long mod = 1e9 + 7, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 1010;

int n, k;
ll dp[N][N][2];
void mysolve()
{
	cin >> n >> k;

	ll ans = (dp[n][k][0] + dp[n][k][1]) % mod;
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	int n = 1000;
	dp[1][0][0] = 1;
	for (int i = 2; i <= n; ++i)for (int j = 0; j < i; ++j)
			{
				dp[i][j][0] = dp[i][j][1] = 0;
				if (j)dp[i][j][1] = (dp[i - 1][j - 1][0] * 2 % mod + dp[i - 1][j - 1][1]) % mod;
				if (j < i - 1)
					{
						dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][1]) % mod;
						dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][0] * (i - 2 - j) % mod + dp[i - 1][j][1] * (i - 1 - j) % mod) % mod;
					}
				if (j + 1 < i - 1)
					{
						dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j + 1][0] * (j + 1) % mod + dp[i - 1][j + 1][1] * j % mod) % mod;
					}
			}
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
