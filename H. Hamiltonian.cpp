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

void mysolve()
{
	int k, n;
	cin >> k;
	if (k == 1)
		{
			cout << 2 << " " << 1 << endl;
			cout << 2 << " " << 1 << endl;
			return;
		}
	else if (k == 2)
		{
			cout << 4 << " " << 4 << endl;
			for (int i = 1; i < 3; ++i)cout << i << " " << i + 1 << endl;
			cout << 1 << " " << 4 << endl;
			cout << 1 << " " << 3 << endl;
			return;
		}

	if (k <= 20)
		{
			n = k ;
			cout << n << " " << n << endl;
			for (int i = 1; i < n; ++i)cout << i << " " << i + 1 << endl;
			cout << n << " " << 1 << endl;
		}
	else
		{
			for (int n = 3; n <= 20; ++n)for (int m = 2; m + n <= 20; ++m)if (n * (n + 3) / 2 + m - 4 == k)
						{
							cout << n + m << " " << n*(n - 1) / 2 + m + 1 << endl;
							for (int i = 1; i <= n; ++i)for (int j = i + 1; j <= n; ++j)cout << i << " " << j << endl;
							for (int i = n; i < n+ m; ++i)cout << i << " " << i + 1 << endl;
							cout << n + m << " " << 1 << endl;
							return;
						}
		}
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
