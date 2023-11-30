#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
const int N = 3e5 + 10;

const int lg = 19; //5e5
int n, m, k, tot, top;
int  id[N], pre[N][30], dep[N], sz[N];
int  stk[N];
pii a[N];
int dp[N], ans[N], mn[N];
bool vis[N];
vector<int>edge[N], eg[N];

bool cmp(pii &a, pii &b)
{
	return id[a.first] < id[b.first];
}

bool cmp2(int &a, int &b)
{
	if (dep[mn[a]] != dep[mn[b]])
		return dep[mn[a]] < dep[mn[b]];
	else return mn[a] < mn[b];
}

void pre_dfs(int u, int f)
{
	dep[u] = dep[f] + 1, pre[u][0] = f;
	id[u] = ++tot, sz[u] = 1;
	for (int i = 1; i <= lg; ++i)
		{
			pre[u][i] = pre[pre[u][i - 1]][i - 1];
		}
	for (auto v : edge[u])if (v != f)
			{
				pre_dfs(v, u);
				sz[u] += sz[v];
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

int dis(int u, int v)
{
	return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
}

void dfs(int u, int last)
{
	sort(eg[u].begin(), eg[u].end(), cmp2);
	if (vis[u])
		{
			dp[u]++;
			int sum = sz[u] - 1;
			for (auto v : eg[u])
				{
					dfs(v, u);
					int now = v;
					for (int k = lg; ~k; --k)if (dep[pre[now][k]] > dep[u])now = pre[now][k];
					int mid = v;
					if (mn[v] < u)
						{
							for (int k = lg; ~k; --k)if (dep[mn[v]] + dep[u] <= 2 * dep[pre[mid][k]])mid = pre[mid][k];
						}
					else for (int k = lg; ~k; --k)if (dep[mn[v]] + dep[u] < 2 * dep[pre[mid][k]])mid = pre[mid][k];
					dp[mn[v]] += sz[mid] - sz[v], dp[u] += sz[now] - sz[mid];
					sum -= sz[now];
				}
			dp[u] += sum;
			mn[u] = u;
		}
	else
		{
			mn[u] = mn[eg[u][0]];
			int sum = sz[u] - 1, tmp = mn[u];
			if (last)
				{
					if (dis(last, u) < dep[tmp] - dep[u])tmp = last;
					else if (dis(last, u) == dep[tmp] - dep[u])tmp = min(last, tmp);
				}
			dp[tmp]++;
			for (auto v : eg[u])
				{
					if (mn[v] != tmp)dfs(v, tmp);
					else dfs(v, last);
					int now = v;
					for (int k = lg; ~k; --k)if (dep[pre[now][k]] > dep[u])now = pre[now][k];
					int mid = v;
					if (mn[v] < tmp)
						{
							for (int k = lg; ~k; --k)if (dep[mn[v]] - dep[pre[mid][k]] <= dis(pre[mid][k], tmp))mid = pre[mid][k];
						}
					else for (int k = lg; ~k; --k)if (dep[mn[v]] - dep[pre[mid][k]] < dis(pre[mid][k], tmp))mid = pre[mid][k];
					dp[mn[v]] += sz[mid] - sz[v], dp[tmp] += sz[now] - sz[mid];
					sum -= sz[now];
				}
			dp[tmp] += sum;
		}
	eg[u].clear(), vis[u] = 0;
}

void mysolve()
{
	cin >> n;
	int x, y;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	pre_dfs(1, 0);
	cin >> m;
	dep[n + 1] = inf;
	while (m--)
		{
			cin >> k;
			for (int i = 1; i <= k; ++i)cin >> a[i].first, a[i].second = i, vis[a[i].first] = 1, dp[a[i].first] = 0;
			sort(a + 1, a + 1 + k, cmp);
			stk[top = 1] = 1;
			if (vis[1])mn[1] = 1;
			else mn[1] = n + 1;
			for (int i = 1; i <= k; ++i)
				{
					int lca = LCA(stk[top], a[i].first);
					while (dep[lca] <= dep[stk[top - 1]])//使得lca是top-1的子代
						{
							if (dep[mn[stk[top]]] < dep[mn[stk[top - 1]]])mn[stk[top - 1]] = mn[stk[top]];
							else if (dep[mn[stk[top]]] == dep[mn[stk[top - 1]]])mn[stk[top - 1]] = min(mn[stk[top - 1]], mn[stk[top]]);
							eg[stk[top - 1]].push_back(stk[top]), top--;
						}
					if (lca != stk[top])//此时要么lca=top,要么lca介于top与top-1之间
						{
							mn[lca] = mn[stk[top]];
							eg[lca].push_back(stk[top--]);
							stk[++top] = lca;
						}
					if (a[i].first != stk[top])stk[++top] = a[i].first, mn[a[i].first] = a[i].first; //防止重复
				}
			while (top > 1)
				{
					if (dep[mn[stk[top]]] < dep[mn[stk[top - 1]]])mn[stk[top - 1]] = mn[stk[top]];
					else if (dep[mn[stk[top]]] == dep[mn[stk[top - 1]]])mn[stk[top - 1]] = min(mn[stk[top - 1]], mn[stk[top]]);
					eg[stk[top - 1]].push_back(stk[top]), top--;
				}
			dfs(1, 0);
			for (int i = 1; i <= k; ++i)ans[a[i].second] = dp[a[i].first];
			for (int i = 1; i <= k; ++i)cout << ans[i] << " \n"[i == k];
		}
}

signed main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
