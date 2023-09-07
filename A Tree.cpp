#include <bits/stdc++.h>
using namespace std;
//#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 3e3 + 10;

int n;
int a[N], cost[N], fa[N], sz[N];
struct node
{
	int u, v, w;
	bool operator<(const node&k)const
	{
		return w < k.w;
	}
} edge[N];
ll dp[N][N];

int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}

void merge(int u, int v, int w)
{
	u = find(u), v = find(v);
	if (sz[u] < sz[v])swap(u, v);
	fa[v] = u;
	vector<ll>tmp(sz[u] + sz[v] + 1, -inf);
	for (int i = 0; i <= sz[u]; ++i)for (int j = 0; j <= sz[v]; ++j)
			tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v][j] + (ll)w * (i * (sz[v] - j) + (sz[u] - i) * j));
	sz[u] += sz[v];
	for (int i = 0; i <= sz[u]; ++i)dp[u][i] = tmp[i];
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i], fa[i] = i, sz[i] = 1;
	for (int i = 1; i <= n; ++i)cin >> cost[i], dp[i][a[i]] = 0, dp[i][a[i] ^ 1] = -cost[i];
	for (int i = 1; i < n; ++i)cin >> edge[i].u >> edge[i].v >> edge[i].w;
	sort(edge + 1, edge + n);
	for (int i = 1; i < n; ++i)
		{
			merge(edge[i].u, edge[i].v, edge[i].w);
		}
	int rt = find(1);
	ll ans = -inf;
	for (int i = 0; i <= n; ++i)ans = max(ans, dp[rt][i]);
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
