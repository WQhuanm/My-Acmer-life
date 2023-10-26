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

int n, m, k;
int a[N], b[N];
void mysolve()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= m; ++i)cin >> b[i];
	sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + m);
	ll ans = 0;
	if (k == 1)
		{
			if (a[1] < b[m])swap(a[1], b[m]);
		}
	else if (k == 2)
		{
			if (a[1] < b[m])swap(a[1], b[m]);
			sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + m);
			if (b[1] < a[n])swap(b[1], a[n]);
		}
	else
		{
			if (k & 1)
				{
					if (a[1] < b[m])swap(a[1], b[m]);
					sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + m);
					if (b[1] < a[n])swap(b[1], a[n]);
					sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + m);
					if (a[1] < b[m])swap(a[1], b[m]);
				}
			else
				{
					if (a[1] < b[m])swap(a[1], b[m]);
					sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + m);
					if (b[1] < a[n])swap(b[1], a[n]);
					sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + m);
					if (a[1] < b[m])swap(a[1], b[m]);
					sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + m);
					if (b[1] < a[n])swap(b[1], a[n]);
				}
		}

	for (int i = 1; i <= n; ++i)ans += a[i];
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
