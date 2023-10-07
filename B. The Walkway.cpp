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

pii a[N];
int n, m, d;
int pre[N], bac[N];
void mysolve()
{
	cin >> n >> m >> d;
	map<int, int>mp;
	for (int i = 1; i <= m; ++i)cin >> a[i].first, a[i].second = i;
	sort(a + 1, a + 1 + m);
	a[0] = {1, 0}, a[m + 1] = {n + 1, m + 1}, pre[0] = 1;
	for (int i = 1; i <= m; ++i)
		{
			int len = max(a[i].first - a[i - 1].first - 1, 0ll);
			int cnt = len / d;
			pre[i] = pre[i - 1] + cnt + (a[i].first != a[i - 1].first);
		}
	bac[m + 1] = 0;
	for (int i = m ; i; --i)
		{
			int len = max(a[i + 1].first - a[i].first - 1, 0ll);
			int cnt = len / d;
			bac[i] = bac[i + 1] + cnt + (a[i].first != a[i + 1].first);
		}
	ll ans = INF, p = 1;
	for (int i = 1; i <= m; ++i)
		{
			ll sum = pre[i - 1] + bac[i + 1];
			int len = max(a[i + 1].first - a[i - 1].first - 1, 0ll);
			int cnt = len / d;
			sum += cnt;
			if (sum < ans)ans = sum, p = 1;
			else if (sum == ans)p++;
		}
	cout << ans << " " << p << endl;
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
