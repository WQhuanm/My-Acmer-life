#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 1e5 + 10;

struct node
{
	int next, to;
} edge[N];

struct tree
{
	int l, r;
	int fl, sl, fr, sr, size;
	int lnum, rnum;
	int fmaxn, smaxn;

	void init()
	{
		fl = sl = fr = sr = size = fmaxn = smaxn = 0;
	}
	void reverse()
	{
		swap(lnum, rnum);
		swap(fmaxn, smaxn);
		swap(fl, sr), swap(sl, fr);
	}

} t[4 * N + 2];

int a[N], b[N], head[N << 1], tot[N], fa[N], son[N], dep[N], top[N], idx[N];
int num, cnt, n;

void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

void init()
{
	memset(head, 0, sizeof(head));
	memset(idx, 0, sizeof(idx));
	num = cnt = 0;
}

void dfs1(int u, int f)
{
	fa[u] = f;
	tot[u] = 1;
	dep[u] = dep[f] + 1;
	son[u] = 0;
	int maxn = -1;
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (v == f)continue;
			dfs1(v, u);
			tot[u] += tot[v];
			if (tot[v] > maxn)son[u] = v, maxn = tot[v];
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

tree unit(tree l, tree r)
{
	tree t;
	t.init();
	t.l = l.l, t.r = r.r;
	t.lnum = l.lnum, t.rnum = r.rnum, t.size = l.size + r.size;

	t.fl = l.fl;
	if (l.fl == l.size && l.rnum > r.lnum)t.fl += r.fl;
	t.sl = l.sl;
	if (l.sl == l.size && l.rnum < r.lnum)t.sl += r.sl;
	t.fr = r.fr;
	if (r.fr == r.size && l.rnum > r.lnum)t.fr += l.fr;
	t.sr = r.sr;
	if (r.sr == r.size && l.rnum < r.lnum)t.sr += l.sr;

	t.fmaxn = max({l.fmaxn, r.fmaxn, (l.rnum > r.lnum ? l.fr + r.fl : 0)});
	t.smaxn = max({l.smaxn, r.smaxn, (l.rnum < r.lnum ? l.sr + r.sl : 0)});

	return  t;
}

void change (int p)
{
	t[p] = unit(t[p << 1], t[p << 1 | 1]);
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	if (l == r)
		{
			t[p].fl = t[p].fr = t[p].sl  = t[p].sr = t[p].size = 1;
			t[p].lnum = t[p].rnum = a[l];
			t[p].fmaxn = t[p].smaxn = 1;
			return;
		}
	int mid = l + ((r - l) >> 1);
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
	change(p);
}

tree ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			return t[p];
		}
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (r <= mid)return ask(l, r, p << 1);
	if (l > mid)return ask(l, r, p << 1 | 1);

	tree t, tl, tr;
	t.init();
	tl = ask(l, r, p << 1), tr = ask(l, r, p << 1 | 1);
	return (t = unit(tl, tr));
}

tree treeunit(tree l, tree r)
{
	if (!l.size)return r;
	if (!r.size)return l;
	tree t;
	t.init();
	return (t = unit(l, r));
}

int treeask(int x, int y)
{
	tree l, r;
	l.init(), r.init();
	bool flag = 0;
	while (top[x] != top[y])
		{
			if (dep[top[x]] < dep[top[y]])swap(x, y), swap(l, r), flag ^= 1;
			tree tmp = ask(idx[top[x]], idx[x], 1);
			l = treeunit(tmp, l);
			x = fa[top[x]];
		}
	if (dep[x] > dep[y])swap(x, y), swap(l, r), flag ^= 1;
	tree tmp = ask(idx[x], idx[y], 1);
	r = unit(tmp, r);
	if (flag)swap(l, r);
	l.reverse();
	return treeunit(l, r).smaxn;
}
int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, x, q, y;
	cin >> t;
	for (int t1 = 1; t1 <= t; ++t1)
		{
			init();
			cin >> n;
			for (int i = 1; i <= n; ++i)cin >> b[i];
			for (int i = 2; i <= n; ++i)
				{
					cin >> x;
					add(x, i);
				}
			dfs1(1, 0);
			dfs2(1, 1);
			build(1, n, 1);
			cin >> q;
			cout << "Case #" << t1 << ":" << endl;
			while (q--)
				{
					cin >> x >> y;
					cout << treeask(x, y) << endl;
				}
			if (t1 < t)cout << endl;
		}
	return 0;
}
