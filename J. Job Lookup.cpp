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
const int N = 210;
		
int n;
ll dp[N][N];
int a[N][N], fa[N];
		
ll get_sum(int x1, int y1, int x2, int y2)
{
	if (x2 > x1 || y2 > y1)return 0;
	return a[x1][y1] - a[x2 - 1][y1] - a[x1][y2 - 1] + a[x2 - 1][y2 - 1];
}
		
void solve(int l, int r, int f)
{
	if (l > r)return;
	if (l == r)return fa[l] = f, void();
	int i = l, j = r;
	for (int k = l; k <= r; ++k)
		if (dp[l][r] == dp[i][k - 1] + dp[k + 1][j] + get_sum(k - 1, i - 1, i, 1) + get_sum(k - 1, n, i, k) + get_sum(j, k, k + 1, 1) + get_sum(j, n, k + 1, j + 1))
			{
				fa[k] = f;
				solve(l, k - 1, k), solve(k + 1, r, k);
				return;
			}
		
}
		
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)cin >> a[i][j], a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	for (int i = 1; i < n; ++i)dp[i][i + 1] = a[i][+1];
	for (int len =2; len <= n; ++len)for (int i = 1; i + len - 1 <= n; ++i)
			{
				int j = i + len - 1;
				dp[i][j] = INF;
				for (int k = i ; k <= j; ++k)dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + get_sum(k - 1, i - 1, i, 1) + get_sum(k - 1, n, i, k) + get_sum(j, k, k + 1, 1) + get_sum(j, n, k + 1, j + 1));
			}
//	cout<<dp[1][n]<<endl;
	solve(1, n, 0);
	for (int i = 1; i <= n; ++i)cout << fa[i] << " \n"[i == n];
		
}
		
signed main()
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
