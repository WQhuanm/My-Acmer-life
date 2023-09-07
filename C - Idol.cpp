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

inline void write(__int128 x)
{
	if (x < 0)x = -x, putchar('-');
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

void mysolve()
{
	ll n;
	cin >> n;
	__int128 ans = 0;
	if (n & 1)
		{
			for (__int128 p = 5; p <= n; p *= 5)ans += ((n / p) + 1) / 2;
			n--;
		}
	for (__int128 p = 5, i = 1; p <= n; p *= 5, ++i)
		{
			__int128 cnt = n / p;
			__int128 odd = p / 2, even = odd + 1;
			cnt--;
			if (cnt)ans += (cnt + 1) / 2 * ((cnt & 1 ? cnt : cnt - 1) + 1) / 2 * odd;
			if (cnt > 1)ans += cnt / 2 * (2 + (cnt & 1 ? cnt - 1 : cnt)) / 2 * even;
			cnt++;
			if (cnt & 1)
				{
					int len = (n % p + 1) / 2;
					ans += cnt * len;
				}
			else
				{
					int len = (n % p + 2) / 2;
					ans += cnt * len;
				}
		}
	write(ans);
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
