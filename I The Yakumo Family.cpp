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
const int mod = 998244353;
const int N = 3e5 + 10;

ll sum[5][N], t[2], a[N];
int n;
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 0; i <= n; ++i)sum[0][i] = 1;
	for (int k = 1; k <= 3; ++k)
		{
			for (int j = 0; j < 30; ++j)
				{
					t[0] = sum[k - 1][k - 1], t[1] = 0;
					int q = 0;
					for (int i = k ; i <= n; ++i)
						{
							q ^= (a[i] >> j) & 1;
							sum[k][i] = (sum[k][i] + t[q ^ 1] * (1 << j) % mod) % mod;
							t[q] = (t[q] + sum[k - 1][i]) % mod;
						}
				}
			for (int i = 1; i <= n; ++i)sum[k][i] = (sum[k][i] + sum[k][i - 1]) % mod;
		}
	cout << sum[3][n] << endl;
//	ll ans = 0;
//	for (int i = 3; i <= n; ++i)ans = (ans + sum[3][i]) % mod;
//	cout << ans << endl;
}

int32_t main()
{
	freopen("in.in", "r", stdin);
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
