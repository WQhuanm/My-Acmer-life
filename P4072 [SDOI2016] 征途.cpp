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
const int N = 3e3 + 10;

struct node
{
	ll x, y;
} q[N << 1];
ll c[N], dp[N][N], sum[N];
int n, m;
void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> c[i], sum[i] = sum[i - 1] + c[i];
	ll ans = -sum[n] * sum[n];
	for (int i = 1; i <= m; ++i)
		{
			int head = 1, tail = 1;
			q[head] = {sum[i - 1], dp[i - 1][i - 1] + sum[i - 1]*sum[i - 1]};
			for (int j = i; j <= n - (m - i); ++j)
				{
					ll k = 2 * sum[j];
					while (head + 1 <= tail && (1.0 * q[head].y - q[head + 1].y) / (1.0 * q[head].x - q[head + 1].x) - k < -eps)head++;
					ll b = q[head].y - k * q[head].x;
					dp[i][j] = b + sum[j] * sum[j];
					if (i -1&& j < n - (m - i))
						{
							ll y = dp[i - 1][j] + sum[j] * sum[j], x = sum[j];
							while (head + 1 <= tail && (1.0 * q[tail - 1].y - y) / (1.0 * q[tail - 1].x - x) - (1.0 * q[tail - 1].y - q[tail].y) / (1.0 * q[tail - 1].x - q[tail].x) < -eps)tail--;
							q[++tail] = {x, y};
						}
				}
		}
	ans += m * dp[m][n];
	cout << ans << endl;
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
