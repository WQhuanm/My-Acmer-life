#include <bits/stdc++.h>
using namespace std;
#define endl             "\n"
const int N = 5e5 + 10, M = 5e6 + 10;
const int lg = 22;

int n, tot;
int a[N], sz[N], mx[N], son[N], dep[N], val[M], ans[N], sum[N], id[N], num[N];
vector<int>edge[N];

void pre_dfs(int u)
{
	id[u] = ++tot, num[tot] = u;
	sz[u] = 1, mx[u] = son[u] = 0;
	for (int v : edge[u])
		{
			dep[v] = dep[u] + 1, sum[v] = sum[u] ^ (1 << a[v]);
			pre_dfs(v);
			sz[u] += sz[v];
			if (sz[v] > mx[u])mx[u] = sz[v], son[u] = v;
		}
}

void dfs(int u, bool fl)
{
	for (int v : edge[u])if (v != son[u])dfs(v, 0);
	if (son[u])dfs(son[u], 1), val[sum[son[u]]] = max(val[sum[son[u]]], dep[son[u]]),ans[u]=max(ans[u],ans[son[u]]);
	for (int v : edge[u])if (v != son[u])
			{
				ans[u] = max(ans[u], ans[v]);
				for (int i = id[v]; i < id[v] + sz[v]; ++i)
					{
						for (int j = 0; j < lg; ++j)if (val[sum[num[i]] ^ (1 << j)])
								{
									ans[u] = max(ans[u], val[sum[num[i]] ^ (1 << j)] + dep[num[i]] - 2 * dep[u]);
								}
						if (val[sum[num[i]]])ans[u] = max(ans[u], val[sum[num[i]]] + dep[num[i]] - 2 * dep[u]);
					}
				for (int i = id[v]; i < id[v] + sz[v]; ++i)val[sum[num[i]]] = max(val[sum[num[i]]], dep[num[i]]);
			}
	for (int i = 0; i < lg; ++i)if (val[(1 << i)^sum[u]])ans[u] = max(ans[u], val[(1 << i)^sum[u]] - dep[u]);
	ans[u] = max(ans[u], val[sum[u]] - dep[u]);
	if (!fl)
		{
			for (int i = id[u]; i < id[u] + sz[u]; ++i)val[sum[num[i]]] = 0;
		}
}

void mysolve()
{
	tot = 0;
	cin >> n;
	int x;
	char y;
	for (int i = 2; i <= n; ++i)cin >> x >> y, a[i] = y - 'a', edge[x].push_back(i);
	sum[1] = 0, dep[1] = 1;
	pre_dfs(1);
	dfs(1, 1);
	for (int i = 1; i <= n; ++i)cout << ans[i] << " \n"[i == n];
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
