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
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 5010;

int n, m;
vector<int>edge[N];
double dp[N][N];
double ans[N];

bool cmp(int x, int y)
{
	return ans[x] - ans[y] > eps;
}
void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)edge[i].clear();
	int x, y;
	while (m--)cin >> x >> y, edge[x].push_back(y);
	ans[n] = 1;
	for (int i = n - 1; i; --i)
		{
			sort(edge[i].begin(), edge[i].end(), cmp);
			ans[i] = 0;
			int cnt = edge[i].size();
			for (int j = 0; j < cnt; ++j)ans[i] += dp[cnt][j + 1] * ans[edge[i][j]];
		}
	printf("%.12lf\n", ans[1]);
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int n = 5000;
	for (int i = 1; i <= n; ++i)
		{
			dp[i][1] = 1.0 / i;
			for (int j = 2; j < i; ++j)
				{
					dp[i][j] = (i - j) * 1.0 / i * dp[i - 2][j - 1] + (j - 2) * 1.0 / i * dp[i - 2][j - 2];
				}
			if (i > 1 && i & 1)dp[i][i] = (i - 2) * 1.0 / i * dp[i - 2][i - 2];
		}
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
