#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

vector<int>edge[N], eg[N];
multiset<int>val[N];
int n, m, q;
int num, cnt;
int  sz[N], dep[N], fa[N], son[N], top[N], idx[N];
int b[N];//b[]原始点的值，a[]是新编号点的值

//---------以下是线段树代码-------//
#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	int l, r;
	ll sum;
} t[N << 2];

int a[N];
inline void pushup(int p)
{
	t[p].sum = min(t[ls].sum, t[rs].sum);
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	if (l == r)
		{
			t[p].sum = a[l];
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
	pushup(p);
}
void update(int x, int p, ll w)
{
	if (t[p].l == t[p].r)
		{
			t[p].sum = w;
			return;
		}
	if (x <= mid)update(x, ls, w);
	else update(x, rs, w);
	pushup(p);
}

ll ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].sum;
	ll ans = INF;
	if (l <= mid)ans = min(ans, ask(l, r, ls));
	if (r > mid)ans = min(ans, ask(l, r, rs));
	return ans;
}

//------以上是线段树代码------//

void dfs1(int u, int f)//建树
{
	fa[u] = f;
	dep[u] = dep[f] + 1;
	sz[u] = 1, son[u] = idx[u] = 0;//初始化
	int mx = -1;

	if (u > n)
		{
			b[u] = INF;
			for (auto v : eg[u])if (v != f)val[u].insert(b[v]), b[u] = min(b[u], b[v]);
		}
	for (auto v : eg[u])if (v != f)
			{
				dfs1(v, u);
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
	for (auto v : eg[u])if (!idx[v])dfs2(v, v); //v是自己轻链的顶点
}

ll treeask(int x, int y)
{
	ll ans = INF;
	while (top[x] != top[y])
		{
			if (dep[top[x]] < dep[top[y]])swap(x, y);
			ans = min(ans, ask(idx[top[x]], idx[x], 1));
			x = fa[top[x]];
		}
	if (dep[x] > dep[y])swap(x, y);
	ans = min(ans, ask(idx[x], idx[y], 1)); //如果是边权下放到点权，出来后在同一条链上，显然，idx[x]代表的边不在需要的链上，所以要idx[x]+1
	//此时，要特判，防止idx[x]+1>idx[y]
	return ans;
}

int dfncnt, top1,  tot;
int dfn[N], low[N], sta[N];

void tarjan(int u, int f)
{
	dfn[u] = low[u] = ++dfncnt;
	sta[++top1] = u;
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
							eg[u].push_back(tot), eg[tot].push_back(u);
							while (1)
								{
									int now = sta[top1--];
									eg[now].push_back(tot), eg[tot].push_back(now);
									if (now == v)break;
								}
						}
				}
			else low[u] = min(low[u], dfn[v]);
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

void mysolve()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i)cin >> b[i];
	int x, y;
	char c;
	while (m--)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	tot = n;
	for (int i = 1; i <= n; ++i)if (!dfn[i])tarjan(i, 0);
	dfs1(1, 0);//建树
	dfs2(1, 1);//从根节点开始重新编号
	build(1, tot, 1);
	while (q--)
		{
			cin >> c >> x >> y;
			if (c == 'C')
				{
					update(idx[x], 1, y);
					if (fa[x])
						{
							int now = fa[x];
							val[now].erase(val[now].find(b[x]));
							val[now].insert(y);
							update(idx[now], 1, *val[now].begin());
						}
					b[x] = y;
				}

			else
				{
					int ans = treeask(x, y);
					int lca = LCA(x, y);
					if (lca > n)ans = min(ans, b[fa[lca]]);
					cout << ans << endl;
				}

		}
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
