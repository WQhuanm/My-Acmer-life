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

ll solve(int k)
{
	int len = n / __gcd(n, k);
	ll sum = 0;
	for (int p = 0; p <= k; ++p)
		{
			int l = max((p * n + k) / k, p * n / (k - 1) + 1), r = min(len, ((p + 1) * n + k) / k - 1);
			if (l <= r)sum += (r - l + 1) * (l + r) / 2 * k - (r - l + 1) * n * p;
		}
	return sum;
}
void mysolve()
{
	cin >> n >> m;
	int k = min(n, m);
	int ans = 1;
	ll sum = 0;
	for (int i = 2; i <= k; ++i)
		{
			ll tmp = solve(i);
//			cout << tmp << endl;
			if (tmp > sum)sum = tmp, ans = i;
		}
	cout << ans << endl;
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
