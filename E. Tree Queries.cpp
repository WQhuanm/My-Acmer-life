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
const int N = 2e5 + 10;

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	int l, r;
	ll sum, add;
} t[N << 2];

inline void pushup(int p)
{
	t[p].sum = max(t[ls].sum, t[rs].sum);
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	t[p].sum = t[p].add = 0; //初始化
	if (l == r)
		{
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
}

inline void change(int p, ll w)
{
	t[p].sum = (t[p].sum + w );
	t[p].add = (t[p].add + w);
}

inline void lazy(int p)
{
	if (t[p].l == t[p].r)t[p].add = 0;
	if (t[p].add)
		{
			change(ls, t[p].add), change(rs, t[p].add);
			t[p].add = 0;
		}
}

void update(int l, int r, int p, ll w)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			change(p, w);
			return;
		}
	lazy(p);
	if (l <= mid)update(l, r, ls, w);
	if (r > mid)update(l, r, rs, w);
	pushup(p);
}

ll ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].sum;
	lazy(p);
	ll ans = 0;
	if (l <= mid)ans = max(ans, ask(l, r, ls));
	if (r > mid)ans = max(ans, ask(l, r, rs));
	return ans;
}
int n, q, tot;
int in[N], out[N], nx[N];
vector<int>eg[N], kind[N], edge[N];
int ans[N];

void pre_dfs(int u, int f)
{
	in[u] = ++tot;
	for (auto v : edge[u])if (v != f)pre_dfs(v, u);
	out[u] = tot;
}

void dfs(int u, int f)
{
	for (auto id : eg[u])
		{
			vector<pii>now;
			for (auto v : kind[id])
				{
					if (in[v] <= in[u] && out[u] <= out[v])now.push_back({1, in[nx[v]] - 1}), now.push_back({out[nx[v]] + 1, n});
					else now.push_back({in[v], out[v]});
				}
			sort(now.begin(), now.end());
			int p = 1;
			for (auto [l, r] : now)
				{
					if (l > p)ans[id] = max(ans[id], ask(p, l - 1, 1));
					p = max(p, r + 1);
				}
			if (p <= n)ans[id] = max(ans[id], ask(p, n, 1));
		}
	update(1, n, 1, 1);
	for (auto v : edge[u])if (v != f)
			{
				nx[u] = v;
				update(in[v], out[v], 1, -2);
				dfs(v, u);
				update(in[v], out[v], 1, 2);
			}
	update(1, n, 1, -1);
}

void mysolve()
{
	cin >> n >> q;
	int x, y, k;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	pre_dfs(1, 0);
	for (int i = 1; i <= q; ++i)
		{
			cin >> x >> k;
			eg[x].push_back(i);
			for (int j = 1; j <= k; ++j)cin >> y, kind[i].push_back(y);
		}
	build(1, n, 1);
	for (int i = 1; i <= n; ++i)update(in[i], out[i], 1, 1);
	dfs(1, 0);
	for (int i = 1; i <= q; ++i)cout << ans[i]-1 << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
