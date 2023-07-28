	#include <bits/stdc++.h>
	using namespace std;
	typedef pair<int, int> pii;
	#define ll               long long
	#define endl             "\n"
	#define INF 0x3f3f3f3f3f3f3f3f
	#define inf 0x3f3f3f3f
	#define eps 1e-9
	#define int              long long
	//double 型memset最大127，最小128
	//---------------------------------------------------------------------------------------------------------------------//
	//---------------------------------------------------------------------------------------------------------------------//
	const int mod = 998244353;
	const int N = 3e5 + 10;
	
	int exgcd(int a, int b, int &x, int &y)//&直接修改值
	{
		if (!b)
			{
				x = 1, y = 0;
				return a;
			}
		int gcd = exgcd(b, a % b, y, x); //x继承了深层的y,y就继承深层的x，y再减去(a/b)*y2即-(a/b)*x即可
		y -= (a / b) * x;
		return gcd;
	}
	
	void mysolve()
	{
		int a, b, c, x, y;
		cin >> a >> b >> c;
		if (a > b)swap(a, b);
		int g = exgcd(a, b, x, y);
		if (c % g)
			{
				cout << -1 << endl;
				return;
			}
		int k = c / g;
		x *= k, y *= k;
		int p = a / g, q = b / g;
		ll ans = INF;
		int t = x / q;
		x -= t * q, y += t * p;
		if (x >= 0 && y >= 0)ans = min(ans, 2 * (x + y));
		else ans = min(ans, 2 * abs(x - y) - 1);
		if (x >= 0)x -= q, y += p;
		else x += q, y -= p;
		if (x >= 0 && y >= 0)ans = min(ans, 2 * (x + y));
		else ans = min(ans, 2 * abs(x - y) - 1);
		cout << ans << endl;
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
