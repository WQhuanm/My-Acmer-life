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
const int N = 3e5 + 10;
const int mod = 998244353;
vector<int>edge[N];

void mysolve()
{
	int n, m, x, y, w;
	cin >> n >> m;
	vector<int>a(n + 1, inf);
	for (int i = 1; i <= m; ++i)-
		{
			cin >> x >> y >> w;
			edge[x].push_back(y), edge[y].push_back(x);
			a[x] = min(a[x], w), a[y] = min(a[y], w);
		}
	for (int i = 1; i <= n; ++i)if (a[i] == inf)
			{
				cout << "inf" << endl;
				return;
			}
	vector<bool>vis(n + 1);

	vector<pair<string, int>>v;
	ll ans = 0;
	for (int i = 1; i <= n; ++i)if (!vis[i])
			{
				vis[i] = 1;
				for (auto v : edge[i])vis[v] = 1;
				string s;
				for (int j = 1; j <= n; ++j)s.push_back((j == i ? '1' : '0'));
				v.push_back({s, a[i]});
				ans += a[i];
			}
	cout << (int)v.size() << " " << ans << endl;
	for (auto [s, k] : v)
		{
			cout << s << " " << k << endl;
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
