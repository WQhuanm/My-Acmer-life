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

int n, m, k;

void mysolve()
{
	cin >> n >> m >> k;
	if ((k - n - m + 2) & 1 || k < n + m - 2)cout << "NO" << endl, void();
	else
		{
			cout << "YES" << endl;
			for (int j = 1; j < m; ++j)cout << 'R' << " \n"[j == m - 1];
			for (int i = 2; i <= n; ++i)for (int j = 1; j < m; ++j)cout << (j & 1 ? "R" : "B") << " \n"[j == m - 1];

			for (int j = 1; j <= m; ++j)cout << "B" << " \n"[j == m];
			bool fl = (m & 1);
			for (int i = 2; i < n; ++i)
				{
					for (int j = 1; j < m; ++j)cout << "R" << " ";
					cout << (fl ? "R" : "B") << endl;
					fl ^= 1;
				}

		}
}

signed main()
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
