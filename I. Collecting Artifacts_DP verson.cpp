#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
typedef pair<int, int> pii;
const int N = 1e5 + 10;
const int mod = 998244353;

vector<pii>edge[N];
ll dp[N][1 << 6][3], tmp[1 << 6][3];
int a[N];
int n, k;
ll ans = INF;

void dfs(int u, int f)
{
	for (int i = 0; i < 3; ++i)dp[u][a[u]][i] = dp[u][0][i] = 0;
	for (auto [v, w] : edge[u])if (v != f)
			{
				dfs(v, u);
				memset(tmp, 0x3f, sizeof(tmp));
				for (int i = 1; i < (1 << k); ++i)for (int j = i; ; j = i & (j - 1))
						{
							tmp[i][0] = min(tmp[i][0], dp[v][j][0] + dp[u][i ^ j][0] + 2 * w);

							tmp[i][1] = min(tmp[i][1], dp[v][j][1] + dp[u][i ^ j][0] + w);
							tmp[i][1] = min(tmp[i][1], dp[v][j][0] + dp[u][i ^ j][1] + 2 * w);

							tmp[i][2] = min({tmp[i][2], dp[v][j][2] + dp[u][j ^ i][0] + 2 * w, dp[v][j][0] + dp[u][i ^ j][2] + 2 * w, dp[v][j][1] + dp[u][j ^ i][1] + w});
							if (!j)break;
						}
				for (int i = 1; i < (1 << k); ++i)for (int j = 0; j < 3; ++j)dp[u][i][j] = min(dp[u][i][j], tmp[i][j]);
			}
	ans = min(ans, dp[u][(1 << k) - 1][2]);
}

void mysolve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			if (a[i])a[i] = 1 << (a[i] - 1);
		}
	int x, y, w;
	for (int i = 1; i < n; ++i)cin >> x >> y >> w, edge[x].push_back({y, w}), edge[y].push_back({x, w});
	memset(dp, 0x3f, sizeof(dp));
	dfs(1, 0);
	cout << (ans < INF ? ans : -1) << endl;
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
