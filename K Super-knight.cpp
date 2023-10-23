#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<__int128, __int128> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

int n1, a, b;
void mysolve()
{
	map<pii, int>mp;
	cin >>  a >> b >> n1;
	__int128 n = n1;
	a %= n, b %= n;
	__int128 ans = a * a + b * b;
	__int128 x = a, y = b;
	while (!mp.count({x, y}))
		{
			mp[ {x, y}] = 1;
			if (x == 0 && y == 0)break;
			ans = min((__int128)ans, x * x + y * y);
			__int128 t = min((n - y + b - 1) / b, (n - x + a - 1) / a);
			x = (x + a * t) % n, y = (y + b * t) % n;
		}
	ll res = ans;
	cout << res << endl;
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
