#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

const int lg = 19;
const int M = 1e5;
int n;
int number[N];
int ans[N], dep[N], pre[N][30];
vector<int>edge[N];

struct node
{
	int val, cnt;
	node operator+(const node&k)const
	{
		return {k.val, cnt + k.cnt};
	}
	bool operator<(const node&k)const
	{
		return cnt == k.cnt ? val > k.val : cnt < k.cnt;
	}
} ;
vector<node>c[N];

struct line_tree
{
	struct tree
	{
		int ls, rs;
		node w;
	} t[M * 20];
	int tot = 0;
	void init()
	{
		for (int i = tot; ~i; --i)t[i].ls = t[i].rs = 0, t[i].w = {0, 0};
		tot = 0;
	}
	int val, cnt;

	inline void pushup(int p)
	{
		t[p].w = max(t[t[p].ls].w, t[t[p].rs].w);
	}

	void update(int l, int r, node w, int &p)
	{
		if (!p)p = ++tot;
		if (l == r)return t[p].w = t[p].w + w, void();
		int mid = l + ((r - l) >> 1);
		if (w.val <= mid)update(l, mid, w, t[p].ls);
		else update(mid + 1, r, w, t[p].rs);
		pushup(p);
	}

	void merge(int l, int r, int&p, int p2)
	{
		if (!p || !p2)return p = p | p2, void();
		if (l == r)return t[p].w = t[p].w + t[p2].w, void();
		int mid = l + ((r - l) >> 1);
		merge(l, mid, t[p].ls, t[p2].ls), merge(mid + 1, r, t[p].rs, t[p2].rs);
		pushup(p);
	}
} lt;

void pre_dfs(int u, int f)
{
	pre[u][0] = f, dep[u] = dep[f] + 1;
	for (int i = 1; i <= lg; ++i)pre[u][i] = pre[pre[u][i - 1]][i - 1];
	for (auto v : edge[u])if (v != f)pre_dfs(v, u);
}

inline int LCA(int u, int v)
{
	if (dep[u] != dep[v])
		{
			if (dep[u] < dep[v])swap(u, v);
			for (int i = lg; ~i; --i)if (dep[pre[u][i]] >= dep[v])u = pre[u][i];
		}
	if (u == v)return u;
	for (int i = lg; ~i; --i)if (pre[u][i] != pre[v][i])
			{
				u = pre[u][i], v = pre[v][i];
			}
	return pre[u][0];
}

void dfs(int u, int f)
{
	for (int v : edge[u])if (v != f)
			{
				dfs(v, u);
				lt.merge(0, M, number[u], number[v]);
			}
	for (auto w : c[u])
		lt.update(0, M, w, number[u]);
	ans[u] = lt.t[number[u]].w.val;
}

int m;

void mysolve()
{
	cin >> n >> m;
	lt.init();
	int x, y, w;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	pre_dfs(1, 0);
	while (m--)
		{
			cin >> x >> y >> w;
			int lca = LCA(x, y);
			c[x].push_back({w, 1}), c[y].push_back({w, 1});
			c[lca].push_back({w, -1}), c[pre[lca][0]].push_back({w, -1});
		}

	dfs(1, 0);
	for (int i = 1; i <= n; ++i)cout << ans[i] << endl;
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
