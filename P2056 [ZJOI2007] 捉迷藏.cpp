#include <bits/stdc++.h>
using namespace std;
#define endl             "\n"
const int N = 1e5 + 10;

int n, rt, sum_sz, cnt;
bool vis[N];
int mx[N], sz[N], dep[N], rfa[N], fa[N], top[N], idx[N], son2[N];
int a[N], val[N];
priority_queue<int>b[2][N], dis[2][N], son[2][N];
int tp[N];
vector<int>edge[N];

void get_rt(int u, int f)//获取当前子树重心rt
{
	sz[u] = 1, mx[u] = 0;
	for (auto v : edge[u])if (!vis[v] && v != f)
			{
				get_rt(v, u);
				sz[u] += sz[v];
				mx[u] = max(mx[u], sz[v]);
			}
	mx[u] = max(mx[u], sum_sz - sz[u]);
	if (mx[u] <= mx[rt])rt = u;
}

void dfs1(int u, int f)//建树
{
	fa[u] = f, dep[u] = dep[f] + 1;
	sz[u] = 1, son2[u] = idx[u] = 0;//初始化
	int mx = -1;
	for (auto v : edge[u])if (v != f)
			{
				dfs1(v, u);
				sz[u] = (sz[u] + sz[v]);
				if (sz[v] > mx)mx = sz[v], son2[u] = v;//更新重儿子
			}
}

void dfs2(int u, int topfa)
{
	top[u] = topfa;//记录链顶点
	idx[u] = ++cnt;
	if (!son2[u])return;//没儿子
	dfs2(son2[u], topfa);//重儿子优先编号
	for (auto v : edge[u])
		{
			if (!idx[v])dfs2(v, v);//v是自己轻链的顶点
		}
}

int LCA(int u, int v)
{
	while (top[u] != top[v])
		{
			if (dep[top[u]] > dep[top[v]])u = fa[top[u]];
			else v = fa[top[v]];
		}
	return dep[u] > dep[v] ? v : u;//深度小的是lca
}

inline int get_dis(int x, int y)//获得原树两点距离
{
	return dep[x] + dep[y] - 2 * dep[LCA(x, y)];
}

void re_tree(int u)
{
	vis[u] = 1, val[u] = tp[u] = -1;
	for (auto v : edge[u])if (!vis[v])
			{
				rt = 0, sum_sz = sz[v];
				get_rt(v, 0), get_rt(rt, 0);
				rfa[rt] = u;//rfa记录重构树rt的父亲
				re_tree(rt);
			}
}

void update(int u)
{
	for (int i = u; i; i = rfa[i])
		{
			if (~val[i] && rfa[i])
				{
					if (son[0][rfa[i]].top() == val[i])
						{
							son[0][rfa[i]].pop();
							while (!son[1][rfa[i]].empty() && son[1][rfa[i]].top() == son[0][rfa[i]].top())son[0][rfa[i]].pop(), son[1][rfa[i]].pop();
						}
					else son[1][rfa[i]].push(val[i]);
				}
			val[i] = -1;
			if (i == u)
				{
					if (a[u])
						{
							val[u] = 0;
							if (0 > tp[u])tp[u] = 0;
							else b[0][u].push(0);
						}
					else
						{
							val[u] = -1;
							if (!tp[u])tp[u] = -1;
							else
								{
									if (!b[0][u].top())
										{
											b[0][u].pop();
											while (!b[1][u].empty() && b[0][u].top() == b[1][u].top())b[0][u].pop(), b[1][u].pop();
										}
									else b[1][u].push(0);
								}
						}
				}
			if (!son[0][i].empty())val[i] = max(val[i], son[0][i].top());
			if (!b[0][i].empty())
				{
					val[i] = max(val[i], tp[i] + b[0][i].top());
				}
			if (rfa[i])
				{
					int d = get_dis(u, rfa[i]), now = rfa[i];
					if (!dis[0][i].empty())
						{
							if (tp[now] == dis[0][i].top())
								{
									if (!b[0][now].empty())
										{
											tp[now] = b[0][now].top(), b[0][now].pop();
											while (!b[1][now].empty() && b[0][now].top() == b[1][now].top())b[0][now].pop(), b[1][now].pop();
										}
									else tp[now] = -1;
								}
							else if (b[0][now].top() == dis[0][i].top())
								{
									b[0][now].pop();
									while (!b[1][now].empty() && b[0][now].top() == b[1][now].top())b[0][now].pop(), b[1][now].pop();
								}
							else b[1][now].push(dis[0][i].top());
						}
					if (a[u])dis[0][i].push(d);
					else
						{
							if (d == dis[0][i].top())
								{
									dis[0][i].pop();
									while (!dis[1][i].empty() && dis[0][i].top() == dis[1][i].top())dis[0][i].pop(), dis[1][i].pop();
								}
							else dis[1][i].push(d);
						}
					if (!dis[0][i].empty())
						{
							if (dis[0][i].top() > tp[now])
								{
									if (~tp[now])b[0][now].push(tp[now]);
									tp[now] = dis[0][i].top();
								}
							else b[0][now].push(dis[0][i].top());
						}
					if (~val[i])son[0][now].push(val[i]);
				}
		}
}

void mysolve()
{
	cin >> n;
	int x, y;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	dfs1(1, 0), dfs2(1, 1);
	mx[rt = 0] = 1e9, sum_sz = n;
	get_rt(1, 0), get_rt(rt, 0), rfa[rt] = 0;
	int now = rt;
	re_tree(rt);
	for (int i = 1; i <= n; ++i)
		a[i] = 1, update(i);
	int q;
	cin >> q;
	char c;
	while (q--)
		{
			cin >> c;
			if (c == 'C')
				{
					cin >> x;
					a[x] ^= 1;
					update(x);
				}
			else cout << val[now] << endl;
		}
}

signed main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	return 0;
}
