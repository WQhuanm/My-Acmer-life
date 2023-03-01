#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
const int N = 1e5 + 10;

int n, m, r, mod, num, cnt;
int head[N], tot[N], dep[N], fa[N], son[N], top[N], idx[N];
int a[N], b[N];
struct node
{
	int next, to;
} edge[N << 1];
struct tree
{
	int l, r;
	int sum, add;
} t[4 * N + 2];

void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

void dfs1(int u, int f)
{
	fa[u] = f;//存储u点父亲
	dep[u] = dep[f] + 1;//深度是父亲深度+1
	tot[u] = 1, son[u] = idx[u] = 0;//tot是子节点（包括自己）的数量，son是重儿子，idx是u的重新编号，对这3个初始化
	int maxn = -1;
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (v == f)continue;
			dfs1(v, u);
			tot[u] += tot[v];//增加u的子节点数
			if (tot[v] > maxn)maxn = tot[v], son[u] = v;//更新重儿子
		}
}

void dfs2(int u, int topfa)
{
	top[u] = topfa;//记录链顶点
	idx[u] = ++cnt;//新编号，从根节点的1不断编号
	a[cnt] = b[u];//把原来编号的值存入新编号的值
	if (!son[u])return;//如果没用儿子就不用往下
	dfs2(son[u], topfa);//有儿子先访问重儿子（重儿子优先编号）
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (!idx[v])dfs2(v, v);//idx为0，说明没用编号（也说明一定不是重儿子），进行编号，v自己是轻链顶点
		}
}

//---------以下是线段树代码-------//
void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	if (l == r)
		{
			t[p].sum = a[l] % mod;
			return;
		}
	int mid = l + ((r - l) >> 1);
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
	t[p].sum = (t[p << 1].sum + t[p << 1 | 1].sum) % mod;
}

void lazy(int p)
{
	if (t[p].l == t[p].r)t[p].add = 0;
	if (t[p].add)
		{
			t[p << 1].sum = (t[p << 1].sum + t[p].add * (t[p << 1].r - t[p << 1].l + 1)) % mod;
			t[p << 1 | 1].sum = (t[p << 1 | 1].sum + t[p].add * (t[p << 1 | 1].r - t[p << 1 | 1].l + 1)) % mod;
			t[p << 1].add = (t[p << 1].add + t[p].add) % mod;
			t[p << 1 | 1].add = (t[p << 1 | 1].add + t[p].add) % mod;
			t[p].add = 0;
		}
}

void update(int l, int r, int p, ll z)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			t[p].sum = (t[p].sum + z * (t[p].r - t[p].l + 1)) % mod;
			t[p].add = (t[p].add + z) % mod;
			return;
		}
	lazy(p);
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (l <= mid)update(l, r, p << 1, z);
	if (r > mid)update(l, r, p << 1 | 1, z);
	t[p].sum = (t[p << 1].sum + t[p << 1 | 1].sum) % mod;
}

ll ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].sum % mod;
	lazy(p);
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	ll ans = 0;
	if (l <= mid)ans = (ans + ask(l, r, p << 1)) % mod;
	if (r > mid)ans = (ans + ask(l, r, p << 1 | 1)) % mod;
	return ans;
}
//------以上是线段树代码------//

void treeadd(int x, int y, ll z)
{
	while (top[x] != top[y])//不是同一条链，就更新到是为止
		{
			if (dep[top[x]] < dep[top[y]])swap(x, y);//为了方便，始终保持x所在链的顶点深度大（注意，比较的是顶点深度，不是x与y深度
			update(idx[top[x]], idx[x], 1, z);//链是连续区间，直接线段树更新
			x = fa[top[x]];//x成为顶点父亲
		}
	if (dep[x] > dep[y])swap(x, y);//出来后，为了方便，让x深度小，因为我们的线段树必须更新小编号到大编号
	update(idx[x], idx[y], 1, z);
}

ll treeask(int x, int y)
{
	ll ans = 0;
	while (top[x] != top[y])//不是同一条链，就不断累加经过的链的区间的值
		{
			if (dep[top[x]] < dep[top[y]])swap(x, y);
			ans = (ans + ask(idx[top[x]], idx[x], 1)) % mod;
			x = fa[top[x]];
		}
	if (dep[x] > dep[y])swap(x, y);
	ans = (ans + ask(idx[x], idx[y], 1)) % mod;
	return ans % mod;
}
//这模板题用不到
ll lca(int u, int v)
{
	while (top[u] != top[v])
		{
			if (dep[top[u]] > dep[top[v]])u = fa[top[u]];//所在链顶点深度大的求往祖先跳
			else v = fa[top[v]];
		}
	return dep[u] > dep[v] ? v : u;
}

int32_t main()
{
	cin >> n >> m >> r >> mod;
	for (int i = 1; i <= n; ++i)cin >> b[i];
	int h, x, y, z;
	for (int i = 1; i < n; ++i)
		{
			cin >> x >> y;
			add(x, y), add(y, x);
		}
	dfs1(r, 0);
	dfs2(r, r);
	build(1, n, 1);
	while (m--)
		{
			cin >> h;
			if (h == 1)
				{
					cin >> x >> y >> z;
					treeadd(x, y, z);
				}
			else if (h == 2)
				{
					cin >> x >> y;
					cout << treeask(x, y) << endl;
				}
			else if (h == 3)
				{
					cin >> x >> z;
					update(idx[x], idx[x] + tot[x] - 1, 1, z);
				}
			else if (h == 4)
				{
					cin >> x;
					cout << ask(idx[x], idx[x] + tot[x] - 1, 1) << endl;
				}
		}
	return 0;
}
