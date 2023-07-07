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
const int N = 110;
const int mod = 998244353;

int dp[N][N];
bool vis[N];
void mysolve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)if (i != j)dp[i][j] = INF;
	int x, y, w;
	while (m--)
		{
			cin >> x >> y >> w;
			dp[x][y] = dp[y][x] = min(dp[x][y], w);
		}
	for (int k = 1; k <= n; ++k)for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	if (dp[1][n] > 1e18)
		{
			cout << "inf" << endl;
			return;
		}

	vector<pii>v(n + 1);
	for (int i = 1; i <= n; ++i)v[i] = { dp[1][i], i};
	sort(v.begin() + 1, v.end());
	vis[1] = 1;
	string s(n, '0');
	ll sum = 0;
	vector<pair<string, int>>ans;
	for (int i = 1; i < (int)v.size() - 1; ++i)
		{
			int u = v[i].second, p = v[i + 1].second;
			if (u == n)break;
			s[u - 1] = '1';
			int t = dp[1][p] - dp[1][u];
			sum += t;
			if (t)
				ans.push_back({s, t});
		}
	cout << sum << " " << (int)ans.size() << endl;
	for (auto [val, k] : ans)
		{
			cout << val << " " << k << endl;
		}
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
