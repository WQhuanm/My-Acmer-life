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
const int N = 3e4 + 10;

int n;
vector<int>a[N];
void mysolve()
{
	cin >> n;
	ll ans = 0;
	int k, mn = INF, x,  mn2 = INF;
	for (int i = 1; i <= n; ++i)
		{
			a[i].clear();
			cin >> k;
			while (k--)
				{
					cin >> x;
					a[i].push_back(x), mn = min(x, mn);
				}
			sort(a[i].begin(), a[i].end());
			ans += a[i][1];
			mn2 = min(mn2, a[i][1]);
		}
	ans += mn - mn2;
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