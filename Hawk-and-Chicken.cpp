#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 5e3 + 10;

int sta[N], scc[N], dfn[N], low[N], head[N], hd[N], sum[N], sz[N];
bool insta[N], in[N], vis[N];
int num, cnt, dfncnt, top, num1;
struct node
{
	int to, next;
} edge[30005], eg[30005];

void init()
{
	memset(head, 0, sizeof(head));
	memset(hd, 0, sizeof(hd));
	memset(dfn, 0, sizeof(dfn));
	memset(in, 0, sizeof(in));
	memset(sum, 0, sizeof(sum));//////////
	num = num1 = top = dfncnt = cnt = 0;
}

void add(int u, int v)//正向建图
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

void add1(int u, int v)//反向建图
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
			sz[cnt] = 0;//sz数组存储每个环内点的数量，一个环（x人）给人的票一次就是x，自己内部赞赏是x-1
			while (1)
				{
					int v = sta[top--];
					insta[v] = 0;
					scc[v] = cnt;
					++sz[cnt];
					if (u == v)break;
				}
		}
}

int dfs(int u)//求指向u的票，只需要u自己内部赞同票加上他指向的点所获得的票
{
	vis[u] = 1;
	int ans = sz[u];
	for (int i = hd[u]; i; i = eg[i].next)
		{
			int v = eg[i].to;
			if (!vis[v])ans += dfs(v);
		}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, t1 = 0, n, m, x, y;
	cin >> t;

	while (t--)
		{
			++t1;
			init();
			cin >> n >> m;
			for (int i = 1; i <= m; ++i)cin >> x >> y, add(x, y);
			for (int i = 0; i < n; ++i)if (!dfn[i])tarjan(i);
			for (int i = 0; i < n; ++i)
				{
					int u = scc[i];
					for (int j = head[i]; j; j = edge[j].next)
						{
							int v = scc[edge[j].to];
							if (u != v)add1(v, u), in[u] = 1;//反向建环的图
						}
				}
			int ans = -1;
			for (int i = 1; i <= cnt; ++i)
				{
					if (!in[i])	memset(vis, 0, sizeof(vis)), sum[i] = dfs(i) - 1, ans = max(ans, sum[i]);//没有被指向的，每次重置标记，求其值，最后sum-1，就是因为环内部认同是x-1
				}
			cout << "Case " << t1 << ": " << ans << endl;
			bool flag = 1;
			for (int i = 0; i < n; ++i)
				{
					if (sum[scc[i]] == ans)
						{
							if (flag)flag = 0, cout << i;
							else cout << ' ' << i;
						}
				}
			cout << endl;
		}
	return 0;
}
