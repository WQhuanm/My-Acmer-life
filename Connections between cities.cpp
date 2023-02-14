#include <bits/stdc++.h>
using namespace std;
#define ll     long long

const int N = 2e4 + 10;
int head[N << 1], cnt[N], dis[N], pre[N][32], scc[N], ct, num, n, m, c;
struct node
{
	int next, to, w;
} edge[N << 1];

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
	memset(scc, 0, sizeof(scc));
	memset(pre, 0, sizeof(pre));
	num = ct = 0;
}

void dfs(int u, int fa)
{
	scc[u] = ct;
	cnt[u] = cnt[fa] + 1;
	pre[u][0] = fa;
	for (int i = 1; (1 << i ) <= cnt[u]; ++i)pre[u][i] = pre[pre[u][i - 1]][i - 1];
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

int64_t LCA(int u, int v)
{
	if (cnt[u] != cnt[v])
		{
			if (cnt[u] > cnt[v])swap(u, v);
			int k = log2(cnt[v] - cnt[u]);
			assert(k >= 0);
			for (int i = k; i >= 0; --i)if (cnt[pre[v][i]] >= cnt[u])v = pre[v][i];
		}

	if (u == v)return v;
	int k = log2(cnt[v]);
	assert(k >= 0);
	for (int i = k; i >= 0; --i)if (pre[u][i] != pre[v][i])u = pre[u][i], v = pre[v][i];
	return pre[v][0];
}

int32_t main()
{
	int u, v, w;
	while (~scanf("%d%d%d", &n, &m, &c))
		{
			init();
			for (int i = 1; i <= m; ++i)
				{
					scanf("%d%d%d", &u, &v, &w);
					add(u, v, w), add(v, u, w);
				}
			cnt[0] = dis[0] = 0;
			for (int i = 1; i <= n; ++i)if (!scc[i])
					{
						ct++;
						dis[i] = 0;
						dfs(i, 0);
					}

			for (int i = 1; i <= c; ++i)
				{
					scanf("%d %d", &u, &v);
					if (scc[u] != scc[v])printf("Not connected\n");
					else
						{
							int lca = LCA(u, v);
							int ans = dis[u] + dis[v] - 2 * dis[lca];
							printf("%d\n", ans);
						}
				}

		}
	return 0;
}
