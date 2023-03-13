#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1e5 + 10;

int head[N], tot[N], fa[N], son[N], dep[N], idx[N], top[N];
int a[N], b[N];
int num, cnt;
struct tree
{
	int l, r;
	int tmp, sum;
	int add;
} t[N << 2];

struct node
{
	int next, to;
} edge[N << 1];

void init()
{
	memset(head, 0, sizeof(head));
	num = cnt = 0;
}

void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

void dfs1(int u, int f)
{
	dep[u] = dep[f] + 1;
	fa[u] = f;
	tot[u] = 1;
	son[u] = idx[u] = 0;
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

void dfs2(int u, int topfa)
{
	top[u] = topfa;
	idx[u] = ++cnt;
	a[cnt] = b[u];
	if (!son[u])return;
	dfs2(son[u], topfa);
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (!idx[v])dfs2(v, v);
		}
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r, t[p].add = 0;
	if (l == r)
		{
			t[p].tmp = t[p].sum = a[l];
			return;
		}
	int mid = l + ((r - l) >> 1);
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
	t[p].tmp = t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}

void lazy(int p)
{
	if (t[p].l == t[p].r)t[p].add = 0;
	if (t[p].add == 1)
		{
			t[p << 1].add = t[p << 1 | 1].add = t[p].add;
			t[p << 1].tmp = t[p << 1 | 1].tmp = INF;
			t[p].add = 0;
		}
	else if (t[p].add == 2)
		{
			t[p << 1].add = t[p << 1 | 1].add = t[p].add;
			t[p << 1].tmp = t[p << 1].sum;
			t[p << 1 | 1].tmp = t[p << 1 | 1].sum;
			t[p].add = 0;
		}
}

int ask(int l, int r, int p, bool flag)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			if (flag)
				{
					if (t[p].tmp != INF)
						{
							t[p].add = 1;
							int tmp = t[p].tmp;
							t[p].tmp = INF;
							return tmp;
						}
					else return 0;
				}
			else
				{
					if (t[p].tmp != INF)
						{
							return 0;
						}
					else
						{
							t[p].add = 2;
							t[p].tmp = t[p].sum;
							return -t[p].sum;
						}
				}
		}
	lazy(p);
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	int ans = 0;
	if (l <= mid)ans += ask(l, r, p << 1, flag);
	if (r > mid)ans += ask(l, r, p << 1 | 1, flag);
	bool fl = 1;
	t[p].tmp = 0;
	if (t[p << 1].tmp != INF)t[p].tmp += t[p << 1].tmp, fl = 0;
	if (t[p << 1 | 1].tmp != INF)t[p].tmp += t[p << 1 | 1].tmp, fl = 0;
	if (fl)t[p].tmp = INF;
	return ans;
}

ll treeask(int x, int y)
{
	int ans = 0;
	while (top[x] != top[y])
		{
			if (dep[top[x]] < dep[top[y]])swap(x, y);
			ans += ask(idx[top[x]], idx[x], 1, 1);
			x = fa[top[x]];
		}
	if (dep[x] > dep[y])swap(x, y);
	ans += ask(idx[x], idx[y], 1, 1);
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		{
			init();
			int n, x, y;
			cin >> n;
			for (int i = 1; i <= n; ++i)cin >> b[i];
			for (int i = 1; i < n; ++i)
				{
					cin >> x >> y;
					add(x, y), add(y, x);
				}
			dfs1(1, 0);
			dfs2(1, 1);
			build(1, n, 1);
			int q, p;
			cin >> q;
			int ans = 0;

			while (q--)
				{
					cin >> p;
					if (p == 1)
						{
							cin >> x >> y;
							ans += treeask(x, y);
							cout << ans << endl;
						}
					else if (p == 2)
						{
							cin >> x;
							ans += ask(idx[x], idx[x], 1, 0);
							cout << ans << endl;
						}
					else if (p == 3)
						{
							cin >> x;
							ans += ask(idx[x], idx[x] + tot[x] - 1, 1, 1);
							cout << ans << endl;
						}
				}

		}

	return 0;
}
