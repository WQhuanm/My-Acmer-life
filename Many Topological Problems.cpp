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
const int mod = 1e9 + 7, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 1e6 + 10;

ll pre[N];
int n, k;
void mysolve()
{
	cin >> n >> k;
	ll ans = 1;
	for (int i = 2; i <= n; ++i)
		{
			if (i <= k)ans = ans * (i - 1) % mod;
			else ans = ans * k % mod;
		}
	ans = ans * pre[n] % mod;
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	pre[0] = 1;
	for (int i = 1; i <= 1e6; ++i)pre[i] = pre[i - 1] * i % mod;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
