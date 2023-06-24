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
const int N = 1e6 + 10;
const int mod = 998244353;

vector<pii>edge[N];

int ask[N], fa[N], val[N];

int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}
void mysolve()
{
	int n, m, q;
	cin >> n >> m >> q;
	int x, y, w, mx = -1;
	for (int i = 1; i <= m; ++i)cin >> x >> y >> w, edge[w].push_back({x, y}), mx = max(mx, w);
	for (int i = 1; i <= q; ++i)cin >> ask[i], val[ask[i]] = n - 1;
	for (int i = 1; i <= n; ++i)fa[i] = i;
	for (int i = 1; i <= mx; ++i)
		{
			vector<pii>s;
			int ans = n - 1;
			for (int j = 1; j * i <= mx; ++j)for (auto [u, v] : edge[i * j])
					{
						int fu = find(u), fv = find(v);
						if (fu != fv)
							{
								s.push_back({fu, fv});
								fa[fu] = fv;
								ans--;
							}
					}
			val[i] = ans;
			while (!s.empty())
				{
					fa[s.back().first] = s.back().first;
					s.pop_back();
				}
		}
	for (int i = 1; i <= q; ++i)cout << val[ask[i]] << endl;
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
