#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 110;
const int mod = 998244353;

vector<int>edge[N];
bool vis[N];
int match[N];
int ans = 0;
int dfs(int u)
{
	for (auto v : edge[u])
		{
			if (vis[v])continue;
			vis[v] = 1;
			if (!match[v] || dfs(match[v]))
				{
					match[v] = u;
					return 1;
				}
		}
	return 0;
}

void mysolve()
{
	int n, m, k;
//	cin >> n;A
	while (cin >> n && n)
		{
			cin >> m >> k;
			ans = 0;
			int x, y, p;
			for (int i = 0; i <= n; ++i)edge[i].clear();
			for (int i = 0; i <= m; ++i) match[i] = 0;
			for (int i = 1; i <= k; ++i)
				{
					cin >> p >> x >> y;
					if (x && y)edge[x].push_back(y);
				}
			for (int i = 0; i <= n; ++i)
				{
					memset(vis, 0, sizeof(vis));
					ans += dfs(i);
				}
			cout << ans << endl;
		}
}

int32_t main()
{
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
