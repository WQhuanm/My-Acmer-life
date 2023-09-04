#include <bits/stdc++.h>
using namespace std;
//#define int              long long
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
const int N = 3e5 + 10;

int n, tot;
int a[N], sz[N], mx[N], col[N], son[N], id[N], num[N];
ll res[N];
vector<int>edge[N];
ll ans, mxc;

void pre_dfs(int u, int f)
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

void add(int c)
{
	col[c]++;
	if (col[c] > mxc)ans = c,mxc=col[c];
	else if (col[c] == mxc)ans += c;
}

void del(int c)
{
	col[c]--;
}

void dfs(int u, int f, bool fl)
{
	for (int v : edge[u])if (v != f && v != son[u])dfs(v, u, 0);
	ans = mxc = 0;
	if (son[u])dfs(son[u], u, 1);
	for (int v : edge[u])if (v != f && v != son[u])for (int i = id[v]; i < id[v] + sz[v]; ++i)add(a[num[i]]);
	add(a[u]);
	res[u] = ans;
	if (!fl)
		{
			for (int i = id[u]; i < id[u] + sz[u]; ++i)del(a[num[i]]);
		}
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	int x, y;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	pre_dfs(1, 0);
	dfs(1, 0, 1);
	for (int i = 1; i <= n; ++i)cout << res[i] << " ";
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
