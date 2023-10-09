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
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

int m, k, a1, ak;

void mysolve()
{
	cin >> m >> k >> a1 >> ak;
	if (k * ak >= m)
		{
			int l = 0, r = ak, now = 0;
			while (l <= r)
				{
					int mid = l + ((r - l) >> 1);
					if (k * mid <= m)now = mid, l = mid + 1;
					else r = mid - 1;
				}
			m -= k * now;
			cout << max(m - a1, 0ll) << endl;
		}
	else
		{
			m -= k * ak;
			int l = 0, r = inf, now = 0;
			while (l <= r)
				{
					int mid = l + ((r - l) >> 1);
					if (mid * k + a1 >= m)now = mid, r = mid - 1;
					else l = mid + 1;
				}
			if (now * k > m)now--;
			m -= now * k;
			cout << max(m - a1, 0ll) + now << endl;
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
