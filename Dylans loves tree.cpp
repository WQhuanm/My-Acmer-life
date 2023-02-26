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
const int M = 1e6;

struct tree
{
	int l, r;
	ll sum;
} t[4 * N + 2];
struct node
{
	int next, to;
} edge[N << 1];
int head[N << 1], son[N], fa[N], topf[N], tot[N], a[N], b[N], dep[N], idx[N];
int n, m, num, cnt;
void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}
void init()
{
	memset(head, 0, sizeof(head));
	memset(son, 0, sizeof(son));
	memset(idx, 0, sizeof(idx));
	cnt = num = 0;
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	if (l == r)
		{
			t[p].sum = a[l];
			return;
		}
	int mid = l + ((r - l) >> 1);
	build(l, mid, p << 1), build(mid + 1, r, p << 1 | 1);
	t[p].sum = t[p << 1].sum ^ t[p << 1 | 1].sum;
}

void update(int l, int r, int p, int z)
{
	if (l == t[p].l && t[p].r == r)
		{
			t[p].sum = z;
			return;
		}
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (l <= mid)update(l, r, p << 1, z);
	if (r > mid)update(l, r, p << 1 | 1, z);
	t[p].sum = t[p << 1].sum ^ t[p << 1 | 1].sum;
}

int ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].sum;
	ll ans = 0;
	int mid = (t[p].l) + ((t[p].r - t[p].l) >> 1);
	if (l <= mid)ans ^= ask(l, r, p << 1);
	if (r > mid)ans ^= ask(l, r, p << 1 | 1);
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

void dfs2(int u, int tf)
{
	topf[u] = tf;
	idx[u] = ++cnt;
	a[cnt] = b[u];
	if (!son[u])return;
	dfs2(son[u], tf);
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (!idx[v])dfs2(v, v);
		}
}

int  treeadd(int x, int y)
{
	int ans = 0;
	while (topf[x] != topf[y])
		{
			if (dep[x] < dep[y])swap(x, y);
			ans ^= ask(idx[topf[x]], idx[x], 1);
			x = fa[topf[x]];
		}
	if (dep[x] > dep[y])swap(x, y);
	ans ^= ask(idx[x], idx[y], 1);
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
			cin >> n >> m;
			int x, y;
			for (int i = 1; i < n; ++i)
				{
					cin >> x >> y;
					add(x, y);
					add(y, x);
				}
			for (int i = 1; i <= n; ++i)
				{
					cin >> b[i];
					if (b[i] == 0)b[i] = M;
				}

			dfs1(1, 0);
			dfs2(1, 1);
			build(1, n, 1);
			int h;
			while (m--)
				{
					cin >> h >> x >> y;
					if (h == 0)
						{
							if (y == 0)y = M;
							update(idx[x], idx[x], 1, y);
						}
					else if (h == 1)
						{
							int ans = treeadd(x, y);
							if (ans == 0)
								{
									cout << -1 << endl;
									continue;
								}
							else if (ans == M)ans = 0;
							cout << ans << endl;
						}
				}
		}
	return 0;
}
