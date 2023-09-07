#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
const int N = 3e5 + 10;

//const int MAXN = 1e6;
int  n, tt, now = 0, cnt; //插入直线数量
int vis[N];
int number[5],  scc[N], fa[N]; //每个线段树区间对应的根
pii q[N];
struct node
{
	int v, id;
};
vector<node>edge[N];

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
	int tot = 0;//tot为开点数
	struct tree
	{
		int  ls, rs, id;
	} t[N << 5]; //空间nlogn,N为直线数

	void update(int l, int r, int &p, int id)//求min
	{
		if (!p)return t[p = ++tot].id = id, void();//动态开点，这个区间是新的，覆盖完就走

		int mid = l + ((r - l) >> 1);
		if (cal(id, mid) - cal(t[p].id, mid) > eps)swap(id, t[p].id); //保证t[p].id对应的是该位置的最优线段，只有严格小）才更新
		if (l == r)return;
		//操作后 x为次优，在他能够比t[p].id优越的子区间更新
		if (cal(id, l) - cal(t[p].id, l) > eps)update(l, mid, t[p].ls, id); //两个区间只会进入一个，严格小才更新（避免直线是重合还多更新）
		if (cal(id, r) - cal(t[p].id, r) > eps)update(mid + 1, r, t[p].rs, id);
	}

	ll ask(int l, int r, int p, int x) //x为坐标
	{
		if (!p)return -INF;//没开过点，这个区间不存在新直线了，返回极值
		if (l == r)return cal(t[p].id, x);

		//李超没有下传标记，所有覆盖x的区间的最值才是最优
		int mid = l + ((r - l) >> 1);
		ll ans = cal(t[p].id, x);
		if (x <= mid)ans = max(ans, ask(l, mid, t[p].ls, x));
		else ans = max(ans, ask(mid + 1, r, t[p].rs, x));
		return ans;
	}
} T;

void dfs(int u, int f)
{
	vis[u] = 1;
	bool fl = 1;
	for (auto [v, id] : edge[u])
		{
			if (v == f && fl)//重边
				{
					fl = 0;
					continue;
				}
			if (!vis[v])
				{
					q[++cnt] = {u, id} ;
					dfs(v, u);
					cnt--;
				}
			else if (fa[v] != u)
				{
					fa[u] = v;
					now++;
					scc[id] ^= now;
					int x = cnt;
					while (1)
						{
							scc[q[x].second] ^= now;
							if (q[x].first == v)break;
							x--;
						}
				}
		}
}

void mysolve()
{
	cin >> n >> tt;
	int x, y;
	ll sum = 0, add = 0;
	for (int i = 1; i <= n + 1; ++i)
		{
			cin >> x >> y >> a[i].k >> a[i].b;
			edge[x].push_back({y, i}), edge[y].push_back({x, i});
			sum += a[i].b, add += a[i].k;
		}

	dfs(1, 0);
	for (int i = 1; i <= n + 1; ++i)if (scc[i])
			{
				T.update(0, tt, number[scc[i]], i);
			}
	for (int i = 0; i <= tt; ++i)
		{
			ll ans = sum + i * add;
			ll tmp = max({T.ask(0, tt, number[1], i) + T.ask(0, tt, number[2], i),
			              T.ask(0, tt, number[1], i) + T.ask(0, tt, number[3], i),
			              T.ask(0, tt, number[2], i) + T.ask(0, tt, number[3], i)});
			ans -= tmp;
			cout << ans << endl;
		}
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
