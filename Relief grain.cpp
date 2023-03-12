#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 1e5 + 10;

int head[N], tot[N], fa[N], top[N], son[N], idx[N], dep[N], back[N], ans[N];
int num, cnt, n, m;
vector<int>v[N];
struct tree
{
	int l, r;
	int num, cnt;
} t[N << 2];

struct node
{
	int next, to;
} edge[N << 1];

void init()
{
	memset(head, 0, sizeof(head));
	for (int i = 1; i <= n + 1; ++i)v[i].clear(); ///////////////区间push有加一的原因，更新n+1个点
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
	fa[u] = f;
	dep[u] = dep[f] + 1;
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
	back[cnt] = u;
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
	if (l > r)return;//传入的r不一定大于l
	t[p].l = l, t[p].r = r;
	t[p].num = t[p].cnt = 0;
	if (l == r)
		{
			t[p].num = l;
			return;
		}
	int mid = l + ((r - l) >> 1);
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
}

void update(int p, int w, int val)
{
	if (w == t[p].l && w == t[p].r)
		{
			t[p].cnt += val;
			return;
		}
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (w <= mid)update(p << 1, w, val);
	else update(p << 1 | 1, w, val);
	if (t[p << 1].cnt >= t[p << 1 | 1].cnt)
		{
			t[p].cnt = t[p << 1].cnt;
			t[p].num = t[p << 1].num;
		}
	else
		{
			t[p].cnt = t[p << 1 | 1].cnt;
			t[p].num = t[p << 1 | 1].num;
		}
}

void treeupdate(int x, int y, int w)
{
	while (top[x] != top[y])
		{
			if (dep[top[x]] < dep[top[y]])swap(x, y);
			v[idx[top[x]]].push_back(w), v[idx[x] + 1].push_back(-w);
			x = fa[top[x]];
		}
	if (dep[x] > dep[y])swap(x, y);
	v[idx[x]].push_back(w), v[idx[y] + 1].push_back(-w);
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int  x, y, w;
	while (cin >> n >> m && (n || m))
		{
			init();
			for (int i = 1; i < n; ++i)cin >> x >> y, add(x, y), add(y, x);
			dfs1(1, 0);
			dfs2(1, 1);
			int maxn = 0;
			while (m--)
				{
					cin >> x >> y >> w;
					treeupdate(x, y, w);
					maxn = max(maxn, w);
				}
			t[1].cnt = 0;//防止传入r大于l导致没有清空上一次的值
			build(1, maxn, 1);
			for (int i = 1; i <= n; ++i)
				{
					for (int j = 0; j < (int)v[i].size(); ++j)
						{
							if (v[i][j] > 0)update(1, v[i][j], 1);
							else update(1, -v[i][j], -1);
						}
					if (t[1].cnt > 0)ans[back[i]] = t[1].num;
					else ans[back[i]] = 0;
				}
			for (int i = 1; i <= n; ++i)cout << ans[i] << endl;
		}

	return 0;
}
