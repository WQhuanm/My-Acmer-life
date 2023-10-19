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
const int N = 3e5 + 10;

int dp[N][2];
int s[N];
vector<pii>edge[N];
bool vis[N];
ll sum[N];
int n;

int cnt;
ll ans;
void dfs(int u)
{
	vis[u] = 1;
	for (auto [v, w] : edge[u])
		{
			if (w)cnt = (cnt + 1) % mod;
			else ans = (ans + cnt) % mod;
			if (!vis[v])dfs(v);
			else
				{
					ans = (ans + sum[v] + cnt * dp[v][0] % mod) % mod;
					cnt = (cnt + dp[v][1]) % mod;
				}
			dp[u][1] = (dp[u][1] + w) % mod;
			sum[u] = (sum[u] + sum[v] + dp[v][0] * dp[u][1] % mod) % mod;
			if (!w)sum[u] = (sum[u] + dp[u][1]) % mod;
			dp[u][0] = (dp[u][0] + dp[v][0] + !w) % mod;
			dp[u][1] = (dp[u][1] + dp[v][1]) % mod;
		}
}

void mysolve()
{
	cin >> n;
	int x, y;
	for (int i = 1; i <= n; ++i)
		{
			cin >> s[i];
			for (int j = 1; j <= s[i]; ++j)cin >> x >> y, edge[i].push_back({x, y});
		}
	dfs(1);
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
