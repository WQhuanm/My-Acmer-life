#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 2e5 + 10;

int n, m, rt, tot;
int sz[N], mx[N], son[N], len[N], ans[N], id[N], num[N], dep[N];
string a[N];
set<string>cnt[N];
vector<int>edge[N];
vector<pii>que[N];

void pre_dfs(int u)
{
	id[u] = ++tot, num[tot] = u;
	sz[u] = 1, son[u] = mx[u] = len[u] = 0;
	for (int v : edge[u])
		{
			dep[v] = dep[u] + 1;
			pre_dfs(v);
			sz[u] += sz[v];
			if (sz[v] > mx[u])mx[u] = sz[v], son[u] = v;
			len[u] = max(len[u], len[v]);
		}
	len[u]++;
}

void dfs(int u, bool fl)
{
	for (int v : edge[u])if (v != son[u])dfs(v, 0);
	if (son[u])dfs(son[u], 1);
	for (int v : edge[u])if (v != son[u])
			for (int i = id[v]; i < id[v] + sz[v]; ++i)
				cnt[dep[num[i]]].insert(a[num[i]]);
	for (auto [k, id] : que[u])
		ans[id] = cnt[dep[u] + k].size();
	if (fl)cnt[dep[u]].insert(a[u]);
	else for (int i = dep[u]; i < dep[u] + len[u]; ++i)cnt[i].clear();
}

void mysolve()
{
	cin >> n ;
	int x, y;
	vector<int>rt;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i] >> x;
			if (x) edge[x].push_back(i);
			else rt.push_back(i);
		}
	cin >> m;
	for (int i = 1; i <= m; ++i)cin >> x >> y, que[x].push_back({y, i});
	for (int root : rt)
		{
			pre_dfs(root);
			dfs(root, 1);
			for (int i = 0; i < len[root]; ++i)cnt[i].clear();
		}

	for (int i = 1; i <= m; ++i)cout << ans[i] << endl;
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
