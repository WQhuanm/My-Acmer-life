#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
ll sum[N];
ll a[N];
void mymin()
{
	int n;
	cin >> n;
	ll ans = 0;
	map<ll, ll>mp;
	int flag = 1;
	ll ma = 0;
	for (ll i = 1; i <= n; ++i)
		{
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i];

			if (!a[i])
				{
					if (flag)
						{
							flag = 0;
							ans += mp[0];
						}
					else ans += ma;
					mp.clear();
					ma = 0;
				}
			ma = max(ma, ++mp[sum[i]]);
		}
	if (flag)ans += mp[0];
	else ans += ma;
	cout << ans << endl;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
		{
			mymin();
		}
	system("pause");
	return 0;
}
