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
const int N = 5e5 + 10;

int n;
int a[N], q[N];

void mysolve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 0; i < n; ++i)cin >> q[i];
	double ans = n;
	for (int i = 0; i < n; ++i)
		{
			if (!q[i])continue;
			double p = q[i] * 1.0 / 1e5;
			ans = min(ans, i + (1 + (1 - p) * (i - a[i])) / p);
		}
	printf("%.12lf\n", ans);
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
