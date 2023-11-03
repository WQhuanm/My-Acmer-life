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
int a[N], b[N], c[N];

bool check(int k)
{
	for (int i = 1; i <= n - k; ++i)if (a[i] >= b[i + k])return 0;
	return 1;
}

void mysolve()
{
	cin >> n >> m;
	for (int i = 2; i <= n; ++i)cin >> c[i];
	for (int i = 1; i <= n; ++i)cin >> b[i];

	a[1] = 1;
	for (int i = 2; i <= n; ++i)a[i] = c[i];
	sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
	int l = 0, r = n, ans = n;
	while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (check(mid))ans = mid, r = mid - 1;
			else l = mid + 1;
		}
	l = 1, r = m;int  res = 1;
	while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			a[1] = mid;
			for (int i = 2; i <= n; ++i)a[i] = c[i];
			sort(a + 1, a + 1 + n);
			if (check(ans))res = mid, l = mid + 1;
			else r = mid - 1;
		}
	ll sum = ans * res + (ans + 1) * (m - res);
	cout << sum << endl;
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
