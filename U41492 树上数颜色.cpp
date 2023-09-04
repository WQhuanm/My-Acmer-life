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
const int N = 3e5 + 10;

int n, m, tot;
int a[N], col[N], sz[N], mx[N], son[N], num[N],  id[N], res[N];
int ans;
vector<int>edge[N];

void dfs1(int u, int f)
{
	id[u] = ++tot, num[tot] = u;
	sz[u] = 1, son[u] = mx[u] = 0;
	for (auto v : edge[u])if (v != f)
			{
				dfs1(v, u);
				sz[u] += sz[v];
				if (sz[v] > mx[u])mx[u] = sz[v], son[u] = v;
			}
}

void add(int c)
{
	if (!col[c])ans++;
	col[c]++;
}

void del(int c)
{
	col[c]--;
	if (!col[c])ans--;
}

void dfs(int u, int f, bool fl)
{
	for (auto v : edge[u])if (v != f && v != son[u])dfs(v, u, 0);
	if(son[u])dfs(son[u], u, 1);
	for (auto v : edge[u])if (v != f && v != son[u])for (int i = id[v]; i < id[v] + sz[v]; ++i)add(a[num[i]]);
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
	int x, y;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	for (int i = 1; i <= n; ++i)cin >> a[i];
	dfs1(1, 0);
	dfs(1, 0, 1);
	cin >> m;
	while (m--)
		{
			cin >> x;
			cout << res[x] << endl;
		}
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
