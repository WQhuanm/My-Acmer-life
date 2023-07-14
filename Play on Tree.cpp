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
const int mod = 1e9 + 7;

vector<int>edge[N];
int dp[N];

ll fastmi(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans = ans * base % mod;
			power >>= 1, base = base * base % mod;
		}
	return ans;
}

void dfs1(int u, int f)
{
	dp[u] = 0;
	for (auto v : edge[u])if (v != f)
			{
				dfs1(v, u);
				dp[u] ^= dp[v] + 1;
			}
//	dp[u]++;
}

int cnt, n;
void dfs(int u, int f)
{
	if (dp[u])cnt++;
	for (auto v : edge[u])if (v != f)
			{
				int du = dp[u], dv = dp[v];
		dp[u]^=dp[v]+1;dp[v]^=dp[u]+1;
//				dp[u]--;
//				dp[u] ^= dp[v], dp[u]++;
//				dp[v]--, dp[v] ^= dp[u], dp[v]++;
				dfs(v, u);
				dp[u] = du, dp[v] = dv;
			}
}

void mysolve()
{
	cnt = 0;
	cin >> n;
	int x, y;
	for (int i = 0; i <= n; ++i)edge[i].clear();
	for (int i = 1; i < n; ++i)
		{
			cin >> x >> y;
			edge[x].push_back(y), edge[y].push_back(x);
		}
	dfs1(1, 0);
	dfs(1, 0);
	cout << cnt*fastmi(n, mod - 2) % mod << endl;
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
