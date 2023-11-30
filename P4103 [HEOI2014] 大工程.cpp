#include <bits/stdc++.h>
using namespace std;
//#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define inf 0x3f3f3f3f
const int N = 1e6 + 10;

const int lg = 19; //5e5
int n, m, k, tot, top;
int dep[N], pre[N][30], id[N];
int a[N], stk[N];
ll mn[N], mx[N], cnt[N], mndep[N], mxdep[N];
ll dep_sum[N];
bool vis[N];
vector<int>edge[N], eg[N];

bool cmp(int &a, int &b)
{
	return id[a] < id[b];
}

void pre_dfs(int u, int f)
{
	dep[u] = dep[f] + 1, pre[u][0] = f;
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

ll dfs(int u)
{
	mn[u] = mndep[u] = inf, mx[u] = mxdep[u] = cnt[u] = 0;
	if (vis[u])cnt[u]++, dep_sum[u] = mndep[u] = mxdep[u] = dep[u];
	else dep_sum[u] = 0;
	ll sum = 0;
	for (auto v : eg[u])
		{
			sum += dfs(v);
			if (cnt[v])
				{
					sum += (ll)cnt[u] * (dep_sum[v] - dep[u] * cnt[v]) + (ll)cnt[v] * (dep_sum[u] - dep[u] * cnt[u]);
					dep_sum[u] += dep_sum[v];
					mn[u] = min(mn[u], mn[v]), mx[u] = max(mx[u], mx[v]);
					if (cnt[u])
						{
							mn[u] = min(mn[u], mndep[u] + mndep[v] - 2 * dep[u]);
							mx[u] = max(mx[u], mxdep[u] + mxdep[v] - 2 * dep[u]);
						}
					mxdep[u] = max(mxdep[u], mxdep[v]), mndep[u] = min(mndep[v], mndep[u]);
					cnt[u] += cnt[v];
				}
		}
	vis[u] = 0;
	eg[u].clear();
	return sum;
}

void mysolve()
{
	cin >> n;
	int x, y;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	pre_dfs(1, 0);
	cin >> m;
	while (m--)
		{
			cin >> k;
			for (int i = 1; i <= k; ++i)cin >> a[i], vis[a[i]] = 1;
			sort(a + 1, a + 1 + k, cmp);
			stk[top = 1] = 1;
			for (int i = 1; i <= k; ++i)
				{
					int lca = LCA(stk[top], a[i]);
					while (dep[lca] <= dep[stk[top - 1]])//使得lca是top-1的子代
						{
							eg[stk[top - 1]].push_back(stk[top]), top--;
						}
					if (lca != stk[top])//此时要么lca=top,要么lca介于top与top-1之间
						{
							eg[lca].push_back(stk[top--]);
							stk[++top] = lca;
						}
					if (a[i] != stk[top])stk[++top] = a[i];//防止重复
				}
			while (top > 1)	eg[stk[top - 1]].push_back(stk[top]), top--;
			cout << dfs(1) << " " << mn[1] << " " << mx[1] << endl;
		}
}

signed main()
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
