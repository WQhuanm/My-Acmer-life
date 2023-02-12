#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 4e5 + 10;

int head[N], dis[N], pre[N][32], cnt[N], num, n, m;
struct node
{
	int next, to, w;
} edge[N];

void add(int u, int v, int w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;
}

void init()
{
	memset(head, 0, sizeof(head));
	num = 0;
}

void dfs(int u, int fa)
{
	cnt[u] = cnt[fa] + 1;
	pre[u][0] = fa;
	for (int i = 1; pre[u][i - 1]; ++i)pre[u][i] = pre[pre[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to, w = edge[i].w;
			if (v != fa)
				{
					dis[v] = dis[u] + w;
					dfs(v, u);
				}
		}
}

int32_t LCA(int u, int v)
{
	if (cnt[u] > cnt[v])swap(u, v);
	int k = log2(cnt[v] - cnt[u]);
	for (int i = k; i >= 0; --i)if (cnt[pre[v][i]] >= cnt[u])v = pre[v][i];
	if (u == v)return v;
	k = log2(cnt[v]);
	for (int i = k; i >= 0; --i)if (pre[u][i] != pre[v][i])u = pre[u][i], v = pre[v][i];
	return pre[v][0];
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, u, v, w;
	cin >> t;
	while (t--)
		{
			cin >> n >> m;
			init();
			for (int i = 1; i < n; ++i)
				{
					cin >> u >> v >> w;
					add(u, v, w), add(v, u, w);
				}
			dis[1] = 0;
			dfs(1, 0);
			for (int i = 1; i <= m; ++i)
				{
					cin >> u >> v;
					int lca = LCA(u, v);
					int ans = dis[u] + dis[v] - 2 * dis[lca];
					cout << ans << endl;
				}
		}
	return 0;
}
