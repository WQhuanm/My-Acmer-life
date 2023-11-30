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
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

int sta[N], scc[N], dfn[N], low[N], sz[N];
bool insta[N], vis[N];
int  cnt, dfncnt, top;
int n, m;
int a[N], in[N];
ll sum[N], dp[N], len[N];
vector<int>edge[N], eg[N];

inline void init()
{
	for (int i = 0; i <= n; ++i)dfn[i] = 0, edge[i].clear();
	for (int i = 1; i <= cnt; ++i)eg[i].clear(), vis[i] = 0, in[i] = 0;
	top = dfncnt = cnt = 0;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++dfncnt;
	insta[u] = 1;
	sta[++top] = u;
	for (auto v : edge[u])
		{
			if (!dfn[v])//如果子代没有访问过，深入
				{
					tarjan(v);
					low[u] = min(low[u], low[v]);
				}
			else if (insta[v])low[u] = min(low[u], dfn[v]);//子代在里面说明成一个环
		}
	if (dfn[u] == low[u])
		{
			sz[++cnt] = 0, sum[cnt] = 0; //强连通分量增加
			while (1)
				{
					int v = sta[top--];
					insta[v] = 0;
					sum[cnt] += a[v];
					scc[v] = cnt;//记录每个点属于的连通分量
					++sz[cnt];
					if (u == v)break;
				}
		}
}

void dfs(int u)
{
	vis[u] = 1;
	len[u] = sz[u], dp[u] = sum[u];
	for (auto v : eg[u])
		{
			if (!vis[v])dfs(v);
			if (len[v] + sz[u] > len[u])len[u] = len[v] + sz[u], dp[u] = sum[u] + dp[v];
			else if (len[v] + sz[u] == len[u])dp[u] = min(dp[u], sum[u] + dp[v]);
		}
}

void mysolve()
{
	cin >> n >> m;
	init();
	for (int i = 1; i <= n; ++i)cin >> a[i];
	int x, y;
	while (m--)
		{
			cin >> x >> y;
			if (x != y)edge[y].push_back(x);
		}
	for (int i = 1; i <= n; ++i)if (!dfn[i])tarjan(i);//跑整个图的强连通，点为1~n
	for (int i = 1; i <= n; ++i)for (auto v : edge[i])if (scc[v] != scc[i])eg[scc[i]].push_back(scc[v]), in[scc[v]]++;
	int mxl = 0, mn = INF;
	for (int i = 1; i <= cnt; ++i)if (!in[i])
			{
				dfs(i);
				if (len[i] > mxl)mxl = len[i], mn = dp[i];
				else if (len[i] == mxl)mn = min(mn, dp[i]);
			}
	for (int i = 1; i <= cnt; ++i)if (!vis[i])
			{
				dfs(i);
				if (len[i] > mxl)mxl = len[i], mn = dp[i];
				else if (len[i] == mxl)mn = min(mn, dp[i]);
			}
	cout << mxl << " " << mn << endl;
}

signed main()
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
