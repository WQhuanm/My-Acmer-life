#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 5e3 + 10;

int n, m;
int sta[N], dfn[N], head[N], in[N], scc[N], low[N], hd[N], ct[N];
bool insta[N], vis[N], du[N];
int num, cnt, dfncnt, top, num1;
struct node
{
	int next, to;
} edge[30005], eg[30005];

void init()
{
	memset(dfn, 0, sizeof(dfn));
	memset(head, 0, sizeof(head));
	memset(hd, 0, sizeof(hd));
	memset(du, 0, sizeof(du));
	memset(in, 0, sizeof(in));
//	memset(scc, 0, sizeof(scc));
	memset(edge, 0, sizeof(edge));
	memset(eg, 0, sizeof(eg));
	memset(ct, 0, sizeof(ct));
	num = top = cnt = dfncnt = num1 = 0;
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
			else if (insta[v])low[u] = min(dfn[v], low[u]);
		}
	if (dfn[u] == low[u])
		{
			++cnt;
			while (1)
				{
					int v = sta[top--];
					insta[v] = 0;
					++ct[cnt];
					scc[v] = cnt;
					if (u == v)break;
				}
		}
}

int dfs(int u)
{
	int sum = ct[u];
	for (int i = hd[u]; i; i = eg[i].next)
		{
			int v = eg[i].to;
			if (!vis[v])
				{
					vis[v] = 1;
					sum += dfs(v);
				}
		}
	return sum;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, t1 = 0;
	cin >> t;
	while (t--)
		{
			init();
			++t1;
			cin >> n >> m;
			int x, y;
			for (int i = 1; i <= m; ++i)
				{
					cin >> x >> y;
					add(x, y);
				}
			for (int i = 0; i < n; ++i)if (!dfn[i])tarjan(i);

			for (int i = 0; i < n; ++i)
				{
					int u = scc[i];
					for (int j = head[i]; j; j = edge[j].next)
						{
							int v = scc[edge[j].to];
							if (u != v)add1(v, u), du[u] = 1;
						}
				}
			int ans = -1;
			for (int i = 1; i <= cnt; ++i)
				{
					if (!du[i])
						{
							memset(vis, 0, sizeof(vis));
							vis[i] = 1;
							in[i] = dfs(i) - 1;
							ans = max(ans, in[i]);
						}
				}
			cout << "Case " << t1 << ": " << ans << endl;
			//	printf("Case %d: %d\n", t1, ans);
			bool flag = 1;
			for (int i = 0; i < n; ++i)
				{
					if (in[scc[i]] == ans)
						{
							if (flag)flag = 0, cout << i;
							else cout << ' ' << i;
						}
				}
			cout << endl;
		}
	return 0;
}
