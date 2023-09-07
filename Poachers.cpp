#include <bits/stdc++.h>
using namespace std;
#define endl             "\n"
#define inf 0x3f3f3f3f
const int N = 1e6 + 10;
const int MAXN = (1 << 19);
int n, tot;
int sz[N], son[N], mx[N], len[N], dep[N], val[N], id[N], num[N], mxlen[N];
int sum[N], dep_val[N]; //xor出现次数,每一层的xor异或
int t[N];
vector<int>edge[N];

void add(int x, int w)
{
	if (x == 0)
	{
		t[0] += w;
		return;
	}
	for (int i = x; i <= MAXN; i += i & -i)t[i] += w;
}
int ask(int x)
{
	int ans = t[0];
	for (int i = x; i; i -= i & -i)ans += t[i];
	return ans;
}

void add(int x)
{
	if (!sum[x])add(x, 1);
	sum[x]++;
}
void del(int x)
{
	sum[x]--;
	if (!sum[x])add(x, -1);
}

void pre_dfs(int u)
{
	id[u] = ++tot, num[tot] = u;
	sz[u] = 1, mx[u] = son[u] = mxlen[u] = 0, len[u] = inf;
	for (int v : edge[u])
	{
		dep[v] = dep[u] + 1;
		pre_dfs(v);
		sz[u] += sz[v];
		mxlen[u] = max(mxlen[u], mxlen[v]);
		len[u] = min(len[u], len[v]);
		if (sz[v] > mx[u])mx[u] = sz[v], son[u] = v;
	}
	if (len[u] == inf)len[u] = dep[u];
	if (!mxlen[u])mxlen[u] = dep[u];
}

void dfs(int u, bool fl)
{
	for (int v : edge[u])if (v != son[u])dfs(v, 0);
	if (son[u])
	{
		dfs(son[u], 1);
		for (int i = len[u] + 2; i <= len[son[u]] + 1; ++i)if (~dep_val[i])del(dep_val[i]), dep_val[i] = -1;
	}
	for (int v : edge[u])if (v != son[u])
	{
		for (int i = id[v]; i < id[v] + sz[v]; ++i)
		{
			int now = num[i];
			if (dep[now] <= len[u] + 1)
			{
				if (~dep_val[dep[now]])del(dep_val[dep[now]]);
				else dep_val[dep[now]] = 0;
				dep_val[dep[now]] ^= val[now];
				add(dep_val[dep[now]]);
			}
		}
	}
	int l = 0, r = n + 10, ans = 0;
	if (mxlen[u] == len[u])add(0);
	while (l <= r)
	{
		int mid = l + ((r - l) >> 1);
		if (ask(mid) < mid + 1)r = mid - 1;
		else ans = l = mid + 1;
	}
	if (mxlen[u] == len[u])del(0);
	val[u] = ans;
	if (!fl)
	{
		for (int i = dep[u]; i <= len[u] + 1; ++i)if (~dep_val[i])
		{
			del(dep_val[i]), dep_val[i] = -1;
		}
	}
	else dep_val[dep[u]] = val[u], add(val[u]);
}

void mysolve()
{
	vector<int>rt;
	cin >> n;
	tot = 0;
	int x;
	for (int i = 0; i <= n; ++i)edge[i].clear(), t[i] = sum[i] = 0,  dep_val[i] = -1;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		if (x)edge[x].push_back(i);
		else rt.push_back(i);
	}
	int ans = 0;
	for (auto v : rt)
	{
		dep[v] = 0;
		pre_dfs(v);
		dfs(v, 0);
		ans ^= val[v];
	}
	if (ans)cout << "YES" << endl;
	else cout << "NO" << endl;
}

int32_t main()
{
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
