#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 110;

int n, m;
vector<int>edge[N];

typedef unsigned long long ull;
const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();
ull h[N], ans[N];

ull shift(ull x)
{
	x ^= mask;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	x ^= mask;
	return x;
}

void dfs(int u, int f)
{
	h[u] = 1;
	for (auto v : edge[u])if (v != f)
			{
				dfs(v, u);
				h[u] += shift(h[v]);
			}
}

void dfs2(int u, int f, int id)
{
	ans[id] += h[u];
	for (auto v : edge[u])if (v != f)
			{
				h[v] += shift(h[u] - shift(h[v]));
				dfs2(v, u,id);
			}
}

void mysolve()
{
	cin >> m;
	for (int k = 1; k <= m; ++k)
		{
			cin >> n;
			for (int i = 1; i <= n; ++i)edge[i].clear();
			int x;
			for (int i = 1; i <= n; ++i)
				{
					cin >> x;
					if (x)edge[x].push_back(i), edge[i].push_back(x);
				}
			ans[k] = 1;
			dfs(1, 0), dfs2(1, 0, k);
			for (int i = 1; i <= k; ++i)if (ans[i] == ans[k])
					{
						cout << i << endl;
						break;
					}
		}
}

signed main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	return 0;
}
