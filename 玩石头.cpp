#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
const int M = 3600;
ll a[M + 200];

int main()
{
	vector<pll>v;
	memset(a, 0x3f, sizeof(a));

	a[0] = 0;
	int n;
	cin >> n;
	ll x, y;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x >> y;
			v.push_back({x, y});
		}
	sort(v.begin(), v.end());
	ll maxn = -INF;
	for (auto [x, y] : v)
		{
			for (int i = M; i >= 0; --i)
				{
					if (a[i] < x)
						{
							a[i + y] = min(a[i + y], a[i] + x);

							maxn = max(maxn, i + y);
						}
				}
		}
	cout << maxn << endl;
	return 0;
}
