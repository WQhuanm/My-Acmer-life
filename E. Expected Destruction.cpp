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
const int mod = 1e9 + 7, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 510;

int n, m;
int a[N], dp[N][N];

ll fastmi(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans = ans * base % mod;
			base = base * base % mod, power >>= 1;
		}
	return ans;
}

int inv = fastmi(2, mod - 2);

int dfs(int i, int j)
{
	if (j == m + 1)return dp[i][j] = 0;
	if (dp[i][j])return dp[i][j];
	if (i == j)return dp[i][j] = m - i + 1;
	return dp[i][j] = inv * (dfs(i, j + 1) + dfs(i + 1, j)) % mod;
}
void mysolve()
{
	cin >> n >> m;
	ll ans = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i], ans += m - a[i] + 1;
	for (int i = 1; i < n; ++i)
		{
			ans = (ans - dfs(a[i], a[i + 1]) + mod) % mod;;
		}
//	cout << fastmi(4, mod - 2) % mod << endl;
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
