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

int n, k;
int a[N], ans[N];

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i], ans[i] = 0;
	cin >> k;
	for (int i = n - 1; i; --i)a[i] = min(a[i + 1], a[i]);
	for (int i = n; i >= 2; --i)a[i] -= a[i - 1];
	int tmp = k / a[1];
	k %= a[1];
	ans[1] = tmp;

	for (int i = 2; i <= n; ++i)
		{
			if (a[i])
				{
					ans[i] -= tmp;
					tmp = min(tmp, k / a[i]), k -= tmp * a[i];
					ans[i] += tmp;
				}
		}
	for (int i = 1; i <= n; ++i)ans[i] += ans[i - 1];
	for (int i = 1; i <= n; ++i)cout << ans[i] << " \n"[i == n];
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
