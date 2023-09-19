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
const int mod = 998244353;
const int N = 3e6 + 10;

int dis[N];
vector<int>edge[N];
int n, tot, now;
int a[N];
int sz[N], mx[N], col[N], son[N], id[N], num[N], ans[N], vis[N];

void pre_dfs(int u, int f)//预处理树儿子
{
	id[u] = ++tot, num[tot] = u;
	sz[u] = 1, mx[u] = son[u] = 0;
	for (int v : edge[u])if (v != f)
			{
				dis[v] = dis[u] + 1;
				pre_dfs(v, u);
				sz[u] += sz[v];
				if (sz[v] > mx[u])mx[u] = sz[v], son[u] = v;
			}
}

void add(int u)
{
	vis[dis[u]]++;
	if (vis[dis[u]] > vis[now])now = dis[u];
	else if (vis[dis[u]] == vis[now] && dis[u] < now)now = dis[u];
}

void del(int u)
{
	vis[dis[u]]--;
}

void dfs(int u, int f, bool fl)
{
	for (int v : edge[u])if (v != f && v != son[u])dfs(v, u, 0);//先处理好轻子树的答案
	if (son[u])dfs(son[u], u, 1);//递归到重子树处理，然后继承重子树信息
	for (int v : edge[u])if (v != f && v != son[u])//dfs序连续，暴力访问所有轻子树节点
			{
				//                                （也可以dfs访问）
				for (int i = id[v]; i < id[v] + sz[v]; ++i)add(num[i]);
			}
	add(u);//最后添加u自己的信息
	ans[u] = now - dis[u];
	if (!fl)//如果是轻子树，需要清空其留下的信息
		{
			for (int i = id[u]; i < id[u] + sz[u]; ++i)del(num[i]);
			now = 0;
		}
}

void mysolve()
{
	cin >> n;
	int x, y;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	pre_dfs(1, 0);
	dfs(1, 0, 1);
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
