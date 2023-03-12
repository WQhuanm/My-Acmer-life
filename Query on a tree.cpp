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

struct tree
{
	int l, r;
	int max;
} t[4 * N];

struct node
{
	int next, to, w;
} edge[N << 1];

struct nod1
{
	int x, y, z, id, ans;
	bool operator<(const nod1&k)const
	{
		return z < k.z;
	}
} t1[N], t2[N], t3[N];

int head[N], dep[N], tot[N], son[N], fa[N], idx[N], top[N];
int a[N], b[N];
int num, cnt;

void add(int u, int v, int w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;
}

void init()
{
	memset(head, 0, sizeof(head));
	num = cnt = 0;
}

void dfs1(int u, int f)
{
	fa[u] = f;
	dep[u] = dep[f] + 1;
	idx[u] = son[u] = 0;
	tot[u] = 1;
	int maxn = -1;
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (v == f)continue;
			dfs1(v, u);
			tot[u] += tot[v];
			b[v] = edge[i].w;
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
	t[p].l = l, t[p].r = r;
	if (l == r)
		{
			t[p].max = -1;
			return;
		}
	int mid = l + ((r - l) >> 1);
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
	t[p].max = max(t[p << 1].max, t[p << 1 | 1].max);
}

void update(int l, int r, int p, int z)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			t[p].max = z;
			return;
		}
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (l <= mid)update(l, r, p << 1, z);
	if (r > mid)update(l, r, p << 1 | 1, z);
	t[p].max = max(t[p << 1].max, t[p << 1 | 1].max);
}

int ask(int l, int r, int p, int z)
{
	if (l <= t[p].l && t[p].r <= r)if (t[p].max <= z)return t[p].max;
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	int ans = -1;
	if (l <= mid)ans = max(ans, ask(l, r, p << 1, z));
	if (r > mid)ans = max(ans, ask(l, r, p << 1 | 1, z));
	return ans;
}

ll treeask(int x, int z)
{
	int ans = -1;
	while (top[x] != 1)
		{
			ans = max(ans, ask(idx[top[x]], idx[x], 1, z));
			x = fa[top[x]];
		}
	ans = max(ans, ask(idx[top[x]], idx[x], 1, z));
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, n, x, y, w, q;
	cin >> t;
	while (t--)
		{
			init();
			cin >> n;
			for (int i = 1; i < n; ++i)
				{
					cin >> x >> y >> w;
					t1[i].x = x, t1[i].y = y, t1[i].z = w;
					add(x, y, w);
					add(y, x, w);
				}
			dfs1(1, 0);
			b[1] = -1;
			dfs2(1, 1);
			build(1, n, 1);
			cin >> q;
			for (int i = 1; i <= q; ++i)
				{
					cin >> x >> y;
					t2[i].x = x, t2[i].z = y, t2[i].id = i;
				}
			sort(t1 + 1, t1 + n);
			sort(t2 + 1, t2 + 1 + q);

			int cnt = 1;
			for (int i = 1; i <= q; ++i)
				{
					while (cnt < n && t1[cnt].z <= t2[i].z)
						{
							int u = t1[cnt].x, v = t1[cnt].y, w = t1[cnt].z;
							if (dep[u] < dep[v])swap(u, v);
							update(idx[u], idx[u], 1, w);
							cnt++;
						}
					int id = t2[i].id;
					t2[id].ans = treeask(t2[i].x, t2[i].z);
				}
			for (int i = 1; i <= q; ++i)cout << t2[i].ans << endl;

		}
	return 0;
}
