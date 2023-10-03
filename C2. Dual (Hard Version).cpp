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

int n;
int a[N];

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	vector<pii>ans;
	bool fl = 1;
	for (int i = 1; i < n; ++i)if (a[i] > a[i + 1])
			{
				fl = 0;
				break;
			}
	if (fl)
		{
			cout << 0 << endl;
			return;
		}
	int zh = 0, fu = 0;
	for (int i = 1; i <= n; ++i)
		{
			if (a[i] > 0)zh++;
			else if (a[i] < 0)fu++;
		}
	if (max(zh, fu) <= 12)
		{
			int mx = max_element(a + 1, a + 1 + n) - a, mn = min_element(a + 1, a + 1 + n) - a;
			if (abs(a[mx]) > abs(a[mn]) || a[mn] >= 0)
				{
					for (int i = 1; i <= n; ++i)if (a[i] < 0)a[i] += a[mx], ans.push_back({i, mx});
					for (int i = 1; i < n; ++i)if (a[i] > a[i + 1])a[i + 1] += a[i], ans.push_back({i + 1, i});
				}
			else
				{
					for (int i = 1; i <= n; ++i)if (a[i] > 0)a[i] += a[mn], ans.push_back({i, mn});
					for (int i = n; i > 1; --i)if (a[i - 1] > a[i])a[i - 1] += a[i], ans.push_back({i - 1, i});
				}
		}
	else
		{
			if (zh >= fu)
				{
					int mx = max_element(a + 1, a + 1 + n) - a;
					while (a[mx] < 20)ans.push_back({mx, mx}), a[mx] += a[mx];
					for (int i = 1; i <= n; ++i)if (a[i] < 0)a[i] += a[mx], ans.push_back({i, mx});
					for (int i = 1; i < n; ++i)if (a[i] > a[i + 1])a[i + 1] += a[i], ans.push_back({i + 1, i});
				}
			else
				{
					int mn = min_element(a + 1, a + 1 + n) - a;
					while (a[mn] > -20)ans.push_back({mn, mn}), a[mn] += a[mn];
					for (int i = 1; i <= n; ++i)if (a[i] > 0)a[i] += a[mn], ans.push_back({i, mn});
					for (int i = n; i > 1; --i)if (a[i - 1] > a[i])a[i - 1] += a[i], ans.push_back({i - 1, i});
				}
		}
	cout << (int)ans.size() << endl;
	for (auto [v, k] : ans)cout << v << " " << k << endl;
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
