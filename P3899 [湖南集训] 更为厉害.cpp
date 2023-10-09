#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 3e5 + 10;

struct line_tree
{
	struct tree
	{
		int ls, rs;
		ll sum;
	} t[N * 39];
	int tot = 0;
	void init()
	{
		for (int i = 0; i <= tot; ++i)t[i].ls = t[i].rs = t[i].sum = 0;
		tot = 0;
	}

	void pushup(int p)
	{
		t[p].sum = t[t[p].ls].sum + t[t[p].rs].sum;
	}

	void update(int l, int r, int x, int w, int &p)
	{
		if (!p)p = ++tot;
		if (l == r)
			{
				t[p].sum += w;
				return;
			}
		int mid = l + ((r - l) >> 1);
		if (x <= mid)update(l, mid, x, w, t[p].ls);
		else update(mid + 1, r, x, w, t[p].rs);
		pushup(p);
	}

	void merge(int l, int r, int &p, int &p2)
	{
		if (!p || !p2)return p = p | p2, void();
		t[++tot] = t[p], p = tot;
		if (l == r)
			{
				t[p].sum += t[p2].sum;
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
		if (ql <= l && r <= qr)return t[p].sum;
		int mid = l + ((r - l) >> 1);
		ll ans = 0;
		if (ql <= mid)ans += ask(ql, qr, l, mid, t[p].ls);
		if (qr > mid)ans += ask(ql, qr, mid + 1, r, t[p].rs);
		return ans;
	}
} T;
int number[N];

int dep[N], sz[N];
vector<int>edge[N];
int n, q;

void dfs(int u, int f)
{
	sz[u] = 1, dep[u] = dep[f] + 1;
	for (auto v : edge[u])if (v != f)
			{
				dfs(v, u), sz[u] += sz[v];
				T.merge(1, n, number[u], number[v]);
			}
	T.update(1, n, dep[u], sz[u] - 1, number[u]);
}

void mysolve()
{
	cin >> n >> q;
	int x, y;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	dfs(1, 0);
	while (q--)
		{
			cin >> x >> y;
			ll ans = 1ll * min(dep[x] - 1, y) * (sz[x] - 1) + T.ask(dep[x] + 1, min(dep[x] + y, n), 1, n, number[x]);
			cout << ans << endl;
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	return 0;
}
