#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, ll> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
const int N = 2e5 + 10, M = 1e6 + 10;

int cnt, n; //插入直线数量
int number[N << 2]; //每个线段树区间对应的根

struct line
{
	ll k, b;
} a[N];//记录填入直线

ll cal(int id, int x)//x为坐标
{
	return a[id].k * x + a[id].b;//如果是实数，需要改为double
}

struct LC_tree//这里要求是加入直线，而不是线段(需要开辟空间直到线段包含当前区间），才能保证nlogn空间复杂度（否则是nlogn^2）
{
	int tot = 0;
	struct tree
	{
		int  ls, rs, id;
	} t[M << 5]; //空间nlogn,M为x定义域

	void clear()
	{
		for (int i = 1; i <= tot; ++i)t[i].ls = t[i].rs = t[i].id = 0;
		tot = 0;
	}

	void update(int l, int r, int &p, int id)//求min
	{
		if (!p)return t[p = ++tot].id = id, void();//动态开点，这个区间是新的，覆盖完就走

		int mid = l + ((r - l) >> 1);
		if (cal(id, mid) - cal(t[p].id, mid) < -eps)swap(id, t[p].id); //保证t[p].id对应的是该位置的最优线段，只有严格小）才更新
		if (l == r)return;

		//操作后 x为次优，在他能够比t[p].id优越的子区间更新
		if (cal(id, l) - cal(t[p].id, l) < - eps)update(l, mid, t[p].ls, id); //两个区间只会进入一个，严格小才更新（避免直线是重合还多更新）
		if (cal(id, r) - cal(t[p].id, r) < - eps)update(mid + 1, r, t[p].rs, id);
	}

	ll ask(int l, int r, int p, int x) //x为坐标
	{
		if (!p)return INF;
		if (l == r)return cal(t[p].id, x);

		//李超没有下传标记，所有覆盖x的区间的最值才是最优
		int mid = l + ((r - l) >> 1);
		ll ans = cal(t[p].id, x);
		if (x <= mid)ans = min(ans, ask(l, mid, t[p].ls, x));
		else ans = min(ans, ask(mid + 1, r, t[p].rs, x));
		return ans;
	}
} T;

void init()
{
	cnt = 0, T.clear();
	for (int i = 1; i <= n << 2; ++i)number[i] = 0;
}

#define ls (p<<1)
#define rs (p<<1|1)

void update(int l, int r, int p, int x, int id)
{
	T.update(0, 1e6, number[p], id);
	if (l == r)return;
	int mid = l + ((r - l) >> 1);
	if (x <= mid)update(l, mid, ls, x, id);
	else update(mid + 1, r, rs, x, id);
}

ll ask(int l, int r, int p, int L, int R, int x)//[L,R]为可以询问的线段树区间，x为李超树坐标x
{
	if (L <= l && r <= R)return T.ask(0,1e6, number[p], x);//////////////////
	ll ans = INF;
	int mid = l + ((r - l) >> 1);
	if (L <= mid)ans = min(ans, ask(l, mid, ls, L, R, x));
	if (R > mid)ans = min(ans, ask(mid + 1, r, rs, L, R, x));
	return ans;
}

int type, top, idx;
int id[N], fa[N], stk[N];
ll dis[N], p[N], q[N], lim[N], dp[N], que[N];
vector<pii>edge[N];

void pre_dfs(int u)
{
	for (auto [v, w] : edge[u])dis[v] = dis[u] + w, pre_dfs(v);
	id[u] = ++idx;
}

void dfs(int u)
{
	a[++cnt] = {-dis[u], dp[u]}, update(1, n, 1, id[u], cnt);
	stk[++top] = u, que[top] = dis[u];
	for (auto [v, w] : edge[u])
		{
			int l = id[v], r = id[stk[lower_bound(que + 1, que + 1 + top, dis[v] - lim[v]) - que]];
			dp[v] = q[v] + dis[v] * p[v] + ask(1, n, 1, l, r, p[v]);
			dfs(v);
		}
	top--;
}
void mysolve()
{
	cin >> n >> type;
	init();
	ll w;
	for (int i = 2; i <= n; ++i)cin >> fa[i] >> w >> p[i] >> q[i] >> lim[i], edge[fa[i]].push_back({i, w});
	pre_dfs(1);
	dfs(1);
	for (int i = 2; i <= n; ++i)cout << dp[i] << endl;
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
//	system("pause");
	return 0;
}
