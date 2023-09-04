#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 2e5 + 10;
int n;
int sz[N], mx[N], son[N], a[N], q[N], val[N];
bool vis[N];
vector<int>edge[N];

void pre_dfs(int u, int f)
{
	sz[u] = 1, mx[u] = son[u] = 0;
	for (int v : edge[u])if (v != f)
			{
				pre_dfs(v, u);
				sz[u] += sz[v];
				if (sz[v] > mx[u])mx[u] = sz[v], son[u] = v;
			}
}

void get_xor(int u, int f)
{
	q[++q[0]] = val[u];
	for (auto v : edge[u])if (v != f && !vis[v])val[v] = val[u] ^ a[v], get_xor(v, u);
}
int ans;
map<int, int>mp;
int now;
void dfs(int u, int f, int fl)
{
	for (int v : edge[u])if (v != f && v != son[u] && !vis[v])dfs(v, u, 0);
	if (son[u])dfs(son[u], u, 1);
	for (int v : edge[u])if (!vis[v] && v != f && v != son[u])
			{
				q[0] = 0;
				val[v] = a[v], get_xor(v, u);
				for (int i = q[0]; i; --i)if (mp.count(now ^ q[i]^a[u]))
						{
							mp.clear(), ans++, vis[u] = 1;
							return;
						}
				for (int i = q[0]; i; --i)mp[q[i]^now] = 1;
			}
	if (mp.count(a[u]^now))
		{
			mp.clear(), ans++, vis[u] = 1;
			return;
		}
	mp[now] = 1;
	if (!fl)mp.clear();
	else now ^= a[u];
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	int x, y;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	pre_dfs(1, 0);
	dfs(1, 0, 1);
	cout << ans << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	return 0;
}
