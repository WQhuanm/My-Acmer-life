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
const int N = 510;

int n;
int son[N], sz[N];
ll dp[N][N], pre[N], p[N];
vector<int>edge[N];

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

void pre_dfs(int u, int fa)
{
	p[u] = sz[u] = 1, son[u] = 0;
	for (auto v : edge[u])if (v != fa)
			{
				pre_dfs(v, u);
				son[u]++, sz[u] += sz[v];
				p[u] = p[u] * p[v] % mod * pre[son[v]] % mod;
			}
}

void dfs(int u, int fa)
{
	vector f(son[u] + 1, vector<ll>(sz[u] + 1));
	f[0][0] = 1;
	ll base = fastmi(p[u] * pre[son[u]] % mod, mod - 2);
	for (auto v : edge[u])if (v != fa)//pre all son
			{
				for (int i = son[u]; i; --i)for (int j = sz[u] - 1; j >= sz[v]; --j)
						f[i][j] = (f[i][j] + f[i - 1][j - sz[v]]) % mod;
			}
	for (auto v : edge[u])if (v != fa)
			{
				for (int i = 1; i <= son[u]; ++i)for (int j = sz[v]; j <= sz[u] - 1; ++j)//del v
						f[i][j] = (f[i][j] - f[i - 1][j - sz[v]] + mod) % mod;

				vector<ll>g(sz[u] + 1);
				for (int i = 0; i < sz[u]; ++i)for (int j = 0; j < son[u]; ++j)
						g[i] = (g[i] + f[j][i] * pre[son[u] - j - 1] % mod * pre[j] % mod) % mod;

				for (int i = 1; i < n; ++i)for (int j = i + 1; j <= n; ++j)if (dp[u][i]&&j-i-1<sz[u])
							dp[v][j] = (dp[v][j] + dp[u][i] * p[u] % mod * g[j - i - 1] % mod * base % mod) % mod;
				for (int i = son[u]; i; --i)for (int j = sz[u] - 1; j >= sz[v]; --j)
						f[i][j] = (f[i][j] + f[i - 1][j - sz[v]]) % mod;
			}
	for (auto v : edge[u])if (v != fa)
			dfs(v, u);
}

void mysolve()
{
	cin >> n;
	int x, y;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	pre_dfs(1, 0);
	dp[1][1] = p[1] * pre[son[1]] % mod;
	dfs(1, 0);
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)cout << dp[i][j] << " \n"[j == n];
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	pre[0] = 1;
	for (int i = 1; i <= N - 5; ++i)pre[i] = pre[i - 1] * i % mod;
//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
