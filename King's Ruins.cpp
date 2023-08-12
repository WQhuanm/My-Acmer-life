#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define ll               long long
#define endl             "\n"
const int N = 5e4 + 100;
const int m = 64, M = 16, D = 5;
const ull p = 0xffff;
int n;
int a[N][D],  mx[4][1 << M], w[N], dp[N];
ull b[D][N];
bool check(int j, int i)
{
	for (int d = 0; d < D; ++d)if (a[j][d] > a[i][d])return 0;
	return 1;
}
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j < D; ++j)cin >> a[i][j];
			cin >> w[i], dp[i] = w[i];
		}
	for (int l = 1, t = 1; l <= n; l += m, t++)
		{
			int r = min(n, l + m - 1);
			for (int i = 0; i <= n; ++i)for (int d = 0; d < D; ++d)b[d][i] = 0;
			for (int i = l; i <= r; ++i)
				{
					for (int d = 0; d < D; ++d)b[d][a[i][d]] |= 1ull << (i - l);
					for (int j = l; j < i; ++j)if (check(j, i))dp[i] = max(dp[i], dp[j] + w[i]);
				}
			for (int i = 0; i < M; ++i)
				{
					mx[0][1 << i] = dp[l + i];
					mx[1][1 << i] = dp[l + 16 + i];
					mx[2][1 << i] = dp[l + 32 + i];
					mx[3][1 << i] = dp[l + 48 + i];
				}
			for (int i = 0; i < 1 << M; ++i)
				{
					mx[0][i] = max(mx[0][i - (i & (i - 1))], mx[0][i & (i - 1)]);
					mx[1][i] = max(mx[1][i - (i & (i - 1))], mx[1][i & (i - 1)]);
					mx[2][i] = max(mx[2][i - (i & (i - 1))], mx[2][i & (i - 1)]);
					mx[3][i] = max(mx[3][i - (i & (i - 1))], mx[3][i & (i - 1)]);
				}
			for (int i = 1; i <= n; ++i)for (int d = 0; d < D; ++d)b[d][i] |= b[d][i - 1];
			for (int i = r + 1; i <= n; ++i)
				{
					ll lim = -1ull;
					for (int d = 0; d < D; ++d)lim &= b[d][a[i][d]];
					dp[i] = max(dp[i], mx[0][lim & p] + w[i]);
					dp[i] = max(dp[i], mx[1][(lim >> 16) &p] + w[i]);
					dp[i] = max(dp[i], mx[2][(lim >> 32) &p] + w[i]);
					dp[i] = max(dp[i], mx[3][(lim >> 48) &p] + w[i]);
				}
		}
	for (int i = 1; i <= n; ++i)cout << dp[i] << endl;
}

int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
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
