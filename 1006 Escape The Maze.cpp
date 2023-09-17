#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 1e5 + 10;

int MAXN = 1e5;
int  n, L, cnt; //插入直线数量
int idx[N], sz[N], mx[N], son[N], num[N], rt[N]; //每个线段树区间对应的根
ll dis[N], b[N], dp[N];
vector<pii>edge[N];

struct line
{
	ll k, b;
} a[N];//记录填入直线

inline ll cal(int id, int x)//x为坐标
{
	return a[id].k * b[x] + a[id].b;//如果是实数，需要改为double
}

struct LC_tree//这里要求是加入直线，而不是线段(需要开辟空间直到线段包含当前区间），才能保证nlogn空间复杂度（否则是nlogn^2）
{
	int tot = 0; //tot为开点数
	struct tree
	{
		int  ls, rs, id;
	} t[N << 5]; //空间nlogn,N为直线数

	void clear()
	{
		for (int i = 0; i <= tot; ++i)t[i].ls = t[i].rs = t[i].id = 0;
		tot =  0;
	}

	void update(int l, int r, int &p, int id)//求min
	{
		if (!p)return t[p = ++tot].id = id, void();//动态开点，这个区间是新的，覆盖完就走
		int mid = l + ((r - l) >> 1);
		if (cal(id, mid) - cal(t[p].id, mid) < 0)swap(id, t[p].id); //保证t[p].id对应的是该位置的最优线段，只有严格小）才更新
		if (l == r)return;

		//操作后 x为次优，在他能够比t[p].id优越的子区间更新
		if (cal(id, l) - cal(t[p].id, l) < 0)update(l, mid, t[p].ls, id); //两个区间只会进入一个，严格小才更新（避免直线是重合还多更新）
		if (cal(id, r) - cal(t[p].id, r) < 0)update(mid + 1, r, t[p].rs, id);
	}

	ll ask(int l, int r, int p, int x) //x为坐标
	{
		if (!p)return INF;//没开过点，这个区间不存在新直线了，返回极值
		if (l == r)return cal(t[p].id, x);
		//李超没有下传标记，所有覆盖x的区间的最值才是最优
		int mid = l + ((r - l) >> 1);
		ll ans = cal(t[p].id, x);
		if (x <= mid)ans = min(ans, ask(l, mid, t[p].ls, x));
		else ans = min(ans, ask(mid + 1, r, t[p].rs, x));
		return ans;
	}
} T;

void pre_dfs(int u, int f)
{
	idx[u] = ++cnt, num[cnt] = u;
	sz[u] = 1, son[u] = mx[u] = 0, b[u] = dis[u] + L;
	for (auto [v, w] : edge[u])if (v != f)
			{
				dis[v] = dis[u] + w;
				pre_dfs(v, u);
				sz[u] += sz[v];
				if (sz[v] > mx[u])mx[u] = sz[v], son[u] = v;
			}
}

void dfs(int u, int f, bool fl)
{
	for (auto [v, w] : edge[u])if (v != f && v != son[u])
			dfs(v, u, 0);
	if (son[u])
		{
			dfs(son[u], u, 1);
			rt[u] = rt[son[u]];
			int x = lower_bound(b + 1, b + 1 + MAXN, dis[u] + L) - b;
			dp[u] = (dis[u] + L) * (dis[u] + L) + T.ask(1, MAXN, rt[u], x);
		}
	else dp[u] = 0;
	for (auto [v, w] : edge[u])if (v != f && v != son[u])
			for (int i = idx[v]; i < idx[v] + sz[v]; ++i)
				{
					int now = num[i];
					dp[u] = min(dp[u], dp[now] + (dis[now] - dis[u] - L) * (dis[now] - dis[u] - L));
					if (fl)T.update(1, MAXN, rt[u], now);
				}
	a[u] = {-2 * dis[u], dp[u] + dis[u]*dis[u]};
	T.update(1, MAXN, rt[u], u);
}

void mysolve()
{
	cin >> n >> L;
	for (int i = 1; i <= n; ++i)edge[i].clear();
	int x, y, w;
	for (int i = 1; i < n; ++i)
		{
			cin >> x >> y >> w;
			edge[x].push_back({y, w});
			edge[y].push_back({x, w});
		}
	int q;
	cin >> q;
	while (q--)
		{
			cin >> x;
			cnt = 0, T.clear();
			for (int i = 1; i <= n; ++i)rt[i] = 0;
			dis[x] = 0;
			pre_dfs(x, 0);
			sort(b + 1, b + 1 + n);
			MAXN = unique(b + 1, b + 1 + n) - b - 1;
			dfs(x, 0, 1);
			cout << dp[x] << endl;
		}
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
