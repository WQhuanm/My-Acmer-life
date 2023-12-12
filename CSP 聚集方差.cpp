#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define endl             "\n"
const int N = 3e5 + 10;

int n, tot;
int a[N];
int sz[N], mx[N], son[N], id[N], num[N];
ll ans[N];
ll sum;
vector<int>edge[N];
multiset<int>s;

void pre_dfs(int u, int f)//预处理树儿子
{
	id[u] = ++tot, num[tot] = u;
	sz[u] = 1, mx[u] = son[u] = 0;
	for (int v : edge[u])if (v != f)
	{
		pre_dfs(v, u);
		sz[u] += sz[v];
		if (sz[v] > mx[u])mx[u] = sz[v], son[u] = v;
	}
}

ll b[10];

ll cal(ll x, ll y, ll z)
{
	if (abs(y) == inf)return 0;
	if (abs(x) == abs(z) && abs(x) == inf)return 0;
	if (abs(x) < inf && abs(z) < inf)return min((x - y) * (x - y), (y - z) * (y - z));
	else if (abs(z) < inf)return (y - z) * (y - z);
	else if (abs(x) < inf)return (x - y) * (x - y);
	return 0;
}

void add(ll c)
{
	auto p = s.upper_bound(c);
	p--, p--;
	for (int i = 1; i <= 5; ++i)
	{
		if (i != 3)b[i] = *p, p++;
		else b[i] = c;
	}
	sum += cal(b[1], b[2], b[3]) + cal(b[2], b[3], b[4]) + cal(b[3], b[4], b[5]) - cal(b[1], b[2], b[4]) - cal(b[2], b[4], b[5]);
	s.insert(c);
}

void init()
{
	s.insert(inf), s.insert(inf);
	s.insert(-inf), s.insert(-inf);
}

void dfs(int u, int f, bool fl)
{
	for (int v : edge[u])if (v != f && v != son[u])dfs(v, u, 0);//先处理好轻子树的答案
	if (son[u])dfs(son[u], u, 1);//递归到重子树处理，然后继承重子树信息
	for (int v : edge[u])if (v != f && v != son[u])//dfs序连续，暴力访问所有轻子树节点
	{
//                                （也可以dfs访问）
		for (int i = id[v]; i < id[v] + sz[v]; ++i)add(a[num[i]]);
	}
	add(a[u]);//最后添加u自己的信息
	ans[u] = sum;
	if (!fl)//如果是轻子树，需要清空其留下的信息
	{
		s.clear(), sum = 0;
		init();
	}
}


void mysolve()
{
	int x;
	cin >> n;
	for (int i = 2; i <= n; ++i)cin >> x, edge[x].push_back(i);
	for (int i = 1; i <= n; ++i)cin >> a[i];
	pre_dfs(1, 0);
	init();
	dfs(1, 0, 1);
	for (int i = 1; i <= n; ++i)cout << ans[i] << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	return 0;
}
