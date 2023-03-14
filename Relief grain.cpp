#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 1e5 + 10;
int head[N], tot[N], dep[N], top[N], son[N], fa[N], back[N], idx[N], ans[N];
int num, cnt;
int n, m;
vector<int>v[N];
struct tree
{
	int l, r;
	int cnt, max;//cnt表示区间数量最多的数字的数量，max表示数量最多的数字
} t[N << 2];
struct node
{
	int next, to;
} edge[N << 1];

void init()
{
	memset(head, 0, sizeof(head));
	for (int i = 1; i <= n + 1; ++i)v[i].clear();//因为差分的原因（尾点+1），我们实际更新了n+1个点
	cnt = num = 0;
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
	if (l > r)return;
	t[p].l = l, t[p].r = r, t[p].cnt = 0;//初始化
	if (l == r)
		{
			t[p].max = l;
			return;
		}
	int mid = l + ((r - l) >> 1);
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
}

void update(int id, int p, int w)
{
	if (t[p].l == id && id == t[p].r)
		{
			t[p].cnt += w;
			return;
		}
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (mid >= id)update(id, p << 1, w);
	if (mid < id)update(id, p << 1 | 1, w);
	if (t[p << 1].cnt >= t[p << 1 | 1].cnt)t[p].cnt = t[p << 1].cnt, t[p].max = t[p << 1].max;
	else t[p].cnt = t[p << 1 | 1].cnt, t[p].max = t[p << 1 | 1].max;
}

void treeupdate(int x, int y, int w)
{
	while (top[x] != top[y])
		{
			if (dep[top[x]] < dep[top[y]])swap(x, y);
			v[idx[top[x]]].push_back(w);
			v[idx[x] + 1].push_back(-w);
			x = fa[top[x]];
		}
	if (dep[x] > dep[y])swap(x, y);
	v[idx[x]].push_back(w), v[idx[y] + 1].push_back(-w);//v数组存储每个点的差分信息
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> n >> m && (n || m))
		{
			init();
			int x, y, w, maxn = 0;
			for (int i = 1; i < n; ++i)cin >> x >> y, add(x, y), add(y, x);
			dfs1(1, 0);
			dfs2(1, 1);
			while (m--)
				{
					cin >> x >> y >> w;
					treeupdate(x, y, w);//存储树上差分
					maxn = max(maxn, w);
				}
			t[1].cnt = 0;
			build(1, maxn, 1);//建立空的权值线段树
			for (int i = 1; i <= n; ++i)//从1开始维护
				{
					for (int j = 0; j < (int)v[i].size(); ++j)
						{
							if (v[i][j] > 0)update(v[i][j], 1, 1);
							else update(-v[i][j], 1, -1);//权值为负，即是食物w分配区间的尽头，之后的点要减少了
						}
					ans[back[i]] = 0;
					if (t[1].cnt > 0)ans[back[i]] = t[1].max;//只有cnt大于0，才说明有食物
				}
			for (int i = 1; i <= n; ++i)cout << ans[i] << endl;
		}

	return 0;
}
