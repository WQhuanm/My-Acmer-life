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
const int mod = 1e9 + 7;
const int N = 5e3 + 10;

ll fastmi(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans = ans * base % mod;
			power >>= 1, base = base * base % mod;
		}
	return ans;
}

ll dp[N][N];
ll pre[N];
int n, p;

void mysolve()
{
	cin >> n >> p;
	dp[0][0] = 1;
	pre[0] = 1;
	for (int i = 1; i <= n; ++i)pre[i] = pre[i - 1] * p % mod;
	for (int i = 1; i <= n; ++i)
		{
			dp[i][0] = 1;
			for (int j = 1; j <= i; ++j)
				{
					dp[i][j] = (dp[i - 1][j] * pre[j] + dp[i - 1][j - 1] * ((pre[n] - pre[j - 1] + mod) % mod) % mod) % mod;
				}
		}
	ll ans = 0;
	for (int j = 0; j <= n; ++j)ans = (ans + j * dp[n][j] % mod) % mod;
	ans = ans * fastmi(fastmi(p, n * n), mod - 2) % mod;
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
