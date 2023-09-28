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
ll s, k, ans = 0;

void update()
{
	ll a = -80, b = 20 * k - 4 * s;
	double mid = -b / (2.0 * a);
	if (mid > -eps)
		{
			for (int x = max(0ll, (ll)mid - 1), p = 1; 4 * x <= k && p <= 3; ++p, ++x)
				ans = max(ans, (s + 20 * x) * (k - 4 * x));
			for (int x = k / 3, p = 1; x >= 0 && p <= 12; --x, ++p)
				ans = max(ans, (s + 20 * x) * (k - 4 * x));
		}
	else
		{
			for (int x = 0; x <= 3 && x * 4 <= k; ++x)
				{
					ans = max(ans, (s + 20 * x) * (k - 4 * x));
				}
		}
}

void mysolve()
{
	cin >> s >> k;
	ans = 0;
	while (k)
		{
			ans = max(ans, s * k);
			if (s % 10 == 0 || s % 10 == 2)break;
			s += s % 10;
			k--;
		}
	if (s % 10 == 2)
		{
			if (k)update();//2
			s += s % 10, k--;
			if (k)update();//4
			s += s % 10, k--;
			if (k)update();//8
			s += s % 10, k--;
			if (k)update();//6
		}

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
