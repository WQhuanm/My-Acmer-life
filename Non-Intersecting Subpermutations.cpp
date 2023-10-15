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
const int N = 4010;

ll dp[N][N], sum[N][N], pre[N];
int n, k;
void mysolve()
{
	cin >> n >> k;
	ll ans = 0;
	pre[0] = 1;
	for (int i = 1; i <= n; ++i)pre[i] = pre[i - 1] * k % mod, sum[i][k] = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)for (int j = k; j; --j)
			{
				if (j < k)
					{
						dp[i][j] = dp[i - 1][j - 1] * (k - j + 1) % mod;
						dp[i][j] = (dp[i][j] + sum[i - 1][j]) % mod;
						sum[i][j] = (sum[i][j + 1] + dp[i][j]) % mod;
					}
				else if (i >= k)
					{
						dp[i][0] = dp[i - 1][j - 1];
						ans = (ans + dp[i][0] * pre[n - i] % mod) % mod;
					}
			}
	cout << ans << endl;
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
