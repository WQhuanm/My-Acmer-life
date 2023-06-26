#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
typedef pair<int, int> pii;
const int N = 1e5 + 10;

vector<int>edge[N<<1];
pii unit[N << 1], ask[N << 1];
int f[N], ans[N << 1], sz[N];

int find(int x)
{
	while (f[x] != x)x = f[x];
	return x;
}

void dfs(int u)
{
	int fa, fb;
	if (unit[u].first)
		{
			fa = find(unit[u].first), fb = find(unit[u].second);
			if (fa != fb)
				{
					if (sz[fa] > sz[fb])swap(fa, fb);
					sz[fb] += sz[fa];
					f[fa] = fb;
				}
		}
	if (ask[u].first)
		{
			if (find(ask[u].first) == find(ask[u].second))ans[u] = 1;
			else ans[u] = -1;
		}
	for (auto v : edge[u])dfs(v);
	if (unit[u].first&&fa!=fb)sz[fb] -= sz[fa], f[fa] = fa;
}

void mysolve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)f[i] = i, sz[i] = 1;
	int op, a, b;
	for (int i = 1; i <= m; ++i)
		{
			cin >> op;
			if (op == 1)
				{
					cin >> a >> b;
					unit[i] = {a, b};
				}
			else if (op == 2)
				{
					cin >> a;
					edge[a].push_back(i);
					continue;
				}
			else
				{
					cin >> a >> b;
					ask[i] = {a, b};
				}
			edge[i - 1].push_back(i);
		}
	dfs(0);
	for (int i = 1; i <= m; ++i)if (ans[i])cout << (ans[i] == 1 ? 1 : 0) << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
