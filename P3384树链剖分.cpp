#include <bits/stdc++.h>
using namespace std;
#define ll     long long
//#define int ll
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1e5 + 10;

int a[N], b[N], n, m, r, mod, num, head[N << 1], tot[N], dep[N], fa[N], son[N], cnt, topfa[N], idx[N];
struct tree
{
	int l, r;
	ll sum, add;
} t[4 * N + 2];

struct node
{
	int next, to;
} edge[N << 1];

void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

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
	if (l <= t[p].l && t[p].r <= r)	return t[p].sum % mod;

	lazy(p);
	ll ans = 0;
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (l <= mid)ans = (ans + ask(l, r, p << 1)) % mod;
	if (r > mid)ans = (ans + ask(l, r, p << 1 | 1)) % mod;
	return ans;
}

void dfs1(int u, int f)
{
	dep[u] = dep[f] + 1;
	fa[u] = f;
	tot[u] = 1;
	int maxn = -1;
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (v == f)continue;
			dfs1(v, u);
			tot[u] += tot[v];
			if (tot[v] > maxn)maxn = tot[v], son[u] = v;
		}
}

void dfs2(int u, int topf)
{
	idx[u] = ++cnt;
	a[cnt] = b[u];
	topfa[u] = topf;
	if (!son[u])return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (!idx[v])dfs2(v, v);
		}
}

void treeadd(int x, int y, ll z)
{
	while (topfa[x] != topfa[y])
		{
			if (dep[topfa[x]] < dep[topfa[y]])swap(x, y);////
			update(idx[topfa[x]], idx[x], 1, z);
			x = fa[topfa[x]];
		}
	if (dep[x] > dep[y])swap(x, y);
	update(idx[x], idx[y], 1, z);
}

ll treesum(int x, int y)
{
	ll ans = 0;
	while (topfa[x] != topfa[y])
		{
			if (dep[topfa[x]] < dep[topfa[y]])swap(x, y);
			ans = (ans + ask(idx[topfa[x]], idx[x], 1)) % mod;
			x = fa[topfa[x]];
		}
	if (dep[x] > dep[y])swap(x, y);
	ans = (ans + ask(idx[x], idx[y], 1)) % mod;
	return ans;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> r >> mod;
	for (int i = 1; i <= n; ++i)cin >> b[i];
	int x, y;
	for (int i = 1; i < n; ++i)
		{
			cin >> x >> y;
			add(x, y), add(y, x);
		}
	dfs1(r, 0);
	dfs2(r, r);
	build(1, n, 1);
	ll a1, z;
	for (int i = 1; i <= m; ++i)
		{
			cin >> a1;
			if (a1 == 1)
				{
					cin >> x >> y >> z;
					treeadd(x, y, z % mod);
				}
			else if (a1 == 2)
				{
					cin >> x >> y;
					cout << treesum(x, y) << endl;
				}
			else if (a1 == 3)
				{
					cin >> x >> z;
					update(idx[x], idx[x] + tot[x] - 1, 1, z % mod);
				}
			else if (a1 == 4)
				{
					cin >> x;
					cout << ask(idx[x], idx[x] + tot[x] - 1, 1) << endl;
				}
		}
	return 0;
}
