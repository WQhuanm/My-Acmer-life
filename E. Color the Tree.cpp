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

const int lg = 19; //5e5
int n, m, tot, top;
int  id[N], pre[N][30], dep[N];
int a[N], stk[N];
bool vis[N];
vector<int>edge[N], eg[N], now[N];

bool cmp(int &a, int &b)
{
	return id[a] < id[b];
}

void pre_dfs(int u, int f)
{
	dep[u] = dep[f] + 1, pre[u][0] = f;
	now[dep[u]].push_back(u);
	id[u] = ++tot;
	for (int i = 1; i <= lg; ++i)
		{
			pre[u][i] = pre[pre[u][i - 1]][i - 1];
		}
	for (auto v : edge[u])if (v != f)
			{
				pre_dfs(v, u);
			}
}

inline int LCA(int u, int v)
{
	if (dep[v] != dep[u])//不相等时才求，否则出现log2(0)
		{
			if (dep[u] < dep[v])swap(u, v); //始终让u深度大
			for (int i = lg; ~i; --i)if (dep[pre[u][i]] >= dep[v])u = pre[u][i];
		}
	if (u == v)return u;
	for (int i = lg; ~i; --i)
		{
			if (pre[u][i] != pre[v][i])
				{
					u = pre[u][i];
					v = pre[v][i];
				}
		}
	return pre[v][0];//儿子的父亲才是LCA
}

int dp[N][30], lgg[N];

void st()
{
	for (int i = 1; i <= n; ++i)cin >> dp[i][0];
	for (int j = 1; j <= lgg[n]; ++j)for (int i = 1; i + (1 << j) - 1 <= n; ++i)dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]); //预处理st表
}

int stask(int l, int r)
{
	int k = lgg[r - l + 1];
	return min(dp[l][k], dp[r - (1 << k) + 1][k]); //区间查询
}

ll dfs(int u, int lay)
{
	ll sum = 0;
	for (auto v : eg[u])sum += dfs(v, lay);
	ll ans;
	if (vis[u])ans = stask(lay - dep[u] + 1, lay);
	else ans = min(stask(lay - dep[u] + 1, lay), sum);
	eg[u].clear(), vis[u] = 0;
	return ans;
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) edge[i].clear(), now[i].clear();
	st();
	int x, y;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	pre_dfs(1, 0);
	ll ans = 0;
	for (int i = 1; i <= n; ++i)if (!now[i].empty())
			{
				for (auto v : now[i])vis[v] = 1;
				sort(now[i].begin(), now[i].end(), cmp);
				stk[top = 1] = 1;
				for (auto v : now[i])
					{
						int lca = LCA(stk[top], v);
						while (dep[lca] <= dep[stk[top - 1]])//使得lca是top-1的子代
							{
								eg[stk[top - 1]].push_back(stk[top]), top--;
							}
						if (lca != stk[top])//此时要么lca=top,要么lca介于top与top-1之间
							{
								eg[lca].push_back(stk[top--]);
								stk[++top] = lca;
							}
						if (v != stk[top])stk[++top] = v; //防止重复
					}
				while (top > 1)	eg[stk[top - 1]].push_back(stk[top]), top--;
				ans += dfs(1, i);
			}
	cout << ans << endl;
}

signed main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;

	lgg[1] = 0;
	for (int i = 2; i <= N - 5; ++i)lgg[i] = lgg[i >> 1] + 1; //预处理lg
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
