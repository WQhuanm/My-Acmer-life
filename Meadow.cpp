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
const int mod = 1e9 + 7;
const int N = 1e3 + 10;

int a[N][N], b[N][N];
ll sum[N][N], len[N][N], x[N][N], y[N][N], z[N][N];
int n, m;

void pre_xyz()
{
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				x[i][j] += x[i - 1][j];
				y[i][j] += y[i][j - 1];
				z[i][j] += z[i - 1][j - 1];
			}
}

void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				cin >> a[i][j];
				if (a[i][j])len[i][j] = min({len[i - 1][j], len[i][j - 1], len[i - 1][j - 1]}) + 1;
				else len[i][j] = 0;
				sum[i][j] = x[i][j] = y[i][j] = z[i][j] = 0;
			}
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				cin >> b[i][j];
				if (len[i][j])
					{
						int l = len[i][j];
						sum[i + 1][j + 1] += l * (l + 1) / 2;
						z[i - l + 2][j - l + 2] -= 1, z[i + 2][j + 2] += 1;
						x[i - l + 2][j + 1] += 1, x[i + 2][j + 1] -= 1;
						y[i + 1][j - l + 2] += 1, y[i + 1][j + 2] -= 1;
					}
			}
	pre_xyz();
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				if (len[i][j])
					{
						int l = len[i][j];
						z[i - l + 1][j - l + 1] += l;
						x[i - l + 1][j + 1] -= l;
						y[i + 1][j - l + 1] -= l;
					}
			}
	pre_xyz();
	ll ans = 0;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				sum[i][j] = (sum[i][j] + x[i][j] + y[i][j] + z[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]) % mod;
				ans = (ans + sum[i][j] * b[i][j] % mod + mod) % mod;
			}
	cout << ans << endl;
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
