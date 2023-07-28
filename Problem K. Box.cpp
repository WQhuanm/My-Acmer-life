#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
#define int              long long
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 1e6 + 10;
int a[N], b[N], dp[N][4];//[0]没有，[1]有自己的,[2]拿了左边的，[3]自己的1给了左边
int n;
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= n; ++i)cin >> b[i];
	for (int i = 1; i <= n; ++i)
		{
			dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]}) ;
			if (b[i])
				{
					dp[i][1] = dp[i][0] + a[i];
					dp[i][3] = max(dp[i - 1][0], dp[i - 1][3]) + a[i - 1];
				}
			if (b[i - 1])dp[i][2] = max(dp[i - 1][0], dp[i - 1][2]) + a[i];
		}
	cout << max({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << endl;
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
