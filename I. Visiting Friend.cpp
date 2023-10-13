#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 1e6 + 10;

const int lg = 20;
int n, m;
int dfncnt, top, tot;
int dfn[N], low[N], sta[N];
int sz[N], pre[N][30], dep[N];
vector<int> edge[N], eg[N];

void init()
{
	dfncnt = 0;
	for (int i = 0; i <= n; ++i)dfn[i] = 0, edge[i].clear();
	for (int i = 1; i <= tot; ++i)eg[i].clear();
	tot = n;
}

void tarjan(int u, int f)
{
	dfn[u] = low[u] = ++dfncnt;
	sta[++top] = u;
	bool fl = 1;
	for (int v : edge[u])
		{
			if (v == f && fl)
				{
					fl = 0;
					continue;
				}
			if (!dfn[v])
				{
					tarjan(v, u);
					low[u] = min(low[u], low[v]);
					if (low[v] >= dfn[u])
						{
							++tot;
							while (1)
								{
									int now = sta[top--];
									eg[tot].push_back(now), eg[now].push_back(tot);
									if (v == now)break;
								}
							eg[tot].push_back(u), eg[u].push_back(tot);
						}
				}
			else low[u] = min(low[u], dfn[v]);
		}
}

void pre_dfs(int u, int f)
{
	sz[u] = u <= n ;
	pre[u][0] = f, dep[u] = dep[f] + 1;
	for (int i = 1; i <= lg; ++i)
		{
			pre[u][i] = pre[pre[u][i - 1]][i - 1];
		}
	for (int v : eg[u])if (v != f)
			{
				pre_dfs(v, u);
				sz[u] += sz[v];
			}
}

inline int LCA(int u, int v)
{
	if (dep[v] != dep[u])//不相等时才求，否则出现log2(0)
		{
			if (dep[u] < dep[v])swap(u, v); //始终让u深度大
			for (int i = lg; ~i; --i)if (dep[pre[u][i]] >= dep[v])u = pre[u][i];
		}
	if (u == v)return u;
	for (int i = lg; ~i; --i)
		{
			if (pre[u][i] != pre[v][i])
				{
					u = pre[u][i];
					v = pre[v][i];
				}
		}
	return pre[u][0];//儿子的父亲才是LCA
}

void mysolve()
{
	cin >> n >> m;
	init();
	int x, y;
	while (m--)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	for (int i = 1; i <= n; ++i)if (!dfn[i])top = 0, tarjan(i, 0); //每次dfs，栈没有完全退完的
	pre_dfs(1, 0);
	int q;
	cin >> q;
	while (q--)
		{
			cin >> x >> y;
			if (dep[x] < dep[y])swap(x, y);
			int lca = LCA(x, y);
			if (lca == y)
				{
					int fx = x;
					for (int i = lg; ~i; --i)if (dep[pre[fx][i]] > dep[y])fx = pre[fx][i];
					cout << sz[fx] - sz[x] + 2 << endl;
				}
			else cout << n - sz[x] - sz[y] + 2 << endl;
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	return 0;
}
