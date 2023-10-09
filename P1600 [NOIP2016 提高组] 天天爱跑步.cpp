#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
#define endl             "\n"
const int N = 3e5 + 10;

struct line_tree
{
	struct tree
	{
		int ls, rs;
		ll sum_st, sum_ed;
	} t[N * 40];
	int tot = 0;

	void pushup(int p)
	{
		t[p].sum_st = t[t[p].ls].sum_st + t[t[p].rs].sum_st;
		t[p].sum_ed = t[t[p].ls].sum_ed + t[t[p].rs].sum_ed;
	}

	void update(int l, int r, int x, int w1, int w2, int &p)
	{
		if (!p)p = ++tot;
		if (l == r)
			{
				t[p].sum_st += w1, t[p].sum_ed += w2;
				return;
			}
		int mid = l + ((r - l) >> 1);
		if (x <= mid)update(l, mid, x, w1, w2, t[p].ls);
		else update(mid + 1, r, x, w1, w2, t[p].rs);
		pushup(p);
	}

	void merge(int l, int r, int &p, int &p2)
	{
		if (!p || !p2)return p = p | p2, void();
		t[++tot] = t[p], p = tot;//如果每个结点的信息都要保留，不能因为被合并而修改，需要新开结点继承（空间大概需要开2*nlogn)。否则该句可以不写(空间开nlogn)
		if (l == r)
			{
				t[p].sum_st += t[p2].sum_st;
				t[p].sum_ed += t[p2].sum_ed;
				return;
			}
		int mid = l + ((r - l) >> 1);
		merge(l, mid, t[p].ls, t[p2].ls);
		merge(mid + 1, r, t[p].rs, t[p2].rs);
		pushup(p);
	}

	ll ask(int ql, int qr, int l, int r, int p)
	{
		if (!p)return 0;
		if (ql <= l && r <= qr)return t[p].sum_st ;
		int mid = l + ((r - l) >> 1);
		ll ans = 0;
		if (ql <= mid)ans += ask(ql, qr, l, mid, t[p].ls);
		if (qr > mid)ans += ask(ql, qr, mid + 1, r, t[p].rs);
		return ans;
	}

	ll ask2(int ql, int qr, int l, int r, int p)
	{
		if (!p)return 0;
		if (ql <= l && r <= qr)return  t[p].sum_ed;
		int mid = l + ((r - l) >> 1);
		ll ans = 0;
		if (ql <= mid)ans += ask2(ql, qr, l, mid, t[p].ls);
		if (qr > mid)ans += ask2(ql, qr, mid + 1, r, t[p].rs);
		return ans;
	}
} T;

const int lg = 19;
int number[N];
vector<int>edge[N];
int n, m;
int a[N], pre[N][30], dep[N], ans[N];

void pre_dfs(int u, int f)
{
	dep[u] = dep[f] + 1, pre[u][0] = f;
	for (int i = 1; i <= lg; ++i)pre[u][i] = pre[pre[u][i - 1]][i - 1];
	for (auto v : edge[u])if (v != f)
			pre_dfs(v, u);
}

int LCA(int u, int v)
{
	if (dep[u] != dep[v])
		{
			if (dep[u] < dep[v])swap(u, v);
			for (int i = lg; ~i; --i)if (dep[pre[u][i]] >= dep[v])u = pre[u][i];
		}
	if (u == v)return u;
	for (int i = lg; ~i; --i)if (pre[u][i] != pre[v][i])u = pre[u][i], v = pre[v][i];
	return pre[u][0];
}

void dfs(int u, int f)
{
	for (auto v : edge[u])if (v != f)
			{
				dfs(v, u);
				T.merge(-n, n, number[u], number[v]);
			}
	ans[u] = T.ask2(a[u] - dep[u], a[u] - dep[u], -n, n, number[u]);
	if (a[u] + dep[u] <= n)ans[u] += T.ask(dep[u] + a[u], dep[u] + a[u], -n, n, number[u]);
}

void mysolve()
{
	cin >> n >> m;
	int x, y;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	for (int i = 1; i <= n; ++i)cin >> a[i];
	pre_dfs(1, 0);
	while (m--)
		{
			cin >> x >> y;
			int lca = LCA(x, y);
			int len = dep[x] + dep[y] - 2 * dep[lca];
			T.update(-n, n, dep[x], 1, 0, number[x]), T.update(-n, n, len - dep[y], 0, 1, number[y]), T.update(-n, n, dep[x], -1, 0, number[lca]);
			if (pre[lca][0])T.update(-n, n, len - dep[y], 0, -1, number[pre[lca][0]]);
		}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i)cout << ans[i] << " \n"[i == n];
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
