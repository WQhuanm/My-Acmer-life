#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 5e3 + 10;

int sta[N], head[N], hd[N], dfn[N], low[N], scc[N], match[N];
bool insta[N], vis[N];
int num, num1, top, dfncnt, cnt;
struct node
{
	int to, next;
} edge[N * 20 ], eg[N * 20 ];

void init()
{
	memset(dfn, 0, sizeof(dfn));
	memset(head, 0, sizeof(head));
	memset(hd, 0, sizeof(hd));
	memset(match, 0, sizeof(match));
	memset(vis, 0, sizeof(vis));
	num = num1 = top = cnt = dfncnt = 0;
}

void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

void add1(int u, int v)
{
	eg[++num1].next = hd[u];
	eg[num1].to = v;
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
			else if (insta[v])low[u] = min(low[u], dfn[v]);
		}
	if (low[u] == dfn[u])
		{
			++cnt;
			while (1)
				{
					int v = sta[top--];
					insta[v] = 0;
					scc[v] = cnt;
					if (u == v)break;
				}
		}
}

int tfind(int u)
{
	for (int i = hd[u]; i; i = eg[i].next )
		{
			int v = eg[i].to;
			if (!vis[v])
				{
					vis[v] = 1;
					if (!match[v] || tfind(match[v]))
						{
							match[v] = u;
							return 1;
						}
				}
		}
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, n, m, x, y;
	cin >> t;
	while (t--)
		{
			init();
			cin >> n >> m;
			for (int i = 1; i <= m; ++i)cin >> x >> y, add(x, y);
			for (int i = 1; i <= n; ++i)if (!dfn[i])tarjan(i);
			for (int i = 1; i <= n; ++i)
				{
					int u = scc[i];
					for (int j = head[i]; j; j = edge[j].next)
						{
							int v = scc[edge[j].to];
							if (u != v)add1(u, v);
						}
				}
			//cout << cnt;
			int ans = 0;
			for (int i = 1; i <= cnt; ++i)ans += tfind(i);
			cout << cnt - ans << endl;
		}
	return 0;
}

