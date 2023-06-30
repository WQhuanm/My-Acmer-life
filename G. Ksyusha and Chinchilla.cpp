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

vector<pii>edge[N];
int sz[N], nsz[N];

void dfs1(int u, int f)
{
	sz[u] = 1;
	for (auto [v, k] : edge[u])if (v != f)dfs1(v, u), sz[u] += sz[v];
}

//bool fl;
int sum;
vector<int>ans;
void dfs(int u, int f)
{
//	if (!fl)return;
	nsz[u] = sz[u];
	if (sz[u] < 3)return;
	for (auto [v, k] : edge[u])if (v != f)
			{
				dfs(v, u);
				nsz[u] =nsz[u] -sz[v] + nsz[v];
				if (nsz[v] == 3)nsz[u] -= 3, ans.push_back(k), sum += 3;
			}
}

void mysolve()
{
	int n, x, y;
	cin >> n;
	vector<int>in(n + 1);
	for (int i = 1; i <= n; ++i)edge[i].clear();
	for (int i = 1; i < n; ++i)
		{
			cin >> x >> y;
			in[x]++, in[y]++;
			edge[x].push_back({y, i}), edge[y].push_back({x, i});
		}
	int root = 1;
//	for (int i = 1; i <= n; ++i)if (in[i] == 1)
//			{
//				root = i;
//				break;
//			}
	ans.clear();
	sum = 0;
	dfs1(root, 0);
	dfs(root, 0);
//	fl = 1;
	if (sum != n - 3 || n % 3)
		{
			cout << -1 << endl;
		}
	else
		{
			sort(ans.begin(), ans.end());
			cout << ans.size() << endl;
			if (!ans.empty())
				{
					for (auto v : ans)cout << v << " ";
					cout << endl;
				}
			else cout << " " << endl;
		}

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
