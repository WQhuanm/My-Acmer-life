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
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 1e6+10;

int sz[N];
int n;
vector<int>edge[N];
int  dfs(int u)
{
	int ans = 0;
	bitset<N>dp;
	dp[0] = 1;
	for (auto v : edge[u])
		{
			ans += dfs(v);
			sz[u] += sz[v];
			dp |= dp << sz[v];
		}
	int tmp = 0;
	for (int i = 1; i < sz[u]; ++i)if (dp[i])tmp = max(tmp, (sz[u] - i) * i);
	sz[u]++;
	return ans + tmp;
}

void mysolve()
{
	cin >> n;
	int x;
	for (int i = 2; i <= n; ++i)cin >> x, edge[x].push_back(i);
	cout << dfs(1) << endl;
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
