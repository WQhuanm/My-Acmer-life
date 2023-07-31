#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 1e6 + 10;

namespace isap
{
	struct node
	{
		int next, to;
		ll w;
	} edge[N ];

	int head[N ], now[N], gap[N ], dep[N ]; //gap记录每个深度的点数
	int num = 1, s, t, tot = 0; //num初始为1
	ll ans;

	void add(int u, int v, ll w)
	{
		edge[++num].next = head[u];
		edge[num].to = v;
		edge[num].w = w;
		head[u] = num;
		//反向边
		edge[++num].next = head[v];
		edge[num].to = u;
		edge[num].w = 0;//边值初始化为0
		head[v] = num;
	}

	void bfs()
	{
		for (int i = 0; i <= tot; ++i)dep[i] = -1;
		dep[t] = 0;
		gap[0]++;
		queue<int>q;
		q.push(t);

		while (!q.empty())
			{
				int u = q.front();
				q.pop();
				for (int i = head[u]; i; i = edge[i].next)
					{
						int v = edge[i].to;
						ll w = edge[i ^ 1].w; //反向建图，但是边权要取正向边

						if (dep[v] == -1 && w)
							{
								dep[v] = dep[u] + 1;
								gap[dep[v]]++;
								q.push(v);
							}
					}
			}
	}

	ll dfs(int x, ll sum)
	{
		if (sum <= 0)return 0;
		if (x == t)
			{
				ans = (ans + sum);
				return sum;
			}
		ll k, res = 0;
		for (int i = now[x]; i; i = edge[i].next)////
			{
				now[x] = i;//当前弧优化
				int v = edge[i].to;
				ll w = edge[i].w;
				if (dep[v] == dep[x] - 1 && w)//起点到终点，深度递减
					{
						k = dfs(v, min(w, sum));
						if (k <= 0)continue;

						edge[i].w -= k;
						edge[i ^ 1].w += k;
						res = (res + k);
						sum = (sum - k);
						if (!sum)return res;//前面的流已经用完，无需遍历
					}
			}

		//跑完连接的所有点，深度+1
		gap[dep[x]]--;
		if (!gap[dep[x]])dep[s] = tot + 100; //断层
		dep[x]++;
		gap[dep[x]]++;
		return res;
	}
}

namespace tree
{
	struct node
	{
		int next, to;
		ll w;
	} edge[N];

	int num = 0, cnt = 0;
	int head[N], sz[N], dep[N], fa[N], son[N], top[N], idx[N];
	int b[N], c[N]; //b[]原始点的值，a[]是新编号点的值

	inline void add(int u, int v, int w)
	{
		edge[++num].next = head[u];
		edge[num].to = v;
		edge[num].w = w;
		head[u] = num;
	}

	//---------以下是线段树代码-------//
#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

	struct tree
	{
		int l, r;
	} t[N << 2];

	int a[N];

	void build(int l, int r, int p)
	{
		t[p].l = l, t[p].r = r;
		c[p] = ++isap::tot;
		if (l == r)
			{
				isap::add(c[p], isap::t, a[l]);
				return;
			}
		build(l, mid, ls), build(mid + 1, r, rs);
		isap::add(c[p], c[ls], INF), isap::add(c[p], c[rs], INF);
	}

	void ask(int l, int r, int p, int fr)
	{
		if (l <= t[p].l && t[p].r <= r)
			{
				isap::add(fr, c[p], INF);
				return;
			}
		if (l <= mid)ask(l, r, ls, fr);
		if (r > mid)ask(l, r, rs, fr);
	}

	//------以上是线段树代码------//

	void dfs1(int u, int f, ll w) //建树
	{
		fa[u] = f;
		dep[u] = dep[f] + 1;
		b[u] = w;
		sz[u] = 1, son[u] = idx[u] = 0;//初始化
		int mx = -1;
		for (int i = head[u]; i; i = edge[i].next)
			{
				int v = edge[i].to, w1 = edge[i].w;
				if (v == f)continue;
				dfs1(v, u, w1);
				sz[u] = (sz[u] + sz[v]);
				if (sz[v] > mx)mx = sz[v], son[u] = v;//更新重儿子
			}
	}

	void dfs2(int u, int topfa)
	{
		top[u] = topfa;//记录链顶点
		idx[u] = ++cnt;
		a[cnt] = b[u];
		if (!son[u])return;//没儿子
		dfs2(son[u], topfa);//重儿子优先编号
		for (int i = head[u]; i; i = edge[i].next)
			{
				int v = edge[i].to;
				if (!idx[v])dfs2(v, v);//v是自己轻链的顶点
			}
	}

	void treeask(int x, int y, int fr)
	{
		while (top[x] != top[y])
			{
				if (dep[top[x]] < dep[top[y]])swap(x, y);
				ask(idx[top[x]], idx[x], 1, fr);
				x = fa[top[x]];
			}
		if (dep[x] > dep[y])swap(x, y);
		ask(idx[x] + 1, idx[y], 1, fr);
	}
}

int n, m;

void mysolve()
{
	int u, v, x, y;
	cin >> n >> m;
	isap::tot = 0;
	isap::s = ++isap::tot, isap::t = ++isap::tot;
	for (int i = 1; i < n; ++i)
		{
			cin >> x >> y >> u;
			tree::add(x, y, u), tree::add(y, x, u);
		}

	tree::dfs1(1, 0, 0); //建树
	tree::dfs2(1, 1);//从根节点开始重新编号
	tree::build(1, n, 1);
	ll res = 0;
	while (m--)
		{
			cin >> u >> v >> x >> y;
			if (x - y > 0)
				{
					res += x - y;
					tree ::treeask(u, v, ++isap::tot);
					isap::add(isap::s, isap::tot, x - y);
				}
		}

	isap::ans = 0;
	isap::bfs();
	while (isap::dep[isap::s] < isap::tot   && isap::dep[isap::s] != -1) //图连通(t可以建到s)且s深度合法
		{
			for (int i = 0; i <= isap::tot + 10; ++i)isap::now[i] = isap:: head[i];
			isap::dfs(isap::s, INF);
		}
	cout << res - isap::ans << endl;
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
