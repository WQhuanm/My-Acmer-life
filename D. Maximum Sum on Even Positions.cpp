#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

int a[N];
void mysolve()
{
	int n;
	cin >> n;
	ll sum = 0, ans = 0;
	for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			if (i % 2 == 0)sum += a[i];
		}
	ans = sum;
	ll tmp = 0, mx = 0;
	for (int i = 0; i < n - 1; i += 2)
		{
			tmp = max(0ll, a[i + 1] - a[i] + tmp);
			mx = max(tmp, mx);
		}
	ans = max(ans, sum + mx);
	tmp = mx = 0;
	for (int i = 1; i < n - 1; i += 2)
		{
			tmp = max(0ll, a[i ] - a[i + 1] + tmp);
			mx = max(tmp, mx);
		}
	ans = max(ans, sum + mx);
	cout << ans << endl;
}

int32_t main()
{
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
