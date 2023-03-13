#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 1e5 + 10;

int head[N], tot[N], dep[N], idx[N], top[N], fa[N], son[N];
int num, cnt;
int ans[N];

struct tree
{
	int l, r;
	int max;
} t[N << 2];
struct node
{
	int next, to;
} edge[N << 1];
struct dot
{
	int x, y, w, id;
	bool operator<(const dot&k)const
	{
		return w < k.w;
	}
} v1[N], v2[N];

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
	idx[u] = son[u] = 0;
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
	t[p].l = l, t[p].r = r, t[p].max = -1;
	if (l == r)return;
	int mid = l + ((r - l) >> 1);
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
}

void update(int id, int p, int w)//更新线段树是id这个点
{
	if (t[p].l == id && t[p].r == id)
		{
			t[p].max = w;
			return;
		}
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (id <= mid)update(id, p << 1, w);
	if (id > mid)update(id, p << 1 | 1, w);
	t[p].max = max(t[p << 1].max, t[p << 1 | 1].max);
}

int ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].max;
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	int ans = -1;
	if (l <= mid)ans = max(ans, ask(l, r, p << 1));
	if (r > mid)ans = max(ans, ask(l, r, p << 1 | 1));
	return ans;
}
int treeask(int x, int y)
{
	int ans = -1;
	while (top[x] != top[y])
		{
			if (dep[top[x]] < dep[top[y]])swap(x, y);
			ans = max(ans, ask(idx[top[x]], idx[x], 1));
			x = fa[top[x]];
		}
	if (dep[x] > dep[y])swap(x, y);
	ans = max(ans, ask(idx[x], idx[y], 1));
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
			int n, q;
			cin >> n;
			for (int i = 1; i < n; ++i)
				{
					cin >> v1[i].x >> v1[i].y >> v1[i].w;
					add(v1[i].x, v1[i].y), add(v1[i].y, v1[i].x);
				}
			cin >> q;
			for (int i = 1; i <= q; ++i)	cin >> v2[i].x >> v2[i].w, v2[i].id = i;//因为排序打乱原理q的顺序，id记录其原始顺序
			dfs1(1, 0);
			dfs2(1, 1);
			build(1, n, 1);//建空树
			sort(v1 + 1, v1 + n);//按小到大排点值
			sort(v2 + 1, v2 + 1 + q);//排查询的y值
			int cnt1 = 1;//指针表示当前更新了前cnt1个点
			for (int i = 1; i <= q; ++i)
				{
					while (v1[cnt1].w <= v2[i].w && cnt1 < n)//每次查询y前更新小于y的点
						{
							int x = v1[cnt1].x, y = v1[cnt1].y, w = v1[cnt1].w;
							if (dep[x] < dep[y])swap(x, y);//点值给边两端深度较深的点
							update(idx[x], 1, w);
							cnt1++;
						}
					ans[v2[i].id] = treeask(1, v2[i].x);
				}
			for (int i = 1; i <= q; ++i)cout << ans[i] << endl;
		}

	return 0;
}
