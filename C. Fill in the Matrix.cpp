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
const int N = 3e5 + 10;

int n, m;

void mysolve()
{
	cin >> n >> m;
	vector a(n + 1, vector<int>(m + 1));
	if (m == 1)
		{
			cout << 0 << endl;
			for (int i = 1; i <= n; ++i)cout << 0 << endl;
			return;
		}
	if (n >= m)
		{
			cout << m << endl;
			int lim = m - 1;
			for (int i = 0; i < m; ++i)
				{
					for (int j = 1; j <= lim; ++j)
						{
							int k = (i + j + 1) % m;
							if (!k)k = m;
							a[j][k] = i;
						}
				}
			for (int i = lim + 1; i <= n; ++i)for (int j = 1; j <= m; ++j)a[i][j] = a[1][j];
		}
	else
		{
			cout << n + 1 << endl;
			int lim = n;
			for (int i = 0; i <= lim; ++i)
				{
					for (int j = 1; j <= n; ++j)
						{
							int k = (i + j + 1) % (lim + 1);
							if (!k)k = lim + 1;
							a[j][k] = i;
						}
				}
			for (int i = 1; i <= n; ++i)for (int j = lim + 2; j <= m; ++j)a[i][j] = j - 1;
		}
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)cout << a[i][j] << " \n"[j == m];
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
