#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

pii a[N];
void mysolve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].first >> a[i].second;
		}
	sort(a + 1, a + 1 + n);
	vector<pii>v;
	for (int i = 1; i <= n; ++i)for (int j = i + 1; j <= n; ++j)
			{
				if (a[j].first <= a[i].second)v.push_back({min(a[i].first, a[j].first), max(a[i].second, a[j].second)});
			}
	sort(v.begin(), v.end());
	vector<pii>ans;
	for (auto [x, y] : v)
		{
			if (ans.empty())ans.push_back({x, y});
			else
				{
					if (x > ans.back().second)ans.push_back({x, y});
					else if (y < ans.back().second)ans.pop_back(), ans.push_back({x, y});
				}
		}
	int res = n - 2 * (int)ans.size();
//	if (res & 1)res--;
	cout << res << endl;
}

int32_t main()
{
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
