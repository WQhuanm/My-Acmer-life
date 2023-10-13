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
const int N = 510;

char a[N][N];
int n, m;
int r[N][2], c[N][2], cntr[N], cntc[N];

void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cntr[i] = 0, r[i][0] = r[i][1] = 0;
	for (int i = 1; i <= m; ++i)cntc[i] = 0, c[i][0] = c[i][1] = 0;

	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				cin >> a[i][j];
			}
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				if (a[i][j] == 'U')
					{
						if (r[i][0] <= r[i][1])
							{
								r[i][0]++, a[i][j] = 'W';
								r[i + 1][1]++, a[i + 1][j] = 'B';
							}
						else
							{
								r[i][1]++, a[i][j] = 'B';
								r[i + 1][0]++, a[i + 1][j] = 'W';
							}
					}

			}
	for (int j = 1; j <= m; ++j)for (int i = 1; i <= n; ++i)
			{
				if (a[i][j] == 'L')
					{
						if (c[j][0] < c[j][1])
							{
								c[j][0]++, a[i][j] = 'W';
								c[j + 1][1]++, a[i][j + 1] = 'B';
							}
						else
							{
								c[j][1]++, a[i][j] = 'B';
								c[j + 1][0]++, a[i][j + 1] = 'W';
							}
					}
			}

	for (int i = 1; i <= n; ++i)if (r[i][0] != r[i][1])return cout << -1 << endl, void();
	for (int i = 1; i <= m; ++i)if (c[i][0] != c[i][1])return cout << -1 << endl, void();

	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				cout << a[i][j];
				if (j == m)cout << endl;
			}

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
