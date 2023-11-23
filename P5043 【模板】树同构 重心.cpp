#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 110;

int n, m;
vector<int>edge[N];
int cnt[N], root[2];

void pre_dfs(int u, int f)
{
	cnt[u] = 1;
	int maxn = 0;
	for (auto v : edge[u])if (v != f)
			{
				pre_dfs(v, u);
				maxn = max(maxn, cnt[v]);
				cnt[u] += cnt[v];
			}
	maxn = max(maxn, n - cnt[u]);
	if (maxn <= n / 2)
		{
			root[root[0] != -1] = u; //记录第一个重心（或者第二个重心）
		}
}

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
			ans[k] = 1, root[0] = root[1] = -1;
			pre_dfs(1, 0);
			dfs(root[0], 0), ans[k] = h[root[0]];
			if (~root[1])dfs(root[1], 0), ans[k] = min(ans[k], h[root[1]]);
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
