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

int n, a[N], sur[N];
void mysolve()
{
	vector<int>now;
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	sur[n + 1] = 0;
	ll sum = INF;
	for (int i = n; i; --i)
		{
			sur[i] = sur[i + 1] + a[i];
			if (sur[i + 1] >= 0)
				{
					if (sum != INF)now.push_back(sum);
					sum = a[i];
				}
			else
				{
					if (sum != INF)sum += a[i];
					else sum = a[i];
				}
		}
	if (sum != INF)now.push_back(sum);
	reverse(now.begin(), now.end());
	ll ans = 0, k = 1;
	for (auto v : now)
		ans += k * v, k++;
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
