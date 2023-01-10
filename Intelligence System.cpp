#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 5e4 + 10;

int sta[N], dfn[N], low[N], scc[N], head[N], hd[N];
ll sum[105][105], dis[N];
bool insta[N], vis[N], in[N];
int num, cnt, dfncnt, top, ct, num1;
struct node
{
	int to, next;
	ll t;
} edge[N << 1], eg[N << 1];

void init()
{
	num = cnt = dfncnt = top = ct = num1 = 0;
	memset(head, 0, sizeof(head));
	memset(dfn, 0, sizeof(dfn));
	memset(hd, 0, sizeof(hd));
	memset(vis, 0, sizeof(vis));
	memset(sum, 0x3f, sizeof(sum));
	memset(dis, 0x3f, sizeof(dis));
	memset(in, 0, sizeof(in));
}

void add(int u, int v, ll t)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].t = t;
	head[u] = num;
}

void add1(int u, int v, ll t)
{
	eg[++num1].next = hd[u];
	eg[num1].to = v;
	eg[num].t = t;
	hd[u] = num1;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++dfncnt;
	insta[u] = 1;
	sta[++top] = u;
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (!dfn[v])
				{
					tarjan(v);
					low[u] = min(low[u], low[v]);
				}
			else if (insta[v])low[u] = min(dfn[v], low[u]);
		}
	if (low[u] == dfn[u])
		{
			++cnt;
			while (1)
				{
					int v = sta[top--];
					scc[v] = cnt;
					insta[v] = 0;
					if (u == v)break;
				}
		}
}

void dfs(int u)
{
	vis[u] = 1;
	for (int i = hd[u]; i; i = eg[i].next)
		{
			int v = eg[i].to;
			dis[v] = min(dis[v], sum[u][v]);
			if (!vis[v])dfs(v);
		}
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, x, y, n, m;

	while (	cin >> n >> m)
		{
			init();
			for (int i = 1; i <= m; ++i)cin >> x >> y >> t, add(x, y, t);
			for (int i = 0; i < n; ++i)if (!dfn[i])tarjan(i);
			for (int i = 0; i < n; ++i)
				{
					int u = scc[i];
					for (int j = head[i]; j; j = edge[j].next)
						{
							int v = scc[edge[j].to];
							if (u != v)sum[u][v] = min(sum[u][v], edge[j].t), add1(u, v, edge[j].t), in[v] = 1;
						}
				}
			int str;
			for (int i = 1; i <= cnt; ++i)if (!in[i])
					{
						str = i;
						break;
					}
			dis[str] = 0;
			dfs(str);
			ll ans = 0;
			for (int i = 1; i <= cnt; ++i)ans += dis[i];
			cout << ans << endl;
		}
}
