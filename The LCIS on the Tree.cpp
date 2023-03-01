#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 1e5 + 10;

int a[N], b[N], top[N], tot[N], dep[N], head[N], son[N], fa[N], idx[N];
int num, cnt, n, m;

struct node
{
	int next, to;
} edge[N];

struct tree
{
	int l, r, lnum, rnum, size;
	int fl, fr, sl, sr;
	int fmaxn, smaxn;
	void init()
	{
		lnum = rnum = fl = fr = sl = sr = size = fmaxn = smaxn = 0;
	}
	void reverse()//用于把这个tree区间左右信息互换
	{
		swap(fl, sr), swap(sl, fr), swap(lnum, rnum);
		swap(fmaxn, smaxn);
	}
} t[4 * N];

void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
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
	tot[u] = 1, son[u] = idx[u] = 0;
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

tree unit(tree l, tree r)
{
	if (!l.size)return r;//如果左树没用节点（为空），那直接放回右部分即可
	if (!r.size)return l;//同理
	tree t;
	t.l = l.l, t.r = r.r;
	t.size = l.size + r.size;//sized等于左边加右边
	t.lnum = l.lnum, t.rnum = r.rnum;
	t.fl = l.fl;
	if (l.fl == l.size && l.rnum > r.lnum)t.fl += r.fl;
	t.sl = l.sl;
	if (l.sl == l.size && l.rnum < r.lnum)t.sl += r.sl;
	t.fr = r.fr;
	if (r.fr == r.size && l.rnum > r.lnum)t.fr += l.fr;
	t.sr = r.sr;
	if (r.sr == r.size && l.rnum < r.lnum)t.sr += l.sr;
	//以降序fmaxn为例，更新时要么去左边的fmaxn，要么右边的fmaxn，要么如果两边符合端点l.rnum > r.lnum，则可以多算中间一段
	t.fmaxn = max(l.fmaxn, max(r.fmaxn, (l.rnum > r.lnum ? l.fr + r.fl : 0)));
	t.smaxn = max(l.smaxn, max(r.smaxn, (l.rnum < r.lnum ? l.sr + r.sl : 0)));

	return t;
}

void change(int p)
{
	t[p] = unit(t[p << 1], t[p << 1 | 1]);
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	if (l == r)
		{
			t[p].lnum = t[p].rnum = a[l];
			t[p].size = t[p].fmaxn = t[p].smaxn = t[p].fl = t[p].sl = t[p].sr = t[p].fr = 1;
			return ;
		}
	int mid = l + ((r - l) >> 1);
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
	change(p);
}

tree ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p];
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	//如果l，r范围只在左右区间一边，直接返回那一边得到的tree即可
	if (r <= mid)return ask(l, r, p << 1);
	if (l > mid)return ask(l, r, p << 1 | 1);
	tree t, tl, tr;
	tl = ask(l, r, p << 1), tr = ask(l, r, p << 1 | 1);
	return (t = unit(tl, tr));
}

int treeask(int x, int y)
{
	bool flag = 0;
	tree l, r;
	//我们刚刚开始tree是空的，记得初始化，否则与别人连接出问题
	l.init();
	r.init();
	while (top[x] != top[y])
		{
			if (dep[top[x]] < dep[top[y]])swap(x, y), swap(l, r), flag ^= 1;//x,y每次翻转记录一下
			tree tmp = ask(idx[top[x]], idx[x], 1);
			l = unit(tmp, l);//越往上的段在左边
			x = fa[top[x]];
		}
	if (dep[x] > dep[y])swap(x, y), swap(l, r), flag ^= 1;
	tree tmp = ask(idx[x], idx[y], 1);//x深度小于y，则这一段跟y的链拼接
	r = unit(tmp, r);
	if (flag)swap(l, r);//如果翻转奇数次，那么我们最后得出结果是y->x，所以我们需要否则回来
	l.reverse();//最后是x的顶端拼接y的端点，显然需要将x左右翻转
	return unit(l, r).smaxn;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, x, y;
	cin >> t;
	for (int ti = 1; ti <= t; ++ti)
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
			cin >> m;
			cout << "Case #" << ti << ":" << endl;
			while (m--)
				{
					cin >> x >> y;
					cout << treeask(x, y) << endl;
				}
			if (ti < t)cout << endl;
		}

	return 0;
}
