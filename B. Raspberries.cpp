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

int n, k;
int cnt[N];
void mysolve()
{
	int x;
	cin >> n >> k;
	int ans = inf;
	int odd = 0, even = 0;
	for (int i = 1; i <= 10; ++i)cnt[i] = 0;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			cnt[x]++;
			odd += x & 1, even += !(x & 1);
			for (int i = 1; i * k <= 50; ++i)if (x <= i * k)
					{
						ans = min(ans, abs(x - i * k));
					}
		}
	if (k == 4)
		{
			if (even > 1)ans = 0;
			if (even && odd)ans = min(ans, 1ll);
			if (odd > 1)ans = min(ans, 2ll);
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
